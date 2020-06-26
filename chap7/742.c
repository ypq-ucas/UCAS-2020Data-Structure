#include<stdio.h>
#include<stdlib.h>
struct map{
    int data;
    int distance;
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
void buildmap(struct map*line[100]){
    int data[3];
    for(;numbersgetline(data)>0;){
        struct map*p = line[data[0]];
        p->data = data[0];
        for(p;p->next!=NULL;p = p->next);
        p->next = malloc(sizeof(struct map));
        p = p->next;
        p->data = data[1];
        p->distance = data[2];
        p->next =NULL;
    }
}
int distance[10];
int dijkstra(struct map*line[100],int begin,int origin,int path){
    if(path>30)
        return;
    struct map*p = line[origin]->next;
    for(p;p!=NULL;p = p->next){
        if((p->data!=begin)&&((path+p->distance)<distance[p->data]))
        distance[p->data] = p->distance+path;
    }
    p = line[origin]->next;
    for(p;p!=NULL;p = p->next){
        dijkstra(line,begin,p->data,distance[p->data]);
    }
}
int main(){
    int numbers;
    int data[2];
    int origin;
    struct map*line[100];
    for(int i = 0;i<100;i++){
        line[i] = malloc(sizeof(struct map));
        line[i] ->data = -1;
        line[i]->next = NULL;
    }
    numbersgetline(data);
    numbers = data[0];
    origin = data[1];
    for(int i = 1;i<=numbers;i++)
        line[i]->data = i;
    buildmap(line);
    for(int i = 1;i<=numbers;i++){
        distance[i] = 1000;
    }
    dijkstra(line,origin,origin,0);
    int print[10] = {0};
    int j = 0;
    for(int i = 1;i<=numbers;i++){
        if(i!=origin){
            print[j++] = distance[i];
        }
    }
    for(int i = 0;i<numbers-1;i++){
        printf("%d",print[i]);
        if(i<numbers-2)
            printf(",");
    }
}