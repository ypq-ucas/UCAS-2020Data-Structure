#include<stdio.h>
#include<stdlib.h>
int getline(char s[]);
void cmp(char sline[],char tline[],int data[]);
void cmp(char sline[],char tline[],int data[]){
    for(int i = 0;sline[i]!=0;i++){
        int temp = i;
        int j =0;
        while(sline[temp]==tline[j]&&tline[j]!=0){
            temp++;
            j++;
        }
        if(tline[j]=='\0'){
            *(data++) = i+1;
            i = temp-1;
        }
    }
    *data = -1;
}
int getline(char s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}
void found(char s[],char t[]){
    int data[10];
    int lenth1 = 0;
    int lenth2 = 0;
    char target[100];
    target[0] = 0;
    for(int i = 0;s[i+1]!=0;i++){
        for(int j = i;s[j]!=0;j++){
            char line[100];
            int l = 0;
            lenth2 = j-i+1;
            for(int k = i;k<=j;k++){
                line[l++] = s[k];
            }
            line[l] = 0;
            cmp(s,line,data);
            if(data[1]!=-1&&data[0]!=-1){
                if(lenth2>lenth1){
                    int u;
                    for(u = 0;line[u]!=0;u++){
                        target[u] = line[u];
                    }
                    target[u++] = 0;
                    lenth1 = lenth2;
                }
                    
        }
    }
}
if(lenth1>1){
    printf("%s",target);
    cmp(s,target,data);
    printf(" %d",data[0]-1);
}
else{
    printf("-1");
}
}

int main(){
    char s[100];
    char t[100];
    getline(s);
    found(s,t);
}