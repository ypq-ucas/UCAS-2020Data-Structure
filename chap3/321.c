#include<stdio.h>
#include<stdlib.h>
struct stack{
    char stack[100];
    char *top;
};
void InitStack(struct stack* Astack);
int push(char a,struct stack* Astack);
int pop(struct stack *Astack);
int getline(char s[]);
int cmp(int a,int b);
void InitStack(struct stack*Astack){
    Astack->top = Astack->stack;
}
int push(char a,struct stack* Astack){
    if(Astack->top==(Astack->stack+99))
        return 1;
    else{
        *(Astack->top) = a;
        Astack->top++;
    }
}
int pop(struct stack *Astack){
    if(Astack->top!=Astack->stack){   
        return *(--Astack->top);
    }
    else
        return -1;
}
int getline(char s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}
int cmp(int a,int b){
    int ascore,bscore;
    switch (a)
    {
    case '-':
        ascore = 1;
        break;
    case '+':
        ascore = 1;
        break;
    case '*':
        ascore = 2;
        break;
    case '/':
        ascore = 2;
        break;
    default:
        ascore = 0;
        break;
    }
    switch (b)
    {
    case '-':
        bscore = 1;
        break;
    case '+':
        bscore = 1;
        break;
    case '*':
        bscore = 2;
        break;
    case '/':
        bscore = 2;
        break;
    default:
        bscore = 0;
        break;
    }
    if(ascore>bscore)
        return 1;
    else if(ascore==bscore)
        return 0;
    else if(ascore<bscore)
        return -1;
}
int main(){
    struct stack*symbols = malloc(sizeof(struct stack));
    struct stack*rpm = malloc(sizeof(struct stack));
    InitStack(symbols);
    InitStack(rpm);
    char calculate[100];
    getline(calculate);
    for(int i = 0;calculate[i]!='\0';i++){
        if((calculate[i]<='Z'&&calculate[i]>='A')||(calculate[i]<='z'&&calculate[i]>='a')){
            push(calculate[i],rpm);
        }
        else if(calculate[i]=='('){
            push(calculate[i],symbols);
        }
        else if(calculate[i]=='+'||calculate[i]=='-'||calculate[i]=='*'||calculate[i]=='/'){
            if(cmp(calculate[i],*((symbols->top)-1))>0)
                push(calculate[i],symbols);
            else{
                while(cmp(calculate[i],*(symbols->top-1))<=0){
                    push(pop(symbols),rpm);
                }
                push(calculate[i],symbols);
            }
        }
        else if(calculate[i]==')'){
            while(*(symbols->top-1)!='('){
                push(pop(symbols),rpm);
            }
            pop(symbols);
        }
    }
    int a;
    while((a = pop(symbols))!=-1){
        push(a,rpm);
    }
    do{
        rpm->top = rpm->top-1;
        push((*rpm->top),symbols);
    }while(rpm->top!=rpm->stack);
    do{
        symbols->top = symbols->top-1;
        printf("%c",(*symbols->top));
    }while(symbols->top!=symbols->stack);
}