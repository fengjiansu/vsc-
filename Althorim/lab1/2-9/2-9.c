/****
 ��Ҫ�����˿α��ϵĺ�ŵ�� ����ʱ�临�Ӷ�Ϊ O(2^n)                                                                  
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
    hanoi(n,a,c,b);                 //��C����b�̼���
    for(int i=0;i<count;i++)
    {
        fprintf(fpOut,"%d %c %c\n",i+1,r[i][0],r[i][1]);//��¼ÿһ�� �Լ����Ǹ����ƶ�����һ����
    }
    return 0;
}