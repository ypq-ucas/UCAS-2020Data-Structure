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
int fuctiongetline(char s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!=';';++i){
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
            if(c>='A'&&c<='Z'){
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
void IA(struct map*line[100],int a,int b){
    int i;
    for(i = 0;i<100;i++){
        if(line[i]->data== a)
            break;
    }
    struct map*temp = line[i];
    for(temp;temp->next!=NULL;temp = temp->next);
    temp->next = malloc(sizeof(struct map));
    temp = temp->next;
    temp->data = b;
    temp->next = NULL;
    
}
void DV(struct map*line[100],int a){
    line[a]->data = -1;
    line[a]->next = NULL;
    for(int i = 0;i<100;i++){
        if(line[i]->data!=-1){
            struct map*temp = line[i];
            for(temp;temp->next!=NULL&&temp->next->data!=a;temp = temp->next);
            if(temp->next){
                temp->next = temp->next->next;
                //free(temp->next);
            }
        }
    }
}
void DA(struct map*line[100],int a,int b){
    struct map*temp = line[a];
    for(temp;temp->next!=NULL&&temp->next->data!=b;temp = temp->next);
    if(temp->next){
        temp->next = temp->next->next;
        //free(temp->next);
    }
}
int main(){
    struct map*line[100];
    for(int i = 0;i<100;i++){
        line[i] = malloc(sizeof(struct map));
        line[i] ->data = -1;
        line[i]->next = NULL;
    }
    int data[100]= {0};
    int numbers;
    numbersgetline(&numbers);
    for(int i = 1;i<=numbers;i++)
        line[i]->data = i;
    numbersgetline(data);
    buildmap(line,data);
    char function[100] = {0};
    fuctiongetline(function);
    for(int i = 0;i<100;i++){
        if(function[i]=='I'&&function[i+1]=='V'){
            line[function[i+2]]->data = function[i+2];//IV
            i+=2;
            numbers++;
        }
        else if(function[i]=='I'&&function[i+1]=='A'){
            IA(line,function[i+2],function[i+3]);//IA
            i+=3;
        }
        else if(function[i]=='D'&&function[i+1]=='V'){
            DV(line,function[i+2]);//DV
            i+=2;
            numbers--;
        }
        else if(function[i]=='D'&&function[i+1]=='A'){
            DA(line,function[i+2],function[i+3]);//DV
            i+=3;
        }
    }
    int flag = 0;
    for(int i = 0;i<100&&flag<numbers;i++){
        if(line[i]->data!=-1){
            int print[10] = {0};
            int k = 0;
            for(int j = 0;j<9;j++){
                if(line[j]->data!=-1){
                    struct map*temp = line[i]->next;
                    for(temp;temp!=NULL&&temp->data!=j;temp = temp->next);
                    if(temp)
                        print[k++] = 1;
                    else
                        k++; 
                }              
            }
            for(int i = 0;i<numbers;i++){
                printf("%d",print[i]);
                if(i<numbers-1)
                    printf(",");
            }
            flag++;
            printf("\n");
        }
    }
}