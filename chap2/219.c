#include<stdio.h>
#include<stdlib.h>
struct anode{
    struct anode *next;
    int data;
};
int tenpower(int n);
int numbersgetline(int s[]);
//将一行（以换行符为界）的数字写入数组中，返回数字个数
void createchain(int s[],int l,struct anode* head);
//生成一个链表，链表元素依次为s中元素，长度为l
int main(){
    int line[100];
    int mind,maxi;
    int j = numbersgetline(line);
    mind = line[j-2];
    maxi = line[j-1];
    struct anode *head = malloc(sizeof(struct anode));
    struct anode *p;
    p = head;
    createchain(line,j-2,head);
    for(p = head;p->next!=NULL;){
        if((p->next->data>mind)&&(p->next->data<maxi)&&(p->next->next!=NULL)){
            struct anode *temp;
            temp = p->next;
            p->next = p->next->next;
            free(temp);
        }
        else if((p->next->next==NULL)&&p->next->data<maxi)
            p->next = NULL;
        else
        {
            p = p->next;
        }
        
    }
    for(p = head->next;p!=NULL;p = p->next){
        printf("%d",p->data);
        if(p->next!=NULL)
            printf(" ");
    }
}

void createchain(int s[],int l,struct anode* head){
    struct anode *p;
    head->data = l;
    head->next = malloc(sizeof(struct anode));
    p = head->next ;
    for(int i = 0;i<l;i++){
        p->data = s[i];
        p->next = malloc(sizeof(struct anode));
        if(i<l-1)
            p = p->next;
    }
    p->next = NULL;
}

int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        if(c!=' '){
            if(c=='-')
                state = -1;
            else {
                if(number==0){
                    number += 1;
                    s[j++] = (c-'0')*state;  
                }
                else if(number!=0&&(c>='0'&&c<='9')){
                    number += 1;
                    int temp =s[j-1]*10+(c-'0')*state;
                    s[j-1] = temp;
                } 
            }   
        }
        else{
            number = 0;
            state = 1;
        } 
    }
    if(c=='\n'){
        s[j] = c;
        ++i;
    }
    s[j] = '\0';
    return j;
}
