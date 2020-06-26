#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree*L;
    struct tree*R;
};
int numbersgetline(char s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n'&&c!=';';++i){
        if((c<='9'&&c>='0'||c=='n')&&c!=','){           
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
        if(c=='*'||c=='+'||c=='-'||c=='/'){
            s[j++]=c;
            ++i;
        }
    }
    if(c=='\n'||c==';'){
        //s[j] = c;
        ++i;
    }
    //s[j] = '\0';
    return j;
}
void buildtree(struct tree *root,struct tree* line[200],char data[1000]){
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
int printtree(struct tree*root,int pri){
    int temp = root->data=='*'?2:root->data=='-'?1:0;
    if(root==NULL)
        ;
    else if(root->L!=NULL&&root->R!=NULL){
        
        if(pri>temp||pri==1&&temp==1)
            printf("(");
        printtree(root->L,temp);
        if(root->data>=0&&root->data<=9){
            printf("%d",root->data);
        }
        else{
            printf("%c",root->data);
        }
        printtree(root->R,temp);
        if(pri>temp||pri==1&&temp==1)
            printf(")");
    }
    else if(root->L!=NULL&&root->R==NULL){
        printtree(root->L,temp);
        if(root->data>=0&&root->data<=9){
            printf("%d",root->data);
        }
        else{
            printf("%c",root->data);
        }
    }
    else if(root->L==NULL&&root->R!=NULL){
        if(root->data>=0&&root->data<=9){
            printf("%d",root->data);
        }
        else{
            printf("%c",root->data);
        }
        printtree(root->R,temp);
    }
    else if(root->L==NULL&&root->R==NULL){
        if(root->data>=0&&root->data<=9){
            printf("%d",root->data);
        }
        else{
            printf("%c",root->data);
        }
    }

}
int print[100];
int main(){
    char data[1000];
    for(int i = 0;i<1000;i++)
        data[i] = -1;
    numbersgetline(data);
    struct tree*line[200];
    struct tree*root = malloc(sizeof(struct tree));
    buildtree(root,line,data);
    printtree(root,0);
}