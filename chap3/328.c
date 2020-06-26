#include<stdio.h>
#include<stdlib.h>
struct anode{
    int data;
    struct anode* next;
};
void build(int *line,int n,struct anode*head);
int numbersgetline(int s[]);
void build(int *line,int n,struct anode*head){
    head->next = malloc(sizeof(struct anode));
    struct anode*p = head->next;
    for(int i = 0;i<n;i++){
        p->data = *(line+i);
        p->next = malloc(sizeof(struct anode));
        p = p->next;
    }
    p->next = head->next;
}
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        if(c!=','){
            if(c=='-')
                state = -1;
            else {
                if(number==0){
                    number = 1;
                    s[j++] = (c-'0')*state;  
                }
                else if(number==1&&(c>='0'&&c<='9')){
                    number = 0;
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
int main(){
    int line[100];
    struct anode* head = malloc(sizeof(struct anode));
    numbersgetline(line);
    int n = line[0];
    numbersgetline(line);
    build(line,n,head);
    for(int i = 0;i<n;i++){
        head = head->next;
        printf("%d",head->data);
        if(i<n-1)
            printf(",");
    }
}