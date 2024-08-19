#include <iostream>
#include<algorithm>
using namespace std;
int LookupChain(int i,int j,int **m,int **s,int *p)
{
    if(m[i][j]>0)
    return m[i][j];
    if(i==j)
    return 0;
    int u=LookupChain(i,i,m,s,p)+LookupChain(i+1,j,m,s,p)+p[i-1]*p[i]*p[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++)
    {
        int t=LookupChain(i,k,m,s,p)+LookupChain(k+1,j,m,s,p)+p[i-1]*p[k]*p[j];
        if(t<u)
        {
            u=t;
            s[i][j]=k;
        }
    }
    m[i][j]=u;
    return u;
}
int MemoizeMatrixChain(int n,int **m,int **s,int *p)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            m[i][j]=0;
        }
    }
      return LookupChain(1,n,m,s,p);
}
void PrintSolution(int i,int j,int **s)
{
    if(i==j)
    {
        cout<<'A'<<i;
    return;
    }
    cout<<'(';
    PrintSolution(i,s[i][j],s);
    PrintSolution(s[i][j]+1,j,s);
    cout<<')';
}
int main()
{
    int n,l;
    n=6;
     l=n+1;
     //A1 30*35 A2 35*15 A3 15*5 A4 5*10 A5 10*20 A6 20*25
    int p[l]={30,35,15,5,10,20,25};
    int **m=new int*[l];
    int **s=new int*[l];
    for(int i=0;i<l;i++)
    {
        m[i]=new int(l);
        s[i]=new int(l);
    }
    MemoizeMatrixChain(n,m,s,p);
    cout<<"最少乘法次数为："<<m[1][5]<<endl;
    cout<<"最优的加括号方式为："<<endl;
    PrintSolution(1,n,s);
}