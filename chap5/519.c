#include<stdio.h>
int store[1000][1000];
int result[10];
int line[20000];
int numbersgetline(int s[]);
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n';++i){
        if(c!=','){
            if(c==';'){
                s[j++] = -1;
                number = 0;
                state = 1;
            }
                
            else if(c=='-')
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
    if(c=='\n'){
        s[j] = c;
        ++i;
    }
    s[j] = '\0';
    return j;
}
int min(int target,int i,int lenth){
    int state = 1;
    for(int j = 0;j<lenth;j++){
        if(target>store[i][j]){
            return 0;
        }
    }
    return 1;
}
int max(int target,int j,int hight){
    for(int i = 0;i<hight;i++){
        if(target<store[i][j]){
            return 0;
        }
    }
    return 1;
}
int main(){
    numbersgetline(line);
    int j = 0;
    int k = 0;
    int hight;
    int lenth;
    for(int i = 0;line[i]!=0;i++){
        if(line[i]!=-1){
            store[j][k++] = line[i];
        }else{
            j++;
            k = 0;
        }
    }
    hight = j+1;
    lenth = k;
    int p = 0;
    for(int i = 0;i<hight;i++){
        for(j = 0;j<lenth;j++){
            if(min(store[i][j],i,lenth)&&max(store[i][j],j,hight)){
                result[p++] = store[i][j];
            }
        }
    }
    int i;
    for(i =0;result[i]!=0;i++){
        printf("%d",result[i]);
        if(result[i+1]!=0)
            printf(",");
    }
    if(i==0){
        printf("NULL");
    }
}