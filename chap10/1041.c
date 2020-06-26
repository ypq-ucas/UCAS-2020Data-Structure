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
int main(){
    int line[1000];
    int lenth = numbersgetline(line);
    for(int i = 0;i<lenth;i++){
        printf("%d",line[i]);
        if(i<lenth-1)
            printf(" ");
    }
}