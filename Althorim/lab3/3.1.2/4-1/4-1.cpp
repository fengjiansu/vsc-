#include <iostream>
#include<algorithm>
using namespace std;
struct dot{
    int l,r;
    bool v[10001];
}dots[10001];
int cmp(const dot &a,const dot &b)//�ȽϹ��򣬰������Ҷ˵��������� 
{
    return a.r<b.r;
} 
int main()
{
    int n,i,j,count=1,select;
    FILE *fp,*fpOut;
    if((fp=fopen("input.txt","r"))==NULL){
        printf("\nCannot open input file strike any key exit!");
        getchar();
        return -1;
    }
     if((fpOut=fopen("output.txt","w"))==NULL){
        printf("\nCannot open input file strike any key exit!");
        getchar();
        return -1;
    }
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
        fscanf(fp,"%d %d",&dots[i].l,&dots[i].r);
    sort(dots,dots+n,cmp);//Ԥ���������䰴�����ź��򣬷�������Ƚ� 
    select=dots[0].r;
    //̰�Ĳ�����ѡ�������Ҷ˵㣬��֤�ܹ��������󽻲�Σ�ѡ�ĵ����� 
    for(i=1;i<n;i++)//ÿ�ν���ǰѡ���һ��������Ҷ˵�����һ��������ͬһ���䣬�ɺ��ԣ���˱Ƚ� 
    {
        if(dots[i].l>select)//���û�н��棬ѡ��+1,���Դ������Ҷ�Ϊ��һ�ֱȽϵĵ� 
        {
            count++;
            select=dots[i].r;
        }
    }
    fprintf(fpOut,"%d",count);
    fclose(fp);
    fclose(fpOut);
    return 0;
}