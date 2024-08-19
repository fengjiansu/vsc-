/****
 主要参照了课本上的汉诺塔 所以时间复杂度为 O(2^n)                                                                  
****/

#include<stdio.h>
int count=0;
char r[1000000][2];
void move(char a,char b)
{

  r[count][0]=a;
  r[count][1]=b;
  count++;
}                   
void hanoi(int n,char a,char b,char c)
{
    if(n>0)
    {
        hanoi(n-1,a,c,b);
        move(a,b);
        hanoi(n-1,c,b,a);
    }
}
int main()
{
    int n;
    char a='A',b='B',c='C';
    FILE *fp,*fpOut;
     if((fp=fopen("E:\\vsC++\\Althorim\\lab1\\2-9\\input.txt","r"))==NULL){
        printf("\nCannot open input file strike any key exit!");
        getchar();
        return -1;
    }
     if((fpOut=fopen("E:\\vsC++\\Althorim\\lab1\\2-9\\output.txt","w"))==NULL){
        printf("\nCannot open output file strike any key exit!");
        getchar();
        return -1;
    }
    fscanf(fp,"%d",&n);
    hanoi(n,a,c,b);                 //将C看做b盘即可
    for(int i=0;i<count;i++)
    {
        fprintf(fpOut,"%d %c %c\n",i+1,r[i][0],r[i][1]);//记录每一步 以及从那个盘移动到另一个盘
    }
    return 0;
}