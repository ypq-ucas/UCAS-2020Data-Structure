#include<stdio.h>
#include<stdlib.h>
struct anode{
    struct anode* next;
    int data;
};
int getline(int s[]);
void createchain(int s[],int l,struct anode* head);
void reverse(struct anode *head);
//输入头节点，将后面的链表就地倒置
int main(){
    int line[100];
    int s[100];
    getline(line);
    int j = 0;
    for(int i = 0;line[i]!='\0';i++){
        if(line[i]!=',')
            s[j++] = line[i];
    }
    s[j] = '\0';
    struct anode *head = malloc(sizeof(struct anode));
    createchain(s,j,head);
    reverse(head);
}
void reverse(struct anode *head){
    struct anode*p;
    struct anode*temp1;
    struct anode*temp2;
    struct anode*temp;
    p = head->next;
    temp1 = p;
    do{
        p = p->next;
    }while(p->next!=NULL);
    head->next = p;
    temp2 = temp1->next;
    temp = temp2->next;
    temp2->next = temp1;
    temp1->next = NULL;
    for(int i = 1;i<head->data-1;i++){
        temp1 = temp2;
        temp2 = temp;
        temp = temp->next;
        temp2->next = temp1;
    }
    for(p = head->next;p!=NULL;p = p->next){
        printf("%c",p->data);
        if(p->next!=NULL)
            printf(",");
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
int getline(int s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}