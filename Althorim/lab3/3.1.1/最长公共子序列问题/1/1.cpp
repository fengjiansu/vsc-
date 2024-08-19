#include <iostream>
#include<cstring>
using namespace std;
void LCSLength(int m,int n,char *x,char *y,int **c)
{
    int i,j;
    for(i=1;i<=m;i++)
    {
        c[i][0]=0;
    }
    for(i=1;i<=n;i++)
    {
        c[0][i]=0;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
            }
            else
            {
                c[i][j]=c[i][j-1];
            }
        }
    }
}
//借用b数组打印最长公共子序列
/**
void PrintLcs(int i,int j,char*x,int**b)
{
    if(i==0||j==0)
    {
    return ;
    }
    if(b[i][j]==1)
    {
        
        PrintLcs(i-1,j-1,x,b);
        cout<<x[i-1];
        
    }
    else if(b[i][j]==2)
    {
        PrintLcs(i-1,j,x,b);
    }
    else if(b[i][j]==3)
    {
        PrintLcs(i,j-1,x,b);
    }
}**/
void PrintLcs1(int m,int n,int** c,char*x,char*y)
{
   int index = c[m][n]; 
   char lcs[index+1]; //存放最长公共子序列
   lcs[index] = '\0'; //设置终止符
    //从最右下角开始
    //在lcs中一一存储字符
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      // 如果当前字符在X和Y中一样，当前字符在公共子序列中
      if (x[i-1] == y[j-1]) 
      { 
          lcs[index-1] = x[i-1]; // 将当前字符存入
          i--; j--; index--;  
      }  
      // 如果不一样，找到然后找到两个中较大的一个
      else if (c[i-1][j] > c[i][j-1]) 
         i--; 
      else
         j--; 
   } 
   // Print the lcs 
   cout << "LCS of " << x << " and " << y<< " is " << lcs; 
}
int main()
{
    char x[] = "AGGTAB"; 
  char y[] = "GXTXAYB";  
    int m = strlen(x); 
    int n = strlen(y); 
    int **c=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        c[i]=new int(n+1);
    }
    LCSLength(m,n,x,y,c);
    cout << "Length of LCS: " <<c[m][n]<<endl;
    PrintLcs1(m,n,c,x,y);
}