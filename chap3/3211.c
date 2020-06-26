#include<stdio.h>
#define MAXLEN 1000 
struct stack{
	char string[MAXLEN];
	int top;
};
void PushStack(struct stack *p1,char c){
	p1->string[p1->top]=c;
	p1->top+=1;
	p1->string[p1->top]='\0';	
}
char PopStack(struct stack *p1){
	char c;
	p1->top-=1;
	c=p1->string[p1->top];
	p1->string[p1->top]='\0';
	return c;
}
void Polland(struct stack *p1){
	char c;
	while((c=getchar())!=EOF&&c!='\n'){
      if(c<='z'&&c>='A'){
      	printf("%c",c); 
	  }
	  else if(c=='(')
      	PushStack(p1,c);
	  else if(c==')'){
	  	char out;
	  	while((out=PopStack(p1))!='(')
	  	  printf("%c",out);
	  } 
	  else{
	  	if(c=='+'||c=='-'){
	  		if(p1->string[(p1->top-1)]=='(')
	  		  PushStack(p1,c);
	  		else{
	  			while(p1->string[(p1->top-1)]!='('&&p1->top!=0){
	  				char out;
	  				out=PopStack(p1);
	  				printf("%c",out);
				  }
				PushStack(p1,c);
			  }
		  }
		else{
			if(p1->string[(p1->top-1)]=='*'||p1->string[(p1->top-1)]=='/'){
	  			while(p1->string[(p1->top-1)]!='('&&p1->string[(p1->top-1)]!='+'&&p1->string[(p1->top-1)]!='-'&&p1->top!=0){
	  				char out;
	  				out=PopStack(p1);
	  				printf("%c",out);
				  }
				PushStack(p1,c);				
			}
			else
	  		  PushStack(p1,c);
		}
	  }	  
	}
	if(p1->top!=0){
		while(p1->top!=0){
			char c;
			c=PopStack(p1);
			printf("%c",c);
		}
	}	
}
int main(){
	struct stack s1;
	s1.top=0;
	struct stack *p1=&s1;
	char c;
	Polland(p1);
    return 0;
}
