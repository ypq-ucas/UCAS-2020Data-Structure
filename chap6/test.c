#include<stdio.h>
#include<stdlib.h>
int main(){
    int data;
    int times = 0;
    for(data = 0;data<127;data++){
        int line[7];
        int temp = data;
        for(int i = 0;i<7;i++){
            line[6-i] = temp%2;
            temp = temp/2;
        }
        for(int j = 0;j<1;j++){
            if(line[j]==0&&line[j+1]==0&&line[j+2]==0){
                times++;
            }
        }
    }
    printf("%d",times);
}
