#include<stdio.h>
#include<malloc.h>
#define MAXLEN 1000
struct node{
	char name;
	int male;
	int female;
	struct node *next;
};
int get_one_line(char s[]);
struct node* deal_line(struct node* head,char s[]);
void Display(struct node* head);
int main(){
	char c;
	char s[MAXLEN];
	struct node *head = malloc(sizeof(struct node)); 
	head=NULL;
	while(get_one_line(s)!=0){
		head=deal_line(head,s);
	}
	Display(head);
	return 0;
}
int get_one_line(char s[]){
	int i=0;
	char c;
	while((c=getchar())!='\n'&&c!=EOF){
		s[i++]=c;
	}
	if(i==0)
	return 0;
	s[i]='$';
	return 1;
}
struct node* deal_line(struct node* head,char s[]){
	struct node *now,*last;
	struct node a;
	now=head;
	while(now!=NULL&&now->next!=NULL){
		if(now->name==s[4])
		  break;
		now=now->next;
	}
	if(now==NULL||(now->next==NULL&&now->name!=s[4])||now==NULL){
		last=now;
		now=(struct node*)malloc(sizeof(a));
		now->name=s[4];
		now->male=now->female=0;
		if(head==NULL)
		  head=now;
		else;
		last->next=now;
		now->next=NULL;
	}
	int i,p;
	p=0;
	for(i=6;s[i]!='$';i++)
	  p=p*10+s[i]-'0';
	printf("end\n");
	if(s[2]=='F'){
		now->female+=p;
	}
	else
	    now->male+=p;
	    //for(now=head;now!=NULL;now=now->next)
	    //  printf("%c %d %d\n",now->name,now->male,now->female);
	   return head;
}
void Display(struct node* head){
	struct node *now=head;
	while(now->next!=NULL){
		if(now->male!=0)
		  printf("%c M %d\n",now->name,now->male);
		if(now->female!=0)
		  printf("%c F %d\n",now->name,now->female);
		printf("%c %d\n",now->name,now->male+now->female);
		now=now->next;
	}
		if(now->male!=0)
		  printf("%c M %d\n",now->name,now->male);
		if(now->female!=0)
		  printf("%c F %d\n",now->name,now->female);
		printf("%c %d",now->name,now->male+now->female);	
}
