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
void buildtree(struct tree *root,struct tree* line[200],int data[1000]){
    int i = 0;
    line[0] = root;
    for(i = 1;i<200;i++){
        line[i] = malloc(sizeof(struct tree));
        line[i]->data = -1;
    }
    for(i = 0;i<50;i++){ 
        line[i]->L = line[2*i+1];
        line[i]->R = line[2*i+2];
    }
    line[0]->data = data[0];
    int j = 1;
    for(i = 1;i<30;i++){
        if(line[i]->data!=-2)
            line[i]->data = data[j++];
        if(data[j-1]==0){
            line[i]->L->data = -2;
            line[i]->R->data = -2;
        }
    }
    for(i = 1;i<200;i++){
        if(line[i]->data==-1||line[i]->data==-2)
            line[i]->data = 0;
    }
}
void turntree(struct tree*root){
    if(root->L->L->data!=0||root->L->R->data!=0||root->R->L->data!=0||root->R->R->data!=0){
        turntree(root->L);
        turntree(root->R);
        struct tree*temp;
        temp = root->L;
        root->L = root->R;
        root->R = temp;
    }
    else{
        struct tree*temp;
        temp = root->L;
        root->L = root->R;
        root->R = temp;
    }

}
int printdata[100] = {0} ;
int i = 0;
void firstprintftree(struct tree*root){
    if(root->L->data!=0||root->R->data!=0){
        if(root->data!=0)
            printdata[i++] = root->data;
        firstprintftree(root->L);
        firstprintftree(root->R);
    }
    else{
        if(root->data!=0)
            printdata[i++] = root->data;
    }
}
int data[100] = {0};
struct tree *line[0];
int main(){
    numbersgetline(data);
    struct tree *root = malloc(sizeof(struct tree));
    buildtree(root,line,data);
    turntree(root);
    firstprintftree(root);
    for(i = 0;i<100;i++){
        if(printdata[i]!=0){
            printf("%d",printdata[i]);
            if(printdata[i+1]!=0){
                printf(",");
            }
        }
    }
}