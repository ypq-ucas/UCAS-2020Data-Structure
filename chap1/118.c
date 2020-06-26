#include<stdio.h>
#define LIM 10
int getline(int s[]);
int main(){
    int Af,Am,Bf,Bm,Cf,Cm,Df,Dm,Ef,Em = 0;
    int data[2][5] = {0};
    //Af,Am,Bf,Bm,Cf,Cm,Df,Dm,Ef,Em
    int a,b,c,d;
    int line[10];
    getline(line);
    do{
        if(line[7]>='0'&&line[7]<='9')
            line[6] = (line[6]-'0')*10+line[7]-'0';
        else
        {
            line[6]-='0';
        }
        
        a = line[0];
        b = line[2];
        c = line[4];
        d = line[6];
        switch (c)
        {
        case 'A':
            if(b=='M'){
                data[0][0]+=d;
            }else{
                data[1][0]+=d;
            }
            break;
        case 'B':
            if(b=='M'){
                data[0][1]+=d;
            }else{
                data[1][1]+=d;
            }
            break;
        case 'C':
            if(b=='M'){
                data[0][2]+=d;
            }else{
                data[1][2]+=d;
            }
            break;
        case 'D':
            if(b=='M'){
                data[0][3]+=d;
            }else{
                data[1][3]+=d;
            }
            break;
        case 'E':
            if(b=='M'){
                data[0][4]+=d;
            }else{
                data[1][4]+=d;
            }
            break;
        }
    }while(getline(line)!=0);
    for(int i = 0;i<5;i++){
        for(int j = 0;j<2;j++){
            if(data[j][i]!=0){
                printf("%c %c %d\n",'A'+i,j==0?'M':'F',data[j][i]);
            }
        }
        if((data[0][i]+data[1][i])!=0)
                printf("%c %d\n",'A'+i,data[0][i]+data[1][i]);
    }
}
int getline(int s[]){
    int c,i;
    for(i = 0;i<LIM-1&&(c = getchar())!=EOF&&c!='\n';++i){
        s[i] = c;
    }
    if(c=='\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    if(c!=EOF)
        return 1;
    else{
        return 0;
    }
}
