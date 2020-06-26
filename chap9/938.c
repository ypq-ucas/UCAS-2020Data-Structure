#include<stdio.h>
#include<Windows.h>
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
    for(i = 0;(c = getchar())!=EOF&&c!='\n';++i){
        if(c<='9'&&c>='0'||c=='-'){           
            if(c=='-')
                state = -1;
            // if(c=='n'){
            //     s[j++] = -2;
            // }
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
void buildtree(struct tree*root,struct tree*line[200],int data[1000]){
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
        if(data[j]==3)
            ;
        if(line[i]->data!=-2)
            line[i]->data = data[j++];
        if(line[i]->data==-2){
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
int print[100];
int i = 0;
int check(struct tree*root){
    if(!root){
        return 1;
    }
    else{
        check(root->L);
        print[i++] = root->data;
        check(root->R);
    }
}
void merge(int data[100]){
    for(int i = 0;i<100;i++){
        for(int j = 99;j>i;j--){
            if(data[j]<data[j-1]){
                int temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
            }
        }
    }
}
int main(){
    int a,b;
    int max[2];
    int data[1000];
    for(int i = 0;i<1000;i++){
        data[i] = -1;
    }
    struct tree* root1 = malloc(sizeof(struct tree));
    struct tree* root2 = malloc(sizeof(struct tree));
    struct tree* line1[200];
    struct tree* line2[200];
    numbersgetline(data);
    buildtree(root1,line1,data);
    merge(data);
    // for(int i = 0;i<1000;i++){
    //     data[i] = -1;
    // }
    //numbersgetline(data);
    //buildtree(root2,line2,data);
    //merge(data);
    for(int i = 0;i<100;i++){
        if(data[i]!=-1){
            printf("%d",data[i]);
            if(i<99){
                printf(",");
            }
        }
    }
}