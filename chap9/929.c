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
        line[i] = -3;
    }
    numbersgetline(line);
    int i = 0;
    for(i ;line[i]!=';';i++);
    i++;
    int *t = line;
    int *s = line;
    for(i;line[i]!=-3;i++){
        while(*t!=line[i]){
            if(*t<line[i]){
                printf("%d,",*t);
                t++;
            }
            else if(*t>line[i]){
                printf("%d,",*t);
                t = s;
            }
        }
        printf("%d",line[i]);
        if(line[i+1]!=-3)
            printf(";");
    }
}