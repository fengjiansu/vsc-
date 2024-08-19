
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
using std::vector;
double greedy(vector<int>x,int s)
{
    vector<int>st(s+1,0);
    vector<int>su(s+1,0);
    int n=x.size();
    sort(x.begin(),x.end());
    int i=0,j=0;
    while (i<n)
    {
        st[j]+=x[i];
        su[j]+=st[j];
        i++;
        j++;
        if(j==s)
        j=0;
    }
    double t=0;
    for(i=0;i<s;i++)
    {
        t+=su[i];
    }
    t/=n;
    return t;
}
int main()
{
    int n;
    int a;
    int s;
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
   fscanf(fp,"%d %d",&n,&s);
   for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&a);                          //尾部插入
       p.push_back(a);                          //尾部插入
   }
   t=greedy(p,s);
   cout<<"最小平均等待时间为："<<t<<endl;
fprintf(fpOut,"%lf",t);
fclose(fp);
fclose(fpOut);
    return 0;
}