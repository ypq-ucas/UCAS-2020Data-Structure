#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* succ;
    struct node* next;
    char data;
};
void buildline(struct node* head,char line[]);
int getline(char s[]);
void calnext(char t[],int next[]);
void buildline(struct node* head,char line[]){
    int i = 0;
    while(line[i]!=0){
        head->succ = NULL;
        head->data = line[i];
        head->next = malloc(sizeof(struct node));
        struct node*temp = head;
        head = head->next;
        head->succ = temp;
    }
    head->next = NULL;
}
void turnline(struct node*head,int next[]){
    struct node* p = head;
    int i = 0;
    while(p!=NULL){
        if(next[i++]==0){
            p->succ = head;
            p = p->next;
        }
    }
}
void calnext(char t[],int next[]){
    int i = 1;
    int j = 0;
    next[1] = 0;
    while(i<t[0]){
        if(j==0||t[i]==t[j]){
            i++;
            j++;
            if(t[i]!=t[j])
                next[i]=j;
            else
            {
                next[i] = next[j];
            }
            
        }
        else 
            j = next[j];
    }
}
int getline(char s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}
void cmp(char sline[],char tline[],int data[]){
    for(int i = 0;sline[i]!=0;i++){
        int temp = i;
        int j =0;
        while(sline[temp]==tline[j]&&tline[j]!=0){
            temp++;
            j++;
        }
        if(tline[j]=='\0'){
            *(data++) = i+1;
        }
    }
    *data = -1;
}
int main(){
    char sline[100];
    char tline[100];
    int data[10] = {0};
    struct node* thead = malloc(sizeof(struct node));
    struct node* shead = malloc(sizeof(struct node));
    int next[100];
    getline(sline);
    //buildline(shead,sline);
    int lenth = getline(tline);
    cmp(sline,tline,data);
    //buildline(thead,tline);
    for(int i = 99;i>0;i--){
        tline[i] = tline[i-1];
    }
    tline[0] = lenth;
    calnext(tline,next);
    //turnline(thead,next);
    for(int i = 0;data[i]!=-1;i++){
        printf("%d",data[i]);
        if(data[i+1]!=-1)
            printf(" ");
    }
    printf("\n");
    for(int i = 1;i<=lenth;i++){
        printf("%d",next[i]);
        if(i<lenth)
            printf(" ");
    }
}