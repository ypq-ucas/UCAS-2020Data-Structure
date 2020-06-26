#include<stdio.h>
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
void compare(int line[],int a[],int lenth){
    for(int i = 0;i<lenth;i++){
        for(int j = 0;j<1000;j++){
            if(line[i]==j){
                a[j]++;
            }
        }
    } 
}
int main(){
    int line[100];
    int lenth = numbersgetline(line);
    int a[1000] = {0};
    compare(line,a,lenth);
    int numbers = 0;
    for(int i = 0;i<1000;i++){
        if(a[i]!=0){
            for(int j = 0;j<a[i];j++){
                if(i<=99)
                    printf("0");
                if(i<=9)
                     printf("0");
                printf("%d",i);
                if(j<a[i]-1)
                    printf(" ");
            }
            numbers++;
            if(numbers<lenth){
                printf(" ");
            }
        }
    }
    
}