#include <stdio.h>
#include <stdlib.h>
struct Stack{
    ElemType stack[100];
    ElemType *top;
};
typedef struct{
int x;
int y;
}PosType;
typedef struct{
int Color;
int Visited;
PosType seat;
}ElemType;
#define M 8
#define N 8
ElemType g[M][N];
void InitStack(struct Stack stack);
void CreateGDS(ElemType g[M][N]);
void ShowGraphArray(ElemType g[M][N]);
void RegionFilling(ElemType g[M][N],PosType CurPos,int NewColor);
int main()
{
CreateGDS(g);
ShowGraphArray(g);
PosType StartPos;
StartPos.x=5;
StartPos.y=5;
int FillColor=6;
RegionFilling(g,StartPos,FillColor);
ShowGraphArray(g);
return 0;
}
void InitStack(struct Stack stack){
    stack.top = stack.stack;
}
int Stackempty(struct Stack stack){
    if(stack.stack==stack.top)
        return 1;
    else
        return 0;
    
}
void push(struct Stack s,ElemType g){
    (*s.top++) = g;
}
void pop(struct  Stack s,ElemType e){
    e = *(--s.top);
}
void RegionFilling(ElemType g[M][N],PosType CurPos,int FillColor)
{
struct Stack s;
InitStack(s);
ElemType e;
int OldColor=g[CurPos.x][CurPos.y].Color;
Push(s,g[CurPos.x][CurPos.y]);
while(!StackEmpty(s)){
Pop(s,e);
CurPos=e.seat;
g[CurPos.x][CurPos.y].Color=FillColor;
g[CurPos.x][CurPos.y].Visited=1;
if(CurPos.x<M &&
!g[CurPos.x+1][CurPos.y].Visited &&
g[CurPos.x+1][CurPos.y].Color==OldColor
)
Push(s,g[CurPos.x+1][CurPos.y]);
if(CurPos.x>0 &&
!g[CurPos.x-1][CurPos.y].Visited &&
g[CurPos.x-1][CurPos.y].Color==OldColor
)
Push(s,g[CurPos.x-1][CurPos.y]);
if(CurPos.y<N &&
!g[CurPos.x][CurPos.y+1].Visited &&
g[CurPos.x][CurPos.y+1].Color==OldColor
)
Push(s,g[CurPos.x][CurPos.y+1]);
if(CurPos.y>0 &&
!g[CurPos.x][CurPos.y-1].Visited &&
g[CurPos.x][CurPos.y-1].Color==OldColor
)
Push(s,g[CurPos.x][CurPos.y-1]);
}
}
void CreateGDS(ElemType g[M][N])
{
int i,j;
for(i=0;i<M;i++)
for(j=0;j<N;j++){
g[i][j].seat.x=i;
g[i][j].seat.y=j;
g[i][j].Visited=0;
g[i][j].Color=0;
}
for(i=2;i<5;i++)
for(j=2;j<4;j++)
g[i][j].Color=3;
for(i=5;i<M-1;i++)
for(j=3;j<6;j++)
g[i][j].Color=3;
}
void ShowGraphArray(ElemType g[M][N])
{
int i,j;
for(i=0;i<M;i++){
for(j=0;j<N;j++)
printf("%d",g[i][j].Color);
printf(" ");
}
}
