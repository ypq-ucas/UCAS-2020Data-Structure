#include<stdio.h>
void swap(int s[],int i,int j);
int main(){
    int va[100];
    int i = 0;
    while(scanf("%d",va+i++)!=EOF)
        ;
    i-=2;
    int j = i+1;
    for(i;va[i]<va[i-1];i--)
        swap(va,i,i-1);
    for(i = 0;i<j;i++){
        printf("%d",va[i]);
        if(i<j-1)
            printf(" ");
    }
}
void swap(int s[],int i,int j){
    int temp;
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
}