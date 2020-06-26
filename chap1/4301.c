#include<stdio.h>
#include<malloc.h>
#define MAXLEN 100000
int main(){
   char s[MAXLEN];
   void BuildString(char s[]);
   BuildString(s);
   void RepeatString(char s[]);
   RepeatString(s);
   return 0;
}
void BuildString(char s[]){
    char c;
    s[0]=0;
    int i=1;
    while((c=getchar())!=EOF&&c!='\n'){
        s[i++]=c;
        s[0]++;
    }
}
void RepeatString(char s[]){
	int i,j,k,p,maxlen;
	for(maxlen=0,i=1;i<s[0];i++){
		for(k=0,j=1;j<=s[0]-i;j++){
			if(s[j]==s[j+i])
			  k++;
			else
			  k=0;
			if(k>maxlen){
				p=j-k+1;
				maxlen=k;
			}
		}
	}
	if(maxlen>0){
		for(i=p;i<p+maxlen;i++)
		  printf("%c",s[i]);
		printf(" %d",p-1);
	}
	else
	  printf("-1");
}
