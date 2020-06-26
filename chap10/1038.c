#include<stdlib.h>
#include<stdio.h>
struct chain{
    int tag;
    int data;
    struct chain* pre;
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
    for(int l = 0;l<j;l++){
        for(int t = 0;t<j-1;t++){
            if(s[t]>s[t+1]){
                int temp = s[t];
                s[t] = s[t+1];
                s[t+1] = temp;
            }
        }
    }
    //s[j] = '\0';
    return j;
}
void buildchain(struct chain*head,int line[]){
    head->pre = NULL;
    for(int i = 0;line[i]!=-1;i++){
        head->data = line[i];
        head->next = malloc(sizeof(struct chain));
        head->next->pre = head;
        head = head->next;
        head->data = -1;
        head->next = NULL;
    }
    head->pre->next = NULL;
}
void mergesort(struct chain*head){
    struct chain*p = head;
    p->tag = 1;
    p = p->next;
    for(p;p->next!=NULL;p = p->next){
        if(p->data<p->next->data){
            p->tag = 0;
        }else{
            p->tag = 0;
            p->next->tag = 1;
            p = p->next;
        }
    }
    if(p->data>p->pre->data){
        p->tag = 0;
    }
    else{
        p->tag = 1;
    }


    p = head->next;
    struct chain*q;//工作节点
    //for(p;p->tag!=1&&p!=NULL;p = p->next);
    q = p->pre;
    q->next = NULL;
    p->pre = NULL;
    for(p;p!=NULL;p = p->next){
        if(q->data>p->data){
           // for(q;q->data<p->data&&q->next->data>p->data&&q->pre!=NULL;q = q->pre);
        //     if(q->data<p->data){
        //         q->next->pre = p;
        //         p->next = q->next;
        //         q->next = p;
        //         p->pre= q;
        //     }else{
        //         q->pre = malloc(sizeof(struct chain));
        //         q->pre->next = q;
        //         q = q->pre;
        //         q->pre = NULL;
        //         q->data = p->data;  
        //     }
        // }else if(q->data<p->data){
        //     //for(q;q->data<p->data&&q->next->data>p->data&&q->next!=NULL;q = q->next);
        //     if(q->data<p->data){
        //         q->next->pre = p;
        //         p->next = q->next;
        //         q->next = p;
        //         p->pre= q;
        //     }else{
        //         q->pre = malloc(sizeof(struct chain));
        //         q->pre->next = q;
        //         q = q->pre;
        //         q->pre = NULL;
        //         q->data = p->data;  

        //     }
        }
    }
}
int main(){
    int line[1000];
    for(int i = 0;i<1000;i++){
        line[i] = -1;
    }
    int lenth = numbersgetline(line);
    struct chain*head = malloc(sizeof(struct chain));
    buildchain(head,line);
    mergesort(head);
    for(int i = 0;i<lenth;i++){
        printf("%d",line[i]);
        if(i<lenth-1)
            printf(" ");
    }
}