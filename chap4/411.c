#include<stdio.h>
int getline(char s[]);
void found(char s1[],char s2[]);
int getline(char s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n'&&c!=' ';++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}
void found(char s1[],char s2[]){
    char new1[100] = {'\0'};
    int new2[100];
    for(int i =0;i<100;i++)
        new2[i]=-1;
    int k = 0;
    int m = 0;
    for(int i = 0;s1[i]!='\0';i++){
        int state = 0;
        for(int j = 0;s2[j]!='\0';j++){
            if(s1[i]==s2[j])
                state = 1;
                //是否在另外一个串中出现
        }
        if(state==0){
            for(int l = 0;new1[l]!='\0';l++){
                if(new1[l]==s1[i])
                    state = 1;
            }
        }
        if(state==0){
            new1[k++] = s1[i];
            new2[m++] = i;
        }
            
            
    }
    if(new2[0]==-1){
            printf("-1");
        }    
        else{
            printf("%s",new1);
            printf(" ");
            for(int i = 0;new2[i]!=-1;i++){
                printf("%d",new2[i]);
            }
        }
}
int main(){
    char s1[100];
    char s2[100];
    getline(s1);
    getline(s2);
    found(s1,s2);
}