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
int main(){
    int line[100];
    for(int i = 0;i<100;i++){
        line[i] = -1;
    }
    int i = numbersgetline(line);
    int i1,i2,i3;
    i1 = 0;
    i2 = 0;
    i3 = 0;
    for(int j = 0;j<i;j++){
        if(line[j] == 0)
            i1++;
        else if(line[j]==1)
            i2++;
        else
        {
            i3++;
        }
    }
    for(i = 0;i<i1;printf("0,"),i++);
    for(i = 0;i<i2;printf("1,"),i++);
    for(i = 0;i<i3;i++){
        printf("2");
        if(i<i3-1)
            printf(",");
    }
}