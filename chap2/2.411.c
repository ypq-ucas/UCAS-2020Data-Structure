#include<stdio.h>
#include<malloc.h>
#define MAXLEN 10000
struct node{
	int coef;
	int expo;
	struct node *next;
};
void Derivative(struct node* head);
struct node* InputPoly();
void PolyDisplay(struct node* head);
int main(){
	struct node *point;
	point=InputPoly();
	Derivative(point);
	PolyDisplay(point);
	return 0;
}
struct node* InputPoly(){
	char poly[MAXLEN];
	char c;
	int len,num,item;
	int i,j;
	item=i=0;
	while((c=getchar())!='\n'&&c!=EOF){
		if(c!=' ')
		poly[i++]=c;
		if(c=='+'||c=='-')
		  item++;
	}
	poly[i]='e';
	if(poly[0]!='-')
	item++;
	struct node a;
	struct node *head,*pre,*now;
	now=pre=head=(struct node*)malloc(sizeof(a));
	head->coef=head->expo=item;
	head->next=NULL;
	for(;item>0;item--){
		now=(struct node*)malloc(sizeof(a));
		now->coef=1;
		now->expo=0;
		now->next=NULL;
		pre->next=now;
		pre=now;
	}
	now=head->next;
	len=i-1;
	char sign;
	for(i=0;now!=NULL;i++){
	    if(poly[i]=='+'||poly[i]=='-'){
	    	sign=poly[i];
	    	if(poly[++i]=='x'){
	    	  now->coef=(sign=='+')?1:-1;
	    	    if(poly[++i]=='^'){
	    	    	num=0;
	    	    	while(poly[++i]>='0'&&poly[i]<='9')
	    	    	  num=num*10+poly[i]-'0';
	    	    	now->expo=num;
	    	    	i--;
				}
				else{
					i--;
					now->expo=1;
				} 
	        }//coef is 1 or -1
	        else{
                    num=0;
                    i--;
	    	    	while(poly[++i]>='0'&&poly[i]<='9')
	    	    	  num=num*10+poly[i]-'0';
					now->coef=(sign=='+')?num:-num;
					i--;
					if(poly[++i]=='x'){
						if(poly[++i]=='^'){
	    	    	      num=0;
	    	    	      while(poly[++i]>='0'&&poly[i]<='9')
	    	    	      num=num*10+poly[i]-'0';
	    	    	      now->expo=num;
						  i--;							
						}
						else{
						  i--;
						  now->expo=1;
					   }
					}
					else{
						i--;
						now->expo=0;
					}	        	
			}  
		}
		else if(poly[i]=='x'){
			now->coef=1;
            if(poly[++i]=='^'){
	    	    num=0;
	    	    while(poly[++i]>='0'&&poly[i]<='9')
	    	    	num=num*10+poly[i]-'0';
	    	    now->expo=num;	
				i--;						
			}
			else{
				i--;
				now->expo=1;
				}			
		}
		else{
            num=0;
            i--;
	    	while(poly[++i]>='0'&&poly[i]<='9')
	    	    num=num*10+poly[i]-'0';
			now->coef=num;
			i--;	
	    	if(poly[++i]=='x'){
	    	    if(poly[++i]=='^'){
	    	    	num=0;
	    	    	while(poly[++i]>='0'&&poly[i]<='9')
	    	    	  num=num*10+poly[i]-'0';
	    	    	now->expo=num;
	    	    	i--;
				}
				else{
					i--;
					now->expo=1;
				} 
	        }//coef is 1 or -1
	        else{
                    now->expo=0;
                    i--;
		   }
		}
		now=now->next;	
	}
	return head;
}
void Derivative(struct node* head){
	struct node *now,*pre,*to_delete,*con;
	pre=to_delete=head;
	now=head->next;

	while(now!=NULL){
		if(now->expo!=0){
			now->coef=now->coef*now->expo;
			now->expo=now->expo-1;
			pre=now;
			now=now->next;
		}
		else{
			to_delete=now;
			now=now->next;
			pre->next=now;
			free(to_delete);
		}	 
	}

}

void PolyDisplay(struct node* head){
	struct node *now;
	now=head->next;
	int i=20,j=0;
	while(i>=0){
		int coe=0;
		for(now=head->next;now!=NULL;now=now->next)
		  if(now->expo==i)
		    coe+=now->coef;
		if(coe>0){
		  if(coe!=1)
            printf("+%d",coe);
          else if(i==0)
            printf("%d",coe);
          else
            ;
        }
        else if(coe<0){
		  printf("%d",now->coef);
          if(i>1)
            printf("x^%d",now->expo);
          else if(i==1)
            printf("x");
          else
          ;
        }
        else
         j++;
        i--; 
   }
}
