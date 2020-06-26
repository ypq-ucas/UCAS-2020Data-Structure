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
    while((c = getchar())!='\n'){
        if(c=='(')
            *(top++) = c;
        else if(c==')')
            top--;
    }   
    if (top==stack)
        printf("1");
    else
    {
        printf("0");
    }
    
    
    
}