#include<stdio.h>
int getline(int s[]);
int compare(int a[],int b[]);
int main(){
    int line[100];
    int a[50];
    int b[50];
    getline(line);
    int state= 0;
    int ai = 0;
    int bi = 0;
    for(int i = 0;line[i]!='\0';i++){
        if(line[i]!=';'&&state == 0){
            if(line[i]!=',')
                a[ai++] = line[i];
        }
        else if(line[i]==';')   
            state = 1;
        else if(state==1){
            if(line[i]!=',')
                b[bi++] = line[i];
        }
    }
    a[ai] = '\0';
    b[bi-1] = '\0';
    printf("%d",compare(a,b));
}
int getline(int s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        s[i] = c;
    }
    if(c=='\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
int compare(int a[],int b[]){
    int i;
    for(i = 0;a[i]!='\0'&&b[i]!='\0';i++){
        if(a[i]>b[i])
            return 2;
        else if(a[i]<b[i])
            return 1;
    }
    if(a[i]!='\0')
        return 2;
    else if(b[i]!='\0')
    {
        return 1;
    }
    else 
        return 0;
    

}