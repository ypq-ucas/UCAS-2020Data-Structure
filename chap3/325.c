#include<stdio.h>
int cal(int n);
int cal(int n){
    if(n==0)
        return 1;
    else
    {
        return n*cal(n/2);
    }
    
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",cal(n));
}