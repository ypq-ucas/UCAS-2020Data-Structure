#include<stdio.h>
void qjs(int s[],int n,int x);
//int getline(int s[]);
//int turn(int s[],int t[]);
int main(){
    int n,x;
    int s[200];
    //getline(s);
    //n = s[0];
    //x = s[2];
    scanf("%d %d",&n,&x);
    //getline(s);
    int t[10];
    scanf("%d %d %d %d %d %d %d %d %d %d",t,t+1,t+2,t+3,t+4,t+5,t+6,t+7,t+8,t+9);
    //turn(s,t);
    /*for(int i =0;i<10;i++)
        printf("%d ",t[i]);
    for(int i =0;i<10;i++)
        printf("%d ",s[i]);*/
    qjs(t,n,x);
    
}
void qjs(int s[],int n,int x){
    int sum = s[n-1];
    for(int i = n-1;i>=1;i--){
        sum*=x;
        sum+=s[i-1];
    }
    printf("%d\n",sum);
}
int turn(int s[],int t[]){
    int state = 0;
    int pos = 1;
    int j = 0;
    for(int i =0;i<10;i++)
        printf("%d ",t[i]);
    printf("\n\n");
    for(int i =0;i<10;i++)
        printf("%d ",s[i]);
    /*for(int i = 0;i<200;i++){
        if(s[i]!=' '){
            if(s[i] = '-'){
                pos = -1;
            }
            else if(state = 0){
                t[j] = pos*s[i];
                state = 1;
            }
            else if(state = 1){
                t[j]*=10;
                t[j]+=s[i]*pos;
            }
        }else{
            state = 0;
            pos = 1;
        }
    }*/
}
int getline(int  s[]){
    int c,i;
    int state = 1;
    for(i = 0;i<99&&(c = getchar())!=EOF&&c!='\n';i++){
        s[i] = c;
    }
    if(c=='\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    if(c!=EOF)
        return 1;
    else
    {
        return 0;
    }
    
}