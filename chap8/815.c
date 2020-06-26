#include<stdio.h>
int main(){
    int lowbound,highbound,cellsize;
    scanf("%d %d %d",&lowbound,&highbound,&cellsize);
    int c;
    int a;
    int start = lowbound;
    int start1 = lowbound;
    int lenth = 0;
    int pre;
    int result = 1;
    int rresult = 0;
    while((c = scanf("%d",&a))!=-1){
        result = result&a;
        rresult = rresult|a;
        if(a==0){
            lenth+=cellsize;
            start1 +=cellsize;
        }
        else if(a==1){
            if(lenth!=0)
                printf("%d %d %d\n",0,start,lenth);
            start = start1;
            lenth = 0;
            start+=cellsize;
            start1+=cellsize;
        }
    }
    if(rresult==0){
        printf("%d %d %d",0,lowbound,highbound);
    }
    if(result==1)
        printf("0 0 0");
}