
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
using std::vector;
//�������ƽ����ȡ��������ԭ��
double greedy(vector<int>x,vector<int>p)  //x �ǳ��� p�Ƕ�ȡ����
{
    int n=p.size();
    vector <int>y(n,0);   
    for(int i=0;i<n;i++)
        y[i]=x[i]*p[i];                           //�ļ���ȡʱ��
    sort(y.begin(),y.end());                      // ��������     
    for(int i=1;i<=n;i++)
        y[i]+=y[i-1];                             //�ۼ�
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
        x.push_back(a);                               //β������
         p.push_back(b);                              //β������
   }
t=greedy(x,p);
cout<<"��Сƽ����ȡʱ��Ϊ��"<<t<<endl;
fprintf(fpOut,"%lf",t);
fclose(fp);
fclose(fpOut);
    return 0;
}