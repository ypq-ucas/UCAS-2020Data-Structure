#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    int Ltag;
    struct tree*L;
    struct tree*Lchild;
    int Rtag;
    struct tree*R;
    struct tree*Rchild;
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
struct tree*origin;
struct tree* pre;
void cluesive(struct tree* root){
    if(root){
        cluesive(root->L);
            if(!root->L){
                root->Ltag = 1;
                root->L = pre;
            }
            if(!pre->R){
                pre->Rtag = 1;
            }
            if(pre->R!=root){
                pre->Rchild = root;
            }
            pre = root;
            if(root->data==3)
                root->data = 3;
        cluesive(root->R);
    }
}
int printdata[1000];
int b = 0;
printcluesive(struct tree* origin){
    struct tree *p = origin;
    int i = 0;
    p = p->Rchild;
    while(p!=NULL){
        printdata[i++] = p->Ltag;
        printdata[i++] = ',';
        printdata[i++] = p->L->data;
        printdata[i++] = ',';
        printdata[i++] = p->Rtag;
        printdata[i++] = ',';
        if(p->R&&!p->Rtag)
            printdata[i++] = p->R->data;
        else if(p->Rtag&&p->Rchild){
            printdata[i++] = p->Rchild->data;
        }
        else
            printdata[i++] = 0;
        printdata[i++] = ';';
        if(p->Rchild>0xffffff)
            p = p->R;
        else
            p = p->Rchild;
        
    }
}
int main(){
    int data1[1000];
    int data2[1000];
    for(int i = 0;i<1000;i++){
        data1[i] = -1;
        data2[i] = -1;
    }
    struct tree* line1[200];
    struct tree* line2[200];
    struct tree* root1 = malloc(sizeof(struct tree));
    struct tree* root2 = malloc(sizeof(struct tree));
    pre = malloc(sizeof(struct tree));
    pre->R = NULL;
    origin = pre;
    pre->data = 0;
    numbersgetline(data1);
    buildtree(root1,line1,data1);
    numbersgetline(data2);
    buildtree(root2,line2,data2);
    int a;
    numbersgetline(&a);
    for(int i = 0;i<200;i++){
        if(line1[i]->data==a){
            if(line1[i]->L==NULL)
                line1[i]->L = root2;
            else{
                struct tree *temp = line1[i]->L;
                line1[i]->L = root2;
                root2->R = temp; 
            }
                
        }
        line1[i]->Ltag = 0;
        line2[i]->Ltag = 0;
        line1[i]->Rtag = 0;
        line2[i]->Rtag = 0;
    }
    cluesive(root1);
    pre->Rtag = 1;
    pre->Rchild = NULL;
    printcluesive(origin);
    int i = 0;
    while(printdata[i]||printdata[i+1]){
        if(printdata[i]==','||printdata[i]==';'){
            if(printdata[i]==',')
                printf("%c",printdata[i]);
            if(printdata[i]==';'){
                if(printdata[i+1]||printdata[i+2])
                    printf("%c",printdata[i]);
            }
        }
        else
            printf("%d",printdata[i]);
        i++;
    }
}