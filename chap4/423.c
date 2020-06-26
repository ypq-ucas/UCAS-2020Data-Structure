#include<stdio.h>
int getline(char s[]);
int main(){
    char line[100];
    int i = getline(line);
    for(int j =0;j<i;j++){
        if(line[j]==line[i-1-j])
            ;
        else{
            printf("No");
            return 0;
        }

        
    }
    printf("Yes");
}
int getline(char s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}