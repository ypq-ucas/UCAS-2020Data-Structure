#include<stdio.h>
#include<stdlib.h>
struct mem{
    int tag;
    int begin;
    int lenth;
};
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n'&&c!=';';++i){
        if(c<='9'&&c>='0'){           
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
int main(){
    int data[3];
    struct mem *line[100];
    for(int i = 0;i<100;i++){
        line[i] = malloc(sizeof(struct mem));
    }
    int i = 0;
    int lenth = 0;
    while(scanf("%d %d %d",data,data+1,data+2)!=EOF){
        if(data[0]==1){
            int j = 0;
            for(j = 0;j<i;j++){
                if(data[1]<=line[j]->begin&&((data[1]+data[2])>=(line[j]->begin))&&(data[1]+data[2])<=(line[j]->begin+line[j]->lenth)){
                    line[j]->lenth = line[j]->lenth+line[j]->begin-data[1];
                    line[j]->begin = data[1];
                    break;
                }
                else if(data[1]<=line[j]->begin&&((data[1]+data[2])>=(line[j]->begin))&&(data[1]+data[2])>=(line[j]->begin+line[j]->lenth)){
                    line[j]->lenth = data[1]+data[2]-line[j]->begin;
                    line[j]->begin = data[1];
                }
            }
            if(j==i){
                line[j]->begin = data[1];
                line[j]->lenth = data[2];
                line[j]->tag = 0;
                i++;
            }
        }
        if(data[0]==0){
            line[i]->tag = 0;
            line[i]->lenth = data[2];
            line[i++]->begin = data[1];
        }
    }
    for(int j = i-1;j>=0;j--){
        for(int k = j;k>0;k--){
            if(line[k]->begin<line[k-1]->begin){
                struct mem temp;
                temp.begin = line[k]->begin;
                temp.lenth = line[k]->lenth;
                temp.tag = 0;
                line[k]->begin = line[k-1]->begin;
                line[k]->lenth = line[k-1]->lenth;
                line[k-1]->begin = temp.begin;
                line[k-1]->lenth = temp.lenth;   
            }
        }
    }
    for(int j = 1;j<i;j++){
        int lenth = line[0]->begin+line[0]->lenth;
        if(line[j]->begin<=lenth){
            line[j]->tag = 1;
            line[0]->lenth = line[j]->begin+line[j]->lenth-line[0]->begin;
        }
    }
    
    for(int j = 0;j<i;j++){
        if(line[j]->tag==0)
            printf("%d %d %d\n",line[j]->tag,line[j]->begin,line[j]->lenth);
    } 
    int a;
}
