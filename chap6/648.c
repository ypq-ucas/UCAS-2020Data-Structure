#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree*L;
    struct tree*R;
};
int data[1000] ;
struct tree *line[200];
void buildtree(struct tree *root,struct tree* line[200],int data[1000]);
int numbersgetline(int s[]);
int getline(int s[]);
int foundparents(int a,int b,struct tree* root);
void parents(int a,int b,struct tree*root);
int main(){
    for(int i = 0;i<200;i++){
        data[i] = -1;
    }
    struct tree* root = malloc(sizeof(struct tree));
    int numbers[2];
    int a;
    int b;
    numbersgetline(data);
    getline(numbers);
    a = numbers[0];
    b = numbers[1];
    buildtree(root,line,data);
    parents(a,b,root);
}
int foundparents(int a,int b,struct tree* root){
    if(root==NULL)
        return 0;
    else if(root->data==a||root->data==b){
        if(root->L==NULL&&root->R==NULL){
            return 1;
        }
        else if(root->L==NULL&&root->R!=NULL){
            return (1+foundparents(a,b,root->R));
        }
        else if(root->L!=NULL&&root->R==NULL){
            return (1+foundparents(a,b,root->L));
        }
        else if(root->L!=NULL&&root->R!=NULL){
            return (1+foundparents(a,b,root->L)+foundparents(a,b,root->R));
        }
    }

    else{
        return (foundparents(a,b,root->L)+foundparents(a,b,root->R));
    }  
}
void parents(int a,int b,struct tree*root){
    if(foundparents(a,b,root)==2){
        if(foundparents(a,b,root->L)!=2&&foundparents(a,b,root->R)!=2){
            printf("%d",root->data);
        }
        else{
            parents(a,b,root->L);
            parents(a,b,root->R);
        }
    }
}
int getline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n';++i){
        if(c<='9'&&c>='0'||c=='-'||c=='n'){           
            if(c=='-')
                state = -1;
            if(c=='n'){
                s[j++] = 0;
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
    s[j] = '\0';
    return j;
}
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
                s[j++] = -2;
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