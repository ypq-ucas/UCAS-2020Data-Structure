#include<stdio.h>
#include<stdlib.h>
struct chain{
    int data;
    struct chain*pre;
    struct chain*next;
};
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n';++i){
        if(c<='9'&&c>='0'||c=='-'){           
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
        else if(c==';'){
            s[j++] = c;
            ++i;
            number = 0;
            state = 1;
        }
        else{
            number = 0;
            state = 1;
        }
    }
    //s[j] = '\0';
    return j;
}
buildchain(struct chain*head,int line[]){
    head->pre = NULL;
    for(int i = 0;line[i]!=-1;i++){
        if(line[i]==-1)
            line[i] = -1;
        head->data = line[i];
        head->next = malloc(sizeof(struct chain));
        head->next->pre = head;
        head = head->next;
        head->data = -1;
        head->next = NULL;
    }
    head->pre->next = NULL;
}
struct chain *InsertSort(struct chain *head) {  
    return head;  
}  
int main(){
    int line[100];
    for(int i = 0;i<100;i++){
        line[i] = -1;
    }
    struct chain*head = malloc(sizeof(struct chain));
    int j = numbersgetline(line);
    buildchain(head,line);
    for(int i = 0;i<j;i++){
        for(int k = j;k>i;k--){
            if(line[k]<line[k-1]){
                int temp = line[k];
                line[k] = line[k-1];
                line[k-1] = temp;
            }
        }
    }
    struct chain*temp = InsertSort(head);
    for(int i = 1;i<j+1;i++){
        printf("%d",line[i]);
        if(i<j){
            printf(",");
        }
    }
}