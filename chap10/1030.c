#include<stdio.h>
#include<stdlib.h>
struct minmax{
    int min;
    int max;
};
struct stack{
    struct minmax data[100];
    struct minmax*bottom;
    struct minmax*top;
};
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n';++i){
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
        else if(c==';'){
            s[j++] = c;
            ++i;
            number = 0;
            state = 1;
        }
        else{
            number = 0;
            state = 1;
        }
    }
    //s[j] = '\0';
    return j;
}
void Initstack(struct stack *stack){
    stack->bottom = stack->data;
    stack->top = stack->bottom;
}
void push(struct stack*stack,int data[2]){
    (stack->top)->max = data[1];
    (stack->top)->min = data[0];
    stack->top++;
}
struct minmax pop(struct stack *stack){
    return *((stack->top)--);
}
void swap(int line[],int a,int b){
    int temp = line[a];
    line[a] = line[b];
    line[b] = temp;
}
void qqsort(int line[],int low,int high){
    int middle = (low+high)/2;
    if(low==high||low-high==1||high-low==1)
        return;

        for(int i = low;i<=high;i++){
            if(line[i]>line[middle]&&i<middle){
                swap(line,i,middle-1);
                swap(line,middle,middle-1);
                middle--;
            }
            else if(line[i]<line[middle]&&i>middle){
                swap(line,i,middle+1);
                swap(line,middle,middle+1);
                middle++;
            }
            else if(line[i]==line[middle]){
                if(i!=middle-1&&i<middle){
                    swap(line,i,middle-1);
                    i--;
                }
                    
                else if(i!=middle+1&&i>middle){
                    swap(line,i,middle+1);
                    i++;
                }
            }
                
        }

        qqsort(line,low,middle);
        qqsort(line,middle,high);
}
int line[100];
int main(){
    for(int i = 0;i<100;i++){
        line[i] = 100;
    }
    struct stack *stack = malloc(sizeof(struct stack));
    Initstack(stack);
    int lenth = numbersgetline(line);
    qqsort(line,0,lenth-1);
    qqsort(line,0,lenth-1);
    qqsort(line,0,lenth-1);
    for(int i = 0;i<lenth;i++){
        printf("%d",line[i]);
        if(i<lenth-1){
            printf(",");
        }
    }
}