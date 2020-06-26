#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *pre;
	struct node *next;
	int freq;
}; 
struct node* Locate(struct node *head, int x){
	struct node *now;
	now=head;
	int n,m;
	while(now->data!=x&&now!=NULL)
	  now=now->next;
	if(now!=NULL)
	now->freq+=1;
	return now;
	//printf("a\n");
    //AdjustOrder(head);
  //  void ListDisplay(struct node *head);
	//ListDisplay(head);  
	//printf("\n");
}
void AdjustOrder(struct node *head,int s[]){
	struct node *p,*q;
    for(p=head;p!=NULL;p=p->next)
      for(q=p->next;q!=NULL;q=q->next){
      	if(p->freq<q->freq||(p->freq==q->freq&&s[(p->data)]>s[(q->data)])){
      		int a,b;
      		a=p->freq;
      		p->freq=q->freq;
      		q->freq=a;
      		b=p->data;
      		p->data=q->data;
      		q->data=b;
		  }
      	  
	  }
}
/*struct node* AdjustOrder2(struct node *head,struct node *now,int s[]){
	if(now==head){
	 return head;
	}

	struct node *last;
	for(last=now->pre;!(last==NULL||last->freq>=now->freq);last=last->pre);
	if(last==NULL){
		(now->pre)->next=now->next;
	    now->pre=NULL;
		now->next=head;
		return now; 
	}
	else if(last->freq==now->freq&&s[last->data]>s[now->data]){
		for(last=last->pre;!(s[last->data]<s[now->data]||last->freq>now->freq||last==NULL);last=last->pre) ;
		if(last!=NULL){
	   (now->pre)->next=now->next;
	   now->next=last->next;
	   now->pre=last;
	   last->next=now; 	   		
		}
		else{
		(now->pre)->next=now->next;
	    now->pre=NULL;
		now->next=head;
		return now; 			
		}
	}	
	else if (last==now->pre){
		return head;
	}

	else{
	   (now->pre)->next=now->next;
	   now->next=last->next;
	   now->pre=last;
	   last->next=now; 
	}
	return head;
}*/
void ListDisplay(struct node *head){
	struct node *now;
	now=head;
	while(now->next!=NULL){
		printf("%d ",now->data);
		now=now->next;
	}
	printf("%d",now->data);
}
struct node* BuildList(int len){
	struct node *head,*last,*now,*end;
	int num;
	scanf("%d",&num);
	struct node a;
	last=head=now=(struct node*)malloc(sizeof(a));
	head->next=head->pre=NULL;
	head->freq=0;
	head->data=num;	
	len--;
	while(len>0){
		scanf("%d",&num);
		last=now;
		now=(struct node*)malloc(sizeof(a));
		now->data=num;
		now->freq=0;
		now->next=NULL;
		now->pre=last;
		last->next=now;
		len--;
	}
	return head;
}

int main(){
	struct node *point,*now;
	int len,f;
	f=1;
	scanf("%d",&len);
	point=BuildList(len);
	int a;
	int i=0;
    int s[100];
    for(i=0;i<100;i++)
    s[i]=10000;
	char c;
	c=getchar();
	do{
		c=getchar();
		a=c-'0';
		do{
			c=getchar();			
			if(c>='0'&&c<='9')
			 a=10*a+c-'0';
		}while(c!=' '&&c!=EOF&&c!='\n');
		if(s[a]==10000)
		s[a]=f++;
		now=Locate(point,a);
       // point=AdjustOrder2(point,now,s);
        //	ListDisplay(point);
 
	}while(c!=EOF&&c!='\n');
    AdjustOrder(point,s);
	ListDisplay(point);
	return 0;
}
