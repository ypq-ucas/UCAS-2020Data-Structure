#include<stdio.h>
#include<stdlib.h>
struct parterner{
    int k;
    int position[10];
};
void Init(struct parterner *line[10]){
    for(int i = 0;i<10;i++){
        line[i] = malloc(sizeof(struct parterner));
        line[i]->k = i;
        for(int j = 0;j<10;j++)
            line[i]->position[j] = -1;
    }
}
int numbersgetline(int s[]){
    int c,i;
    int j = 0;
    int state = 1;
    int number = 0;
    for(i = 0;(c = getchar())!=EOF&&c!='\n'&&c!=';';++i){
        if(c<='9'&&c>='0'){           
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
void build(struct parterner* line[10]){
    int data[10];
    int i;
    while((i = numbersgetline(data))!=0){
        int j = data[0];
        for(int k = 0;k<i-1;k++)
            line[j]->position[k] = data[k+1];
    }
} 
int power(int n){
    int sum = 1;
    for(int i = 0;i<n;i++){
        sum*=2;
    }
    return sum;
}
void setfree(struct parterner* line[10]){
    int data[10];
    int i;
    while(i = numbersgetline(data)!=0){
        int j = data[0];
        if(data[1]%power(j+1)==0){
            int tag = 0;
            for(int k = 0;line[j]->position[k]!=-1;k++){
                if(line[j]->position[k]==data[1]+power(j)){
                    int l =0;
                    for(l = 0;line[j+1]->position[l]!=-1;l++);
                    line[j+1]->position[l] = data[1];
                    line[j]->position[k] = -2;
                    tag = 1;
                    break;
                }
            }
            if(tag==0){
                int l =0;
                for(l = 0;line[j]->position[l]!=-1;l++);
                line[j]->position[l] = data[1];
            }
        }
        else{
            int tag = 0;
            for(int k = 0;line[j]->position[k]!=-1;k++){
                if(line[j]->position[k]==data[1]-power(j)){
                    int l =0;
                    for(l = 0;line[j+1]->position[l]!=-1;l++);
                    line[j+1]->position[l] = line[j]->position[k];
                    line[j]->position[k] = -2;
                    tag = 1;
                    break;
                }
            }
            if(tag==0){
                int l =0;
                for(l = 0;line[j]->position[l]!=-1;l++);
                line[j]->position[l] = data[1];
            }
        }
    }
    for(int i = 0;i<10;i++){
        if(line[i]->position[0]!=-1&&line[i]->position[0]!=-2){
            if((line[i]->position[0]== 0&&line[i]->position[1]==power(i))||(line[i]->position[1]== 0&&line[i]->position[0]==power(i))){
                line[i+1]->position[0] = 0;
                line[i]->position[1] = -2;
                line[i]->position[0] = -2;
            }
        }
        if(line[i]->position[0]!=-1&&line[i]->position[0]!=-2){
            if((line[i]->position[2]%power(i+1)==0&&line[i]->position[0]==power(i)+line[i]->position[2])){
                int l =0;
                for(l = 0;line[i+1]->position[l]!=-1;l++);
                line[i+1]->position[l] = line[i]->position[2];
                line[i]->position[2] = -2;
                line[i]->position[0] = -2;
            }
        }
    }
}
int main(){
    struct parterner*line[10];
    Init(line);
    build(line);
    setfree(line);
    for(int i = 3;i<4;i++){
        if(line[i]->position[1]>line[i]->position[3]){
            int temp = line[i]->position[1];
            line[i]->position[1] = line[i]->position[3];
            line[i]->position[3] = temp;
        }
    }
    for(int i = 0;i<10;i++){
        if(line[i]->position[0]!=-1){
            int tag = 0;
            int print[10];
            int t = 0;
            print[t++] = i;
            for(int k = 0;k<10;k++){
                if(line[i]->position[k]!=-1&&line[i]->position[k]!=-2){
                    print[t++] = line[i]->position[k];
                    tag = 1;
                }     
            }
            if(tag){
                for(int u = 0;u<t;u++){
                    printf("%d",print[u]);
                    if(u<t-1)
                        printf(" ");
                }
                printf("\n");
            }
            
        }
    }
}
