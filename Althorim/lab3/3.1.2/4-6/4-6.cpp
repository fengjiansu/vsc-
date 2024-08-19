#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
using std::vector;
double greedy(vector<int>x)
{
    int n=x.size();
    sort(x.begin(),x.end());
    for(int i=1;i<n;i++)
    {
       x[i]+=x[i-1]; 
    }
    double t=0;
    for(int i=0;i<n;i++)
    {
        t+=x[i];
    }
    t/=n;
    return t;
}
int main()
{
    int n;
    int a;
    double t;
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
        fscanf(fp,"%d",&a);                          //尾部插入
       p.push_back(a);                          //尾部插入
   }
   t=greedy(p);
   cout<<"最小平均等待时间为："<<t<<endl;
fprintf(fpOut,"%lf",t);
fclose(fp);
fclose(fpOut);
    return 0;
}