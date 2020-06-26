#include<stdio.h>
void compare(int a,int b,int c);
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    compare(a,b,c);
}
void compare(int a,int b,int c){
    int i,j,k;
    if(a>=b){
        if(a>=c){
            if(b>=c){
                i = a;
                j = b;
                k = c;
            }
            else{
                i = a;
                j = c;
                k = b; 
            }
        }
        else{
            i = c;
            j = a;
            k = b;
        }
    }
    else{
        if(a>=c){
            i = b;
            j = a;
            k = c;
        }//a<b,a<c
        else{
            if(b>c){
                i = b;
                j = c;
                k = a;
            }
            else{
                i = c;
                j = b;
                k = a;
            }
        }
    }
    printf("%d %d %d\n",i,j,k);
}