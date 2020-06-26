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
        for(p;p->next!=NULL;p = p->next);
        p->next = malloc(sizeof(struct map));
        p = p->next;
        p->data = data[i+1];
        p->next =NULL;
    }
}
int main(){
    int data[100] = {0};
    numbersgetline(data);
    int a = data[0];
    numbersgetline(data);
    struct map* line[100];
    for(int i = 0;i<100;i++){
        line[i] = malloc(sizeof(struct map));
        line[i]->data = i;
        line[i]->next = NULL;
    }
    buildmap(line,data);
    for(int  i = data[0];i<data[0]+a;i++){
         int flag = 0;
        printf("%d",line[i]->data);
        int temp[10];
        for(int j = 0;j<10;j++)
            temp[j] =0;
        int k = 0;
        for(int j = 10;j>=0;j--){
            struct map * p = line[i]->next;
            for(p;p!=NULL&&p->data!=j;p = p->next);
            if(p){
                if(j)
                    temp[k++] = j;
                else
                    temp[k++] = -1;
            }
        }

        for(int j = 0;j<10;j++){
            if(temp[j]!=0){
              if(flag == 0) {
               printf(" ");
               flag = 1;
              }
                printf("%d",temp[j]!=-1?temp[j]:0);
            }
            if(j+1<10 && temp[j+1]!=0){
                printf(",");
              }
        }
         printf("\n");
    }

}