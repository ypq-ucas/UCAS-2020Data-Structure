#include <stdio.h>
#include <stdlib.h>
#define MAXKEYLEN 100

typedef struct{
    char ch[MAXKEYLEN];     //关键词字符串
    int num;                //关键词长度
}KeysType;
typedef enum{LEAF, BRANCH} NodeKind;
typedef struct TrieNode{
    NodeKind kind;
    int layer;
    int maxlayer;
        KeysType* lf;                   //叶子节点
        struct {                      
            struct TrieNode *ptr[27];   
            int num;                    //此节点经过多少个关键词                       
    };
}TrieNode, *TrieTree;

KeysType* GetKey();
TrieTree TrieAlloc();
TrieTree CreateEmptyTrieTree(int h);
void InsertKey(TrieTree root, KeysType *key);
void PreOrderTraverse(TrieTree root, void (*Visit)(TrieTree tree));
void PrintVisitedNum(TrieTree tree);

int firstelem = 1;

int main(){
    KeysType *key = NULL;           //关键词
    TrieTree root = NULL;           //根节点
    int h;                          //树层次
    scanf("%d", &h);      
    getchar();          
    root = CreateEmptyTrieTree(h);        //在根节点上创建空Trie树
    while(key = GetKey()){
        InsertKey(root, key);
    }
    PreOrderTraverse(root, PrintVisitedNum);
}

TrieTree CreateEmptyTrieTree(int h){
    int i;
    TrieTree root = NULL;
    root = TrieAlloc();
    root -> layer = 0;
    root -> maxlayer = h;
    root -> kind = BRANCH;
    for(i = 0; i < 27; i++){
        root -> ptr[i] = NULL;
        root ->num = 0;
    }
    return root;
}
void InsertKey(TrieTree root, KeysType *key){
    TrieTree p = NULL, pre = NULL;
    int i = 0;
    p = root -> ptr[key -> ch[i++] - 'a' + 1];
    pre = root;
    while(p){
        if(p -> kind == LEAF) break;
        pre = p;
        p ->num++;
        if(key -> ch[i])
            p = p -> ptr[key -> ch[i++] - 'a' + 1];
        else p = p -> ptr[key -> ch[i++]];
    }
    i--;
    if(pre -> layer == root -> maxlayer + 1) return;
    while(pre -> layer < root -> maxlayer){
        int temp = key -> ch[i] - 'a' + 1;
        pre -> ptr[key -> ch[i] - 'a' + 1] = CreateEmptyTrieTree(root -> maxlayer);
        p = pre -> ptr[key -> ch[i++] - 'a' + 1];
        p -> num++;
        p -> layer = pre -> layer + 1;
        p -> kind = BRANCH;
        pre = p;
    }
    if(key -> ch[i]){
        pre -> ptr[key -> ch[i] - 'a' + 1] = TrieAlloc();
        p = pre -> ptr[key -> ch[i++] - 'a' + 1];
    }
    else{
        pre -> ptr[key -> ch[i]] = TrieAlloc();
        p = pre -> ptr[key -> ch[i++]];
    }
    p -> kind = LEAF;
    p -> layer = 4;
    p -> lf = key;
    return;
}
void PreOrderTraverse(TrieTree root, void (*Visit)(TrieTree tree)){
    if(root == NULL || root -> kind == LEAF) return;
    int i;
    Visit(root);
    for(i = 0; i < 27; i++){
        PreOrderTraverse(root -> ptr[i], Visit);
    }
}
void PrintVisitedNum(TrieTree tree){
    if(tree -> layer == 0) return;
    if(firstelem){
        printf("%d", tree -> num);
        firstelem = 0;
    }else printf(",%d", tree -> num);
}
KeysType* GetKey(){
    char c;
    KeysType* key = (KeysType *)malloc(sizeof(KeysType));
    key -> ch[0] = 0;
    key -> num = 0;
    int i = 0;
    while((c = getchar()) != EOF){
        if(c == ';' || c == '\n')
            return key -> ch[0] == 0 ? NULL : key;
        if(c >= 'a' && c <= 'z'){
            key -> ch[i++] = c;
            key -> ch[i] = 0;
            key -> num ++;
        }
    }
    return NULL;
}
TrieTree TrieAlloc(){
    return (TrieTree)malloc(sizeof(TrieNode));
}