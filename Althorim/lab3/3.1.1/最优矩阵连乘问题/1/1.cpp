#include <iostream>
#include<algorithm>
using namespace std;
void MatrixChain(int *p,int n,int **m,int **s)
{
    for(int i=1;i<=n;i++)
    m[i][i]=0;
    for(int r=2;r<=n;r++)
    {
        for(int i=1;i<=n-r+1;i++)
        {
            int j=i+r-1;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j])
                {
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }

    }
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
    MatrixChain(p,n,m,s);
    cout<<"最少乘法次数为："<<m[1][5]<<endl;
    cout<<"最优的加括号方式为："<<endl;
    PrintSolution(1,n,s);
}