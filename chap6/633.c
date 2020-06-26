#include<stdio.h>
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n'&&c!=';';++i){
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
        else{
            number = 0;
            state = 1;
        } 
    }
    if(c=='\n'||c==';'){
        //s[j] = c;
        ++i;
    }
    s[j] = '\0';
    return j;
}
int main(){
    int u[2];
    int v[2];
    int L[100] = {0};
    int R[100] = {0};
    numbersgetline(L);
    numbersgetline(R);
    numbersgetline(&u);
    numbersgetline(&v);
    printf("%d",found(u[0],v[0],L,R));
    
}
int found(int u,int v,int L[100],int R[100]){
    if(L[v]==0&&R[v]==0){
        return 0;
    }
    if(L[v]==u||R[v]==u){
        return 1;
    }
    if(L[v]!=0||R[v]!=0){
        return (found(u,L[v],L,R)||found(u,R[v],L,R));
    }
}