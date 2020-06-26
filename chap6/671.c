#include<stdio.h>
#include<stdlib.h>
struct tree{
    char data;
    struct tree*child;
    struct tree*brother;
};
int numbersgetline(char s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n'&&c!=';';++i){
        if(c<='Z'&&c>='A'||c=='n'||c<='9'&&c>='0'){           
            if(c=='-')
                state = -1;
            if(c=='n'){
                s[j++] = -2;
            }
            else {
                s[j++] = c; 
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
void buildtree(struct tree *line[200],char data[1000]){
    int j = 0;
    struct tree *root = line[j];
    for(int i = 1;i<50;){
        if(root->data!=-2){
            int k;
            root->child = data[i]!=-2?line[i]:NULL;
            i++;
            root->brother = data[i]!=-2?line[i]:NULL;
            i++;
        }
        root = line[++j];
    }
}
void printtree(struct tree*root,int depth){
    if(root){
        for(int i = 0;i<depth;i++)
            printf(" ");
        printf("%c",root->data);
        printf("\n");
        printtree(root->child,depth+1);
        printtree(root->brother,depth);
    }
}
struct tree* line[200];
int main(){
    char data[1000];
    for(int i = 0;i<100;i++){
        data[i] = -1;
    }
    struct tree* root;
    numbersgetline(data);
    for(int i = 0;i<100;i++){
        line[i] = malloc(sizeof(struct tree));
        line[i]->data = data[i];
        line[i]->brother = NULL;
        line[i]->child = NULL;
    }
    root = line[0];
    buildtree(line,data);
    for(int i = 0;i<100;i++){
        if(line[i]->brother&&line[i]->brother>100){
            if(line[i]->brother->data==-1)
                line[i]->brother = NULL;
        }
        if(line[i]->child){
            if(line[i]->child->data==-1)
                line[i]->child = NULL;
        }
    }
    printtree(root,0);
}