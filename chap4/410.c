#include<stdio.h>
int getline(char s[]);
int main(){
    char line[100];
    int i =getline(line);
    for(--i;i>=0;i--){
        printf("%c",line[i]);
    }
}
int getline(char s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}