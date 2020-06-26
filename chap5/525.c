#include<stdio.h>
int line[1000];
int data[100][100];
int temp[1000];
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n';++i){
        if(c!=','&&c!='['&&c!=']'){
            if(c==';'){
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
int read(void){
    int w = line[1];
    int l = line[0];
    int x = 0;
    int y = 0;
    int z = 0;
    int a = 0;
    int b = 0;
    int state = 0;
    for(int i = 2;i<w*l+3;i++){
        if(line[i]!=0)
            temp[state++] = line[i];
            if(x<l)
                data[x][y++]= line[i];
            if(y==w){
                x++;
                y = 0;
            }
            if(x==l)
                break;
    }

    printf("[");
    for(int i = 0;temp[i]!=0;i++){
        printf("%d",temp[i]);
        if(temp[i+1]!=0)
            printf(",");
    }
    printf("];");
    printf("[");
    for(int i = 0;i<l;i++){
        printf("[");
        for(int j = 0;j<w;j++){
            printf("%d",data[i][j]==0?0:1);
            if(j<w-1)
                printf(",");
        }
        if(i<l-1)
            printf("];");
        else
        {
            printf("]");
        }
        
    }
    printf("]");
    


    
    

}
int main(){
    numbersgetline(line);
    read();
}