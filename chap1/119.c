#define MAXINT 65535
#define ARRAYSIZE 300
#include<stdio.h>
void store(int n);
int power2(int n);
int stair(int n);
int main(){
    int n;
    scanf("%d",&n);
    store(n-1);
}
void store(int n){
    int a[ARRAYSIZE];
    if(n>ARRAYSIZE)
        printf("46080\n");
    else{
        int i;
        for(i = 0;i<=n;i++){
            a[i] = power2(i)*stair(i);
            if(a[i]>MAXINT){
                //printf("OVERFLOW\n");
                break;
            } 
        }
        printf("%d\n",a[i-1]);
    }
}
int power2(int n){
    int sum = 1;
    for(int i = 1;i<=n;i++){
        sum*=2;
    }
    return sum;
}
int stair(int n){
    int sum = 1;
    for(int i = 1;i<=n;i++){
        sum*=i;
    }
    return sum;
}
