#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node* left;
    struct node*mid;
    struct node*right;
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
        else if(c==';'){
            s[j++] = c;
            ++i;
            number = 0;
            state = 1;
        }
        else{
            number = 0;
            state = 1;
        }
    }
    //s[j] = '\0';
    return j;
}
void buildtree(struct node*root[1000],int line[100],int lenth){
    for(int i = 0;i<310;i++){
        root[i]->data = -1;
        root[i]->left = root[3*i+1];
        root[i]->mid = root[3*i+2];
        root[i]->right = root[3*i+3];
    }
    for(int i = 0;i<lenth;i++){
        root[i]->data = line[i];
    }
    for(int i = 0;i<310;i++){
        if(root[i]->left->data==-1){
            root[i]->left = NULL;
        }
        if(root[i]->right->data==-1){
            root[i]->right = NULL;
        }
        if(root[i]->mid->data==-1){
            root[i]->mid = NULL;
        }
    }
}
void sort(struct node*root[1000],int lenth){
    int i = 0;
    for(i;root[i]->left||root[i]->mid||root[i]->right;i++);
    i--;
    int k = i;
    for(int j = k;j>=0;j--){
        for(i = k;i>=0;i--){
            if(root[i]->left&&root[i]->left->data>root[i]->data){
                int temp = root[i]->data;
                root[i]->data = root[i]->left->data;
                root[i]->left->data = temp;
            }
            if(root[i]->right&&root[i]->right->data>root[i]->data){
                int temp = root[i]->data;
                root[i]->data = root[i]->right->data;
                root[i]->right->data = temp;
            }
            if(root[i]->mid&&root[i]->mid->data>root[i]->data){
                int temp = root[i]->data;
                root[i]->data = root[i]->mid->data;
                root[i]->mid->data = temp;
            }
        }
    }
    int print[1000];
    k = 0;
    for(int j = lenth;j>0;j--){
        if(root[0]->data==805){
            int a = 1;
        }
        print[k++] = root[0]->data;
        root[0]->data = -1;
        
            for(i = lenth;i>=0;i--){
                if(root[i]->left&&root[i]->left->data>root[i]->data){
                    int temp = root[i]->data;
                    root[i]->data = root[i]->left->data;
                    root[i]->left->data = temp;
                }
                if(root[i]->right&&root[i]->right->data>root[i]->data){
                    int temp = root[i]->data;
                    root[i]->data = root[i]->right->data;
                    root[i]->right->data = temp;
                }
                if(root[i]->mid&&root[i]->mid->data>root[i]->data){
                    int temp = root[i]->data;
                    root[i]->data = root[i]->mid->data;
                    root[i]->mid->data = temp;
                }
            }
        
    

        
    }
    for(int i = 0;i<lenth;i++){
        printf("%d",print[lenth-1-i]);
        if(i<lenth-1){
            printf(",");
        }
    }
}
int main(){
    int line[100];
    int lenth = numbersgetline(line);
    struct node*root[1000];
    for(int i = 0;i<1000;i++){
        root[i] = malloc(sizeof(struct node));
    }
    buildtree(root,line,lenth);
    sort(root,lenth);
    int a = 0;
}
