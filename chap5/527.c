#include<stdio.h>
int a[100][100];
int b[100][100];
int line[10000];
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n';++i){
        if(c!=','&&c!='['&&c!=']'&&c!='+'){
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
    int state = 0;
    int i;
    for(i = 2;i<w*l+3;i++){
            if(x<l)
                a[x][y++]= line[i];
            if(y==w){
                x++;
                y = 0;
            }
            if(x==l)
                break;
    }
    x = 0;
    y = 0;
    for( i  = i+1;i<2*w*l+8;i++){
            if(x<l)
                b[x][y++]= line[i];
            if(y==w){
                x++;
                y = 0;
            }
            if(x==l)
                break;
    }

    for(i = 0;i<l;i++){
        for(int j = 0;j<w;j++){
            a[i][j]+=b[i][j];
        }
    }

    printf("[");
    for(int i = 0;i<l;i++){
        printf("[");
        for(int j = 0;j<w;j++){
            printf("%d",(a[i][j]));
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