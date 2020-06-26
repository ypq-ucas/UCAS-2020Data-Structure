#include<stdio.h>
int numbersgetline(char s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n';++i){
        if(c<='9'&&c>='0'||c=='-'){
            if(c==';'){
                number = 0;
                state = 1;
            }
                
            else if(c=='-')
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
        else{
            s[j++] = c;
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
int main(){
    char line[100];
    numbersgetline(line);
    int x;
    int i = 1;
    x = line[0];
    
    for(i;i<100;i++){
        if(line[i]==x){
            if(line[i+1]==','){
                for(int j = i;j<100;j++){
                    line[j] = line[j+2];
                }

            }
            else{
                if(line[i-1]==',')
                    for(int j = i-1;j<100;j++){
                        line[j] = line[j+2];
                    }
                else{
                    for(int j = i;j<100;j++){
                        line[j] = line[j+1];
                    }
                }
            }
        }
    }
    for(i = 1;i<100;i++){
        if(line[i]==x){
            if(line[i+1]==','){
                for(int j = i;j<100;j++){
                    line[j] = line[j+2];
                }
                
            }
            else{
                if(line[i-1]==',')
                    for(int j = i-1;j<100;j++){
                        line[j] = line[j+2];
                    }
                else{
                    for(int j = i;j<100;j++){
                        line[j] = line[j+1];
                    }
                }
            }
        }
    }
    for(int i = 2;line[i]!=0;i++){
        if(line[i]<='z'&&line[i]>='a'||line[i]==','||line[i]=='('||line[i]==')')
            printf("%c",line[i]);
        else
        {
            printf("%d",line[i]);
        }
        
    }
}