#include<stdio.h>
#include<stdlib.h>
int pop(int stack[100],int *top);
void InitStack(int stack[100],int *top);
void push(int a,int stack[100],int *top);
int main(){
    int stack[100];
    int *top;
    int c;
    int state = 0;
    top = stack;
    while((c = getchar())!='&'){
        *top = c;
        top++;
    }
    while((c = getchar())!='@'){
        if(c==*(--top))
            ;
        else
        {
            printf("0");
            return 0;
        }
    }
    if(top==stack){
        printf("1");
        return 0;
    }
    else
    {
        printf("0");
        return 0;
    }
    
}
