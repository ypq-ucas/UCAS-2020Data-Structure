#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree*L;
    struct tree*R;
};
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n'&&c!=';';++i){
        if(c<='9'&&c>='0'||c=='-'||c=='n'){           
            if(c=='-')
                state = -1;
            if(c=='n'){
                s[j++] = -1;
            }
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
void buildtree(struct tree *root,struct tree* line[200],int data[1000]){
    int i = 0;
    line[0] = root;
    for(i = 1;i<200;i++){
        line[i] = malloc(sizeof(struct tree));
        line[i]->data = -1;
    }
    for(i = 0;i<99;i++){ 
        line[i]->L = line[2*i+1];
        line[i]->R = line[2*i+2];
    }
    line[0]->data = data[0];
    int j = 1;
    for(i = 1;i<99;i++){
        if(line[i]->data!=-2)
            line[i]->data = data[j++];
        if(data[j-1]==-2){
            line[i]->L->data = -2;
            line[i]->R->data = -2;
        }
    }
    for(i = 1;i<99;i++){
        if(line[i]->data==-1||line[i]->data==-2)
            line[i]->data = -2;
    }
    for(i = 0;i<99;i++){
        if(line[i]->L->data==-2)
            line[i]->L = NULL;
        if(line[i]->R->data==-2)
            line[i]->R = NULL;
    }
}
int complete(struct tree*root){
    struct tree** que[100];
    for(int i = 0;i<100;i++)
        que[i]=malloc(sizeof(struct tree*));
    struct tree**a = que[0];
    struct tree**b = a;
    b++;
    a = &root;
    for(a;*a!=NULL;){
        struct tree*temp = *a;
        a++;
        b = &(temp->L);
        b++;
        b = &(temp->R);
        b++;
    }
    for(a+1;a<que+100;a++){
        if(*a!=NULL)
            printf("0");
    }

}
int data[1000] = {-1};
int main(){
    int data[1000];
    for(int i = 0;i<1000;i++){
        data[i] = -1;
    }
    struct tree* root = malloc(sizeof(struct tree));
    struct tree* line[200];
    numbersgetline(data);
    buildtree(root,line,data);
    
    for(int i = 0;i<1000;i++){
        if(data[i]==-1){
            for(int j = i;j<1000;j++){
                if(data[j]!=-1&&data[j]!=-2){
                    printf("0");
                    goto target;
                }

            }
        }
    }
    printf("1");
    target:if(1);

    
}