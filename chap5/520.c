#include <stdio.h>
int data[100][100][100];
int line[100000];
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
    int demention = line[0];
    int l = line[1];
    int x = 0;
    int y = 0;
    int z = 0;
    int a = 0;
    int b = 0;
    for(int i = 2;i<l*l*l+3;i++){
        if(demention==1){
            if(x<l){
                data[x++][0][0] =line[i]; 
            }
            if(x==l)
                break;
        }
        if(demention==2){
            if(y<l)
                data[x][y++][0] = line[i];
            if(y==l){
                x++;
                y = 0;
            }
            if(x==l)
                break;
        }
        else if(demention==3){
            if(x<l&&y<l&&z<l){
                data[x][y][z++]= line[i];
            }
            if(z==l){
                y++;
                z= 0;
            }
            if(y==l){
                x++;
                y = 0;
            }
            if(x==l)
                break;
        }
    }
    int state = 0;
    for(x = l-1;x>=0;x--){
        for(y = l-1;y>=0;y--){
            for(z = l-1;z>=0;z--){
                if(data[x][y][z]!=0){
                    if(state==1){
                        if(data[x][y][z]>0)
                            printf("+");
                        else if(data[x][y][z]<0)
                            printf("-");
                    }
                    state = 1;
                    if(data[x][y][z]!=1&&(x!=0||y!=0||z!=0))
                        printf("%d",data[x][y][z]);
                    else if(x==0&&y==0&&z==0)
                        printf("%d",(data[x][y][z]>0?data[x][y][z]:-data[x][y][z]));

                    if(x==0)
                        ;
                    else if(x==1){
                        printf("x1");
                    }
                    else if(x!=1){
                        printf("x1E%d",x);
                    }

                    if(y==0)
                        ;
                    else if(y==1){
                        printf("x2");
                    }
                    else if(y!=1){
                        printf("x2E%d",y);
                    }

                    if(z==0)
                        ;
                    else if(z==1){
                        printf("x3");
                    }
                    else if(z!=1){
                        printf("x3E%d",z);
                    }
                }
                    
            }
        }
    }

}
int main(){
    numbersgetline(line);
    int a;
    read();
}