#include<stdio.h>
#include<stdlib.h>

#ifndef BASE
#define BASE
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int bool;
#endif

#define VertexType char //点类型
#define VRType int //边类型
#define maxSize 20
void Visit(VertexType e) {
	printf("%c", e);
}

#define MAX_VERTEX_NUM 20
typedef enum{DG, UDG} GraphKind;
typedef struct ArcNode{
	int adjV; //边指向的顶点
	VRType weight; //权重
	struct ArcNode *next;
}ArcNode; //边
typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;
    int mpl;
}VNode, AdjList[MAX_VERTEX_NUM]; //顶点
typedef struct{
	GraphKind kind;
	int vernum,arcnum;
	AdjList vers; 
}ALGraph;
int mpl[100];
void findmpl(ALGraph *G,VNode *v,int depth){
    ArcNode *arc = v->firstarc;
    for(arc;arc!=NULL;arc = arc->next){
        if(depth>mpl[arc->adjV]){
            mpl[arc->adjV] = depth;
        }
        findmpl(G,&(G->vers[arc->adjV]),depth+1);
    }
}
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n'&&c!=';';++i){
        if((c<='9'&&c>='0')&&c!=','){           
            if(c=='-')
                state = -1;
            else {
                if(number==0){
                    number += 1;
                    s[j++] = (c-'0')*state;  
                }
                else if(number!=0&&(c>='0'&&c<='9')){
                    number += 1;
                    int temp =s[j-1]*10+(c-'0')*state;
                    s[j-1] = temp;
                } 
            }   
        }
        else{
            number = 0;
            state = 1;
        } 
    }
    if(c=='\n'||c==';'){
        //s[j] = c;
        ++i;
    }
    //s[j] = '\0';
    return j;
}

Status InitGraph_AL(ALGraph *pG) { 
	int i;
	pG->arcnum = 0;
	pG->vernum = 0;
	for (i=0; i<MAX_VERTEX_NUM; ++i){
        pG->vers[i].firstarc = NULL; 
        pG->vers[i].mpl = 0;
    }
	return OK;
}
int LocateVex_AL(ALGraph G, VertexType e) {
	int i;
	for (i=1; i<=G.vernum; ++i) {
		if (G.vers[i].data == e) {
			return i;
		}
	}
	return -1;
}
int data[2];
Status CreateDG_AL(ALGraph *pG) { 
    numbersgetline(data);
    int line[100];
    int lenth;
    lenth = numbersgetline(line);
	int i,a,b;
	char tmp[MAX_VERTEX_NUM];
	char h,t;
	ArcNode *p, *q;

	InitGraph_AL(pG); 
	pG->kind = DG;
	pG->vernum = data[0];
	pG->arcnum = lenth/2;
	for (i=0; i<=pG->vernum; ++i) pG->vers[i].data=i;
	for (i=0; i<pG->arcnum; ++i) {
		h = line[2*i]; t = line[2*i+1];
		a = LocateVex_AL(*pG, h);
		b = LocateVex_AL(*pG, t);
		if (a<0 || b<0) return ERROR;
		p = (ArcNode *)malloc(sizeof(ArcNode)); if (!p) exit(OVERFLOW);
		p->adjV=b;p->next=NULL;
		if (pG->vers[a].firstarc) {
			for (q = pG->vers[a].firstarc; q->next; q=q->next) ; 
			q->next = p;
		} else { 
			pG->vers[a].firstarc = p;
		}
	}
	return OK;
}
int main() {
	ALGraph G;
	CreateDG_AL(&G);
    int print[100] = {0};
    for(int i = 1;i<=G.vernum;i++){
        for(int j = 0;j<100;j++)
            mpl[j] = 0;
        findmpl(&G,&(G.vers[i]),1);
        int max = 0;
        for(int j = 1;j<=G.vernum;j++){
            if(mpl[j]>max)
                max = mpl[j];
        }
        print[i] = max;
    }
    for(int i = 1;i<=G.vernum;i++){
        printf("%d",print[i]);
        if(i<G.vernum)
            printf(",");
    }

}