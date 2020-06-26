#include<stdio.h>
int getline(int s[]);
int main(){
    int line[100];
    int a[100];
    int b[100];
    int c[100];
    int j = 0;
    int i,k;
    getline(line);
    for(i = 0;line[i]!=';';i++){
        if(line[i]!=',')
            a[j++] = line[i];
    }
    a[j] = '\0';
    j = 0;
    i++;
    for(i;line[i]!=';';i++){
        if(line[i]!=',')
            b[j++] = line[i];
    }
    b[j] = '\0';
    j = 0;
    i++;
    for(i;line[i]!='\0';i++){
        if(line[i]!=',')
            c[j++] = line[i];
    }
    c[j] = '\0';
    for(i = 0;a[i]!=0;i++){
        for(k = 0;b[k]!=0;k++){
            for(j = 0;c[j]!=0;j++){
                if(a[i]==b[k]&&b[k]==c[j])
                    a[i] = -1;
            }
        }
    }
    for(i = 0;a[i]!=0;i++){
        if(a[i]!=-1){
            printf("%c",a[i]);
        }
        break;
    }
    i++;
    for(i;a[i]!=0;i++){
        if(a[i]!=-1){
            printf(",%c",a[i]);
        }
    }
}
int getline(int s[]){
    int c,i;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}