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
void compare(struct chain*head,int a[],int lenth){
    for(head;head!=NULL;head = head->next){
        for(int i = 0;i<1000;i++){
            if(head->data+100==i){
                a[i]++;
            }
        }
    }
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
int main(){
    int line[100];
    for(int i = 0;i<100;i++){
        line[i] = -1;
    }
    int lenth = numbersgetline(line);
    struct chain*head = malloc(sizeof(struct chain));
    buildchain(head,line);
    int a[1000] = {0};
    compare(head,a,lenth);
    int numbers = 0;
    for(int i = 0;i<1000;i++){
        if(a[i]!=0){
            for(int j = 0;j<a[i];j++){
                printf("%d",i-100);
                if(j<a[i]-1)
                    printf(" ");
                    numbers++;
            }
            if(numbers<lenth){
                printf(" ");
            }
        }
    }
    
}