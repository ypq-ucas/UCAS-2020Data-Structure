#include<stdio.h>
#define MAXLEN 1000
int main(){
    int row,col;
    row=col=0;
    char c;
   while(c=getchar()>='0'&&c<='9'){
   	 row=row*10+c-'0';
   }
   while(c=getchar()>='0'&&c<='9'){
   	 col=col*10+c-'0';
   }
   printf("%d %d",row,col);
    int num=0;
    int i,j;
    int A[row*col];
    int V[row*col];
    int B[row][col];

    for(i=0;i<row*col;i++){
    	int e=0;
      while(c=getchar()<'0'||c>'9')
       ;
      putchar(c);
      while(c=getchar()>='0'&&c<='9'){
    	e=e*10+c-'0';
      }
    	A[i]=e;
    	if(e!=0){
    	num++;
    	V[num-1]=e;
		}
	}
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
		 if(A[i*col+j]!=0)
		  B[i][j]=1;
		  else
		  B[i][j]=0;
	}
	printf("[");
	for(i=0;i<num;i++){
		if(i!=num-1)
		printf("%d,",V[i]);
		else
		printf("%d];",V[i]);
	}
	printf("[");
	for(i=0;i<row;i++){
	   printf("[");
	   for(j=0;j<col;j++)
		if(j!=col-1)
		printf("%d,",B[i][j]);
		else
		printf("%d];",B[i][j]);
	}
	printf("]");
	return 0;
} 
