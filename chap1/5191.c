#include<stdio.h>
#define MAXLEN 1000
int main(){
    void HourseSaddle();
    HourseSaddle();
	return 0;
} 
void HourseSaddle(){
	int row,col,e,num;
	row=0;
	col=0;
	num=0;
	int i,j;
	i=j=0;
	int m[MAXLEN];
	char c;
	for(i=0;;i++){
		scanf("%d",&e);
		m[i]=e;
		num++;
		c=getchar();
		if(c==';'||c==EOF||c=='\n')
		  row++;
		if(c==EOF||c=='\n')
		  break;
	}
	int r,co;
	col=num/row;
	int M[row][col];
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
		  M[i][j]=m[i*col+j];
	}

	int saddle[row*col+1];
	saddle[0]=0;
	int s=1;
	int hourse=M[0][0];
	for(i=0;i<=row-1;i++){
        hourse=M[i][0];		
		for(j=0;j<=col-1;j++)
		  if(M[i][j]<hourse){
		  	hourse=M[i][j];
		}//i行最小值
		for(j=0;j<=col-1;j++){
		    if(M[i][j]==hourse){
		       	int flag=1;
		  	    for(int k=0;k<=row-1;k++)
		  	       if(M[k][j]>hourse)
		  	         flag=0;
			    if(flag==1){
			    	saddle[0]++;
			    	saddle[s++]=hourse;
				}
				  	  	    
			}
		}
	}
	if(saddle[0]==0)
	  printf("null");
	else{
		for(i=1;i<saddle[0];i++)
		  printf("%d,",saddle[i]);
		printf("%d",saddle[i]);
	}
}
