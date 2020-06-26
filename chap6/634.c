#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree*L;
    struct tree*R;
};
int root;
int leaf1[2];
int leaf2[4];
int leaf3[8];
int leaf4[16];
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
int buildtree(int line[1000]){
            root = line[0];
            for(int j = 0;j<2;j++){
                leaf1[j] = line[j+1];
            }
            for(int j = 0;j<4;j++){
                leaf2[j] = line[j+3];
            }
            for(int j = 0;j<8;j++){
                leaf3[j] = line[j+7];
            }
            for(int j = 0;j<16;j++){
                leaf4[j] = line[j+15];
            }

    
}
void printtree(void){
    int line[1000] = {0};
    int i = 0;
    line[i++] = root;
    if(leaf1[0]!=0)
        line[i++] = leaf1[0];
    if(leaf2[0]!=0)
        line[i++] = leaf2[0];
    if(leaf2[1]!=0)
        line[i++] = leaf2[1];
    if(leaf1[1]!=0)
        line[i++] = leaf1[1];
    if(leaf2[2]!=0)
        line[i++] = leaf2[2];
    if(leaf2[3]!=0)
        line[i++] = leaf2[3];
    line[i] = leaf3[1];
for(int i = 0;i<1000&&line[i]!=0;i++){
    printf("%d",line[i]);
    if(line[i+1]!=0)
        printf(",");
}
}
int main(){
    int line[1000]={0};
    numbersgetline(line);
    buildtree(line);
    printtree();
}
