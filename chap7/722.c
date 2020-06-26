#include<stdio.h>
#include<stdlib.h>
struct map{
    int data;
    struct map*next;
};
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n'&&c!=';';++i){
        if((c<='9'&&c>='0')&&c!=','){           
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
void buildmap(struct map*line[100],int data[100]){
    for(int i = 0;data[i]!=0||data[i+1]!=0;i+=2){
        struct map*p = line[data[i]];
        p->data = data[i];
        for(p;p->next!=NULL;p = p->next);
        p->next = malloc(sizeof(struct map));
        p = p->next;
        p->data = data[i+1];
        p->next =NULL;
    }
}
int found(struct map*line[100],int i,int j,int depth){
    if(i==j){
        return 1;
    }
    else{
        int result = 0;
        struct map*p = line[i]->next;
        if(depth<6){
            for(p;p!=NULL;p = p->next){
            result = result||found(line,p->data,j,++depth);
            }
            return result;
        }
        else{
            return 0;
        }
        
    }
}
int numbers;
int main(){
    struct map*line[100];
    for(int i = 0;i<100;i++){
        line[i] = malloc(sizeof(struct map));
        line[i] ->data = -1;
        line[i]->next = NULL;
    }
    int data[100]= {0};
    numbersgetline(&numbers);
    for(int i = 1;i<=numbers;i++)
        line[i]->data = i;
    numbersgetline(data);
    buildmap(line,data);
    int i,j;
    numbersgetline(data);
    i = data[0];
    j = data[1];
    printf("%s",found(line,i,j,0)?"yes":"no");
}