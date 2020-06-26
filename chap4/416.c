#include<stdio.h>
int getline(char s[]);
int compare(char s1[],char s2[]);
int getline(char s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n'&&c!=' ';++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}
int compare(char s1[],char s2[]){
    for(int i = 0;s1[i]!='\0'||s2[i]!='\0';i++){
        if(s1[i]>s2[i])
            return 1;
        else if(s1[i]<s2[i])
            return -1;
    }
    return 0;
}
int main(){
    char s1[100] = {'\0'};
    char s2[100] = {'\0'};
    getline(s1);
    getline(s2);
    printf("%d",compare(s1,s2));
}