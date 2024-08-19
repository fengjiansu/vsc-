#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int greedy(vector<int>x,int n)
{
    int sum=0;
    int k=x.size();
    for(int i=0;i<k;i++)
    {
        if(x[i]>n)
        {
            cout<<"No Solution!"<<endl;
            return -1;
        }
    }
    for(int i=0,s=0;i<k;i++)
    {
        s+=x[i];
        if(s>n) 
        {
          sum++;
          s=x[i];
        }
    }
    return sum;
}
int main()
{
    int n,k,sum;
    int a;
    vector<int>x;
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
   fscanf(fp,"%d %d",&n,&k);
    for(int i=0;i<=k;i++)
    {
        fscanf(fp,"%d",&a);
        x.push_back(a);                               //尾部插入
   }
   if(greedy(x,n)!=-1)
{
    sum=greedy(x,n);
cout<<"最小加油次数为："<<sum<<endl;
fprintf(fpOut,"%d",sum);
}
fclose(fp);
fclose(fpOut);
    return 0;
}