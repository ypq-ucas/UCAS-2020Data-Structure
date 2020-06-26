#include<stdio.h>
int fib(int m,int k);
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    fib(b,a);
}
int fib(int m,int k){
    int array[m+1] ;
    if(k>m+1){
        printf("0\n");
    }else{
        for(int i = 0;i<=m;i++)
            array[i] = 0;
        array[k-1] = 1;
        for(int i = k;i<=m;i++){
            for(int j = i-k;j<=i-1;j++){
                array[i]+=array[j];
            }
        }
        printf("%d\n",array[m]);
    }
}