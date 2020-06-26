#include<stdio.h>
int numbersgetline(int s[]);
void delete(int line[],int l,int i);
int main(){
    int line[100];
    int l,location;
    numbersgetline(line);
    l = line[0];
    location = line[1];
    numbersgetline(line);
    if(l>1){
        delete(line,l,location);
        for(int i = 0;i<l-1;i++){
            printf("%d",line[i]);
            if(i<l-2)
                printf(" ");
        }
    }else
    {
        printf("NULL");
    }
    
}
void delete(int line[],int l,int i){
    int j;
    for(j = i;j<l;j++){
        line[j] = line[j+1];
    }
}
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;i<99-1&&(c = getchar())!=EOF&&c!='\n';++i){
        if(c!=' '){
            if(c=='-')
                state = -1;
            else {
                if(number==0){
                    number = 1;
                    s[j++] = (c-'0')*state;  
                }
                else if(number==1&&(c>='0'&&c<='9')){
                    number = 0;
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