#include<stdio.h>
#include<stdlib.h>
 int a[10][17]={{0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0},

                {0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0},

                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                                 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                                 {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},

                                 {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},

                                 {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},

                                 {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},

                                 {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}};



          int b[8][17]={{0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0},

                                 {0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0},

                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                                 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},

                                 {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},

                                 {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},

                                 {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0}};



          int c[6][17]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                                 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},

                                 {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},

                                 {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},

                                 {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0}};


           int d[7][17]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                                  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},

                                  {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},

                                  {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},

                                  {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},

                                  {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},

                                  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}};



           int e[5][17]={{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},

                                  {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},

                                  {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0}, 

                                  {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},

                                  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}};
struct data{
    int x;
    int y;
    int direction;
};
struct stack{
    struct data stack[300];
    struct data *top;
};
void Initstack(struct stack *stack);
void push(struct data data,struct stack *stack);
struct data pop(struct stack *stack);
void Initstack(struct stack *stack){
    stack->top = stack->stack;
}
void push(struct data data,struct stack *stack){
    *(stack->top++) = data;
}
struct data pop(struct stack *stack){
    return *(--stack->top);
}
int main(){
    int line[100] = {-1};
    int i = 0;
    int j;
    while(scanf("%d",line+i++)!=EOF)
        ;
    struct stack *stack = malloc(sizeof(struct stack));
    Initstack(stack);
    struct data *data = malloc(sizeof(struct data));
    int lin = line[0];
    int row = line[1];
    int array[lin][row];
    int num = line[5];
    switch (num)
    {
    case 0:
        for(int i = 0;i<lin;i++)
            for(int j = 0;j<row;j++)
                array[i][j] = a[i][j];
        break;
    case 1:
        for(int i = 0;i<lin;i++)
            for(int j = 0;j<row;j++)
                array[i][j] = b[i][j];
        break;
    case 2:
        for(int i = 0;i<lin;i++)
            for(int j = 0;j<row;j++)
                array[i][j] = c[i][j];
        break;
    case 3:
        for(int i = 0;i<lin;i++)
            for(int j = 0;j<row;j++)
                array[i][j] = d[i][j];
        break;
    case 4:
        for(int i = 0;i<lin;i++)
            for(int j = 0;j<row;j++)
                array[i][j] = e[i][j];
        break;
    
    default:
        break;
    }
    int x = line[2];
    int y = line[3];
    int color = array[x][y];


    
    int wall;
    if(color==1)
        wall =0;
    else
    {
        wall = 1;
    }
    array[x][y] = 2;
    int times = 0;
    int state = 0;
    data->x = x;
    data->y = y;
    push(*data,stack);
    do{
        i = i%4;
        if(state<4){
            switch (i)
            {
            case 0://下
                if(array[x+1][y]!=wall&&array[x+1][y]!=2&&x<lin-1){
                    data->x = x;
                    data->y = y;
                    push(*data,stack);
                    x++;
                    array[x][y] = 2;
                    state = 0;
                }
                else
                {
                    i++;
                    state ++;
                }
                break;
            case 1://左
                if(array[x][y-1]!=wall&&array[x][y-1]!=2&&y>0){
                    data->x = x;
                    data->y = y;
                    push(*data,stack);
                    y--;
                    array[x][y] = 2;
                    state = 0;
                }
                else
                {
                    i++;
                    state ++;
                }
                break;
            case 2://上
                if(array[x-1][y]!=wall&&array[x-1][y]!=2&&x>0){
                    data->x = x;
                    data->y = y;
                    push(*data,stack);
                    x--;
                    array[x][y] = 2;
                    state = 0;
                }
                else
                {
                    i++;
                    state ++;
                }
                break;
            case 3://右
                if(array[x][y+1]!=wall&&array[x][y+1]!=2&&y<row-1){
                    data->x = x;
                    data->y = y;
                    push(*data,stack);
                    y++;
                    array[x][y] = 2;
                    state = 0;
                }
                else
                {
                    i++;
                    state ++;
                }
                break;
            
            default:
                break;
            }
        }
        else{
            state = 0;
            struct data temp = pop(stack);
            x = temp.x;
            y = temp.y;
        }
        times++;
        getchar();
            
        for(int k = 0;k<lin;k++){
            for(j = 0;j<row;j++){
                if(array[k][j]==0)
                    printf(".");
                else if(array[k][j]==1)
                    printf("#");
                else if(array[k][j]==2)
                    printf("*");
            }
            printf("\n");
        }
    }while(stack->stack!=stack->top);

    for(i = 0;i<lin;i++){
        for(j = 0;j<row;j++){
            if(array[i][j]==0)
                printf(".");
            else if(array[i][j]==1)
                printf("#");
            else if(array[i][j]==2)
                printf("*");
        }
        printf("\n");
    }
}
