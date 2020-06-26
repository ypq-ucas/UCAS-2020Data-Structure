#include<stdio.h>
#include<stdlib.h>
struct trienode{
    int nodekind;//0时对应枝干节点，1时对应叶子节点
    char leafname[10];
    int layer;//第几层
    int maxlayer;
    struct trienode* ptr[27];//通向下层的指针
    int num//多少个关键词经过这个节点
};
int numbersgetline(char s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n'&&c!=';';){
        s[j++] = c;
    }
    s[j] = '\0';
    return j;
}
void Inittrietree(struct trienode*root,int h){
    root->maxlayer = h;
    root->layer = 0;
    root->nodekind = 0;
    root->num = 0;
    for(int i = 0; i < 27; i++){
        root -> ptr[i] = NULL;
    }
}
struct trienode* CreateEmptyTrieTree(int h){
    int i;
    struct trienode* root = NULL;
    root = malloc(sizeof(struct trienode));
    root -> layer = 0;
    root -> maxlayer = h;
    root ->nodekind = 0;
    for(i = 0; i < 27; i++){
        root -> ptr[i] = NULL;
        root ->num = 0;
    }
    return root;
}
void insert(struct trienode*root,char*s){
    struct trienode* p = NULL, *pre = NULL;
    int i = 0;
    p = root -> ptr[s[i++] - 'a' + 1];
    pre = root;
    while(p){
        if(p->nodekind == 1) break;
        pre = p;
        p ->num++;
        if(s[i])
            p = p -> ptr[s[i++] - 'a' + 1];
        else p = p -> ptr[s[i++]];
    }
    i--;
    if(pre -> layer == root -> maxlayer + 1) return;
    while(pre -> layer < root -> maxlayer){

        pre -> ptr[s[i] - 'a' + 1] = CreateEmptyTrieTree(root -> maxlayer);



        p = pre -> ptr[s[i++] - 'a' + 1];
        p -> num++;
        p -> layer = pre -> layer + 1;
        p -> nodekind = 0;
        pre = p;
    }
    if(s[i]){
        pre -> ptr[s[i] - 'a' + 1] = malloc(sizeof(struct trienode));
        p = pre -> ptr[s[i]- 'a' + 1];
    }
    else{
        pre -> ptr[s[i]] = malloc(sizeof(struct trienode));
        p = pre -> ptr[s[i]];
    }
    p -> nodekind = 1;
    p -> layer = 4;
    for(int j = 0;s[j]!=0;j++)
        p -> leafname[j] = s[j];
    return;
}
int tag = 1;
void PreOrderTraverse(struct trienode* root){
    if(root == NULL || root ->nodekind==1) return;
    if(root -> layer != 0){
        if(tag){
            printf("%d", root -> num);
            tag = 0;
        }else printf(",%d", root -> num);
    }
    for(int i = 0; i < 27; i++){
        PreOrderTraverse(root -> ptr[i]);
    }
}
void delete(struct trienode* root, char*s){
    struct trienode* p = NULL, *pre = NULL;
    int i = 0;
    p = root -> ptr[s[i++] - 'a' + 1];
    pre = root;
    while(p){
        if(p->nodekind == 1) break;
        pre = p;
        p ->num--;
        if(s[i])
            p = p -> ptr[s[i++] - 'a' + 1];
        else p = p -> ptr[s[i++]];
    }
    i--;
    if(pre -> layer == root -> maxlayer + 1) return;
    while(pre -> layer < root -> maxlayer){

        pre -> ptr[s[i] - 'a' + 1] = CreateEmptyTrieTree(root -> maxlayer);



        p = pre -> ptr[s[i++] - 'a' + 1];
        p -> num--;
        p -> layer = pre -> layer + 1;
        p -> nodekind = 0;
        pre = p;
    }
    if(s[i]){
        pre -> ptr[s[i] - 'a' + 1] = malloc(sizeof(struct trienode));
        p = pre -> ptr[s[i]- 'a' + 1];
    }
    else{
        pre -> ptr[s[i]] = malloc(sizeof(struct trienode));
        p = pre -> ptr[s[i]];
    }
    p -> nodekind = 1;
    p -> layer = 4;
    for(int j = 0;s[j]!=0;j++)
        p -> leafname[j] = s[j];
    return;
}
int main(){
    char s[100] = {0};
    struct trienode *root;
    root = malloc(sizeof(struct trienode));
    int h;
    scanf("%d",&h);
    getchar();
    Inittrietree(root,h);
    char temp[10];
    while(1){
        int lenth = numbersgetline(s);
        if(lenth!=0){
            insert(root,s);
            for(int i = 0;i<10;i++)temp[i] = s[i];
        }     
        else
            break;
    }
    delete(root,temp);
    delete(root,temp);
    if(h==4){
        for(int i = 2;i<27;i++){
            root->ptr[i] = NULL;
        }
    }
    PreOrderTraverse(root);
}