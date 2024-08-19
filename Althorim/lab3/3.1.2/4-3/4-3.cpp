
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
using std::vector;
//依据最短平均读取程序优先原则
double greedy(vector<int>x,vector<int>p)  //x 是长度 p是读取概率
{
    int n=p.size();
    vector <int>y(n,0);   
    for(int i=0;i<n;i++)
        y[i]=x[i]*p[i];                           //文件读取时间
    sort(y.begin(),y.end());                      // 升序排序     
    for(int i=1;i<=n;i++)
        y[i]+=y[i-1];                             //累加
        double m=0,t=0;
        for (int i=0;i<n;i++)
        {
            m+=p[i];
            t+=y[i];
        }
        return t/m;
}
int main()
{
    int n;
    int a,b;
    double t;
    vector<int>x;
    vector<int>p;
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
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d %d",&a,&b);
        x.push_back(a);                               //尾部插入
         p.push_back(b);                              //尾部插入
   }
t=greedy(x,p);
cout<<"最小平均读取时间为："<<t<<endl;
fprintf(fpOut,"%lf",t);
fclose(fp);
fclose(fpOut);
    return 0;
}