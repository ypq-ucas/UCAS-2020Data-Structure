#include<stdio.h>
int numbersgetline(int s[]);
int cal(int m,int n);
int cal(int m,int n){
    if(m==0)
        return 0;
    else
    {
        return cal(m-1, 2*n)+n ;
    }
    
}
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        if(c!=','){
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
int main(){
    int line[3];
    numbersgetline(line);
    printf("%d",cal(line[0],line[1]));
}