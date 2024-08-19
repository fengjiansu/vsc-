#include <iostream>
#include<algorithm>
using namespace std;
struct dot{
    int l,r;
    bool v[10001];
}dots[10001];
int cmp(const dot &a,const dot &b)//比较规则，按区间右端点升序排列 
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
    sort(dots,dots+n,cmp);//预处理，将区间按规则排好序，方便后续比较 
    select=dots[0].r;
    //贪心策略是选择区间右端点，保证能够包含更大交叉段，选的点最少 
    for(i=1;i<n;i++)//每次将当前选择的一个区间的右端点与下一个（或者同一区间，可忽略）左端比较 
    {
        if(dots[i].l>select)//如果没有交叉，选点+1,并以此区间右端为新一轮比较的点 
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