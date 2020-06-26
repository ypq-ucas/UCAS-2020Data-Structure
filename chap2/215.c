#include<stdio.h>
#include<stdlib.h>
struct anode{
    struct anode *next;
    int data;
};
int getline(int s[]);
int main(){
    int line[10] = {0};
    int i = 0;
    int c;
    struct anode* head = malloc(sizeof(struct anode));
    struct anode* p;
    struct anode* b;
    getline(line);
    int m,n;
    m = line[0];
    n = line[1];
    i= 0;
    getline(line);
    p = malloc(sizeof(struct anode));
    b = p;
    for(i = 0;i<m;i++){
        p->data = line[i];
        p->next = malloc(sizeof(struct anode));
        p = p->next;
    }
    i = 0;
    p = head;
    getline(line);
    for(i = 0;i<n;i++){
        p->data = line[i];
        p->next = malloc(sizeof(struct anode));
        if(i<n-1)
            p = p->next;
    }
    p->next = b;
    p = head;
    for(i = 0;i<m+n;i++){
        printf("%d",p->data);
        p = p->next;
        if(i<m+n-1)
            printf(" ");
    }
}
int getline(int s[]){
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