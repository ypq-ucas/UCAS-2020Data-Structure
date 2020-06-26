#include<stdio.h>
#include<stdlib.h>
struct map{
    char data;
    struct map*next;
};
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n'&&c!=';';++i){
        if(c<='9'&&c>='0'){           
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
            if(c=='/'||c=='+'||c=='-'||c=='*'||(c<='Z'&&c>='A')||(c<='z'&&c>='a')){
                s[j++] = c;
            }
            number = 0;
            state = 1;
        } 
    }
    if(c=='\n'||c==';'){
        //s[j] = c;
        ++i;
    }
    //s[j] = '\0';
    return j;
}
void buildmap(struct map*line[100],int numbers){
    for(int i = 1;i<=numbers;i++){
        int data[10];
        int lenth = numbersgetline(data);
        line[i]->data = data[0];
        struct map*p  = line[i];
        for(int j = 1;j<lenth;j++){
            p->next = malloc(sizeof(struct map));
            p = p->next;
            p->data = data[j];
            p->next = NULL;
        }
    }
    for(int i = 1;i<=numbers;i++){
        struct map*p = line[i]->next;
    }
}
void printmap(struct map*line[100],struct map*p){
    if(p==NULL){
        return;
    }
    else{
        if(p->next){
            printmap(line,line[p->next->next->data+1]);
            printmap(line,line[p->next->data+1]);
        }
        printf("%c",p->data);
    }
}
int main(){
    int numbers;
    numbersgetline(&numbers);
    struct map*line[100];
    for(int i = 0;i<100;i++){
        line[i] = malloc(sizeof(struct map));
        line[i]->data = -1;
        line[i]->next = NULL;
    }
    buildmap(line,numbers);
    printmap(line,line[1]);
}