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
int numbers;
void buildmap(struct map *line[100],int s[100],int fst[100],int lst[100]){
    for(int i = 1;i<=numbers;i++){
        struct map* p = line[i];
        p->data = i;
        for(int j = fst[i];j<=lst[i];j++){
            p->next = malloc(sizeof(struct map));
            p = p->next;
            p->data = s[j];
            p->next = NULL;
        }
    }
}
int findcircle(struct map*line[100],struct map*p,int a){
    p = p->next;
    for(p;p!=NULL&&p->data!=-1;p = p->next){
        if(p->data==a){
            return 1;
        }
        else{
            return(findcircle(line,line[p->data],a));
        }
    }
    if(p==NULL||p->data==-1){
        return 0;
    }
}
int main(){
    numbersgetline(&numbers);
    int s[100] = {0};
    int fst[100] = {0};
    int lst[100] = {0};
    numbersgetline(s);
    numbersgetline(fst);
    numbersgetline(lst);
    struct map*line[100];
    for(int i = 0;i<100;i++){
        line[i] = malloc(sizeof(struct map));
        line[i] ->data = -1;
        line[i]->next = NULL;
    }
    buildmap(line,s,fst,lst);
    int a = 0;
    for(int i = 1;i<=numbers;i++){
        a = a|findcircle(line,line[i],i);
    }
    printf("%s",a?"yes":"no");
}