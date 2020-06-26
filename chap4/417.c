#include<stdio.h>
int getline(char s[]);
void replace(char s[],char t[],char k[]);
int getline(char s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n'&&c!=' ';++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}
void replace(char s[],char t[],char k[]){
    char result[100];
    int q = 0;
    int state = 0;
    for(int i = 0;s[i]!='\0';i++){
        if(s[i]!=t[0])
            result[q++] = s[i];
        else{
            int j = i;
            int l = 0;
            do{
                j++;
                l++;
            }while(s[j]==t[l]&&s[j]!='\0');
            if(t[l]=='\0'){
                for(l = 0;k[l]!='\0';l++)
                    result[q++] = k[l];
                i = j-1;
                state = 1;
            }
            else{
                result[q++] = s[i];
            }
        }
    }
    result[q] = '\0';
    if(state==1)
        printf("%s",result);
}
int main(){
    char s[100];
    char t[100];
    char k[100];
    getline(s);
    getline(t);
    getline(k);
    replace(s,t,k);
}