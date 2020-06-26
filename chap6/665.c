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
int i = 0;
int j = 0;
void buildtree(struct tree *root,int data1[100],int data2[100],int lenth){
    if(lenth==0)
        return;
    root->L = malloc(sizeof(struct tree));
    root->R = malloc(sizeof(struct tree));
    root->data = data1[0];
    int k;
    for(k = 0;data2[k]!=data1[0];k++);
    buildtree(root->L,data1+1,data2,k);
    buildtree(root->R,data1+1+k,data2+1+k,(lenth-k-1));
}
int printdata[100];
int k =0;
void printtree(struct tree*root){
    if(root->data>100||root->data<-100)
        return;
    else{
        printtree(root->L);
        printtree(root->R);
        printdata[k++] = root->data;
    }
}
int main(){
    int data1[100] = {0};//先序
    int data2[100] = {0};//中序
    int lenth;
    lenth = numbersgetline(data1);
    numbersgetline(data2);
    struct tree *root = malloc(sizeof(struct tree));
    buildtree(root,data1,data2,lenth);
    printtree(root);
    for(i = 0;i<100;i++){
        if(printdata[i]!=0){
            printf("%d",printdata[i]);
            if(printdata[i+1]!=0||printdata[i+2]!=0)
                printf(",");
        }
    }
}