#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
class A
{
public:
    int x;
    int y;
    A()
    {
       x=0;
       y=0;
    }
};
int main()
{
    long double totalLength=0;//��ŵڶ����ֹܵ��ܳ���
    int n1=180;//һ�������ڵ����
     A p[n1];//�洢�������ֵ
//    int lowcost[180][168];//�洢S�е����Ӧ�������������СȨֵ�ֱ��Ƕ���
     ifstream in("PointA19.txt");
     for(int i=0;i<n1;i++)
     {
          in>>p[i].x;
        in>>p[i].y;
      // cout<<p[i].x<<" "<<p[i].y<<endl;
     }
      in.close();
       float juli[n1][n1];//�洢�����֮��ľ���
    for(int a=0;a<18;a++)
    {
        for(int b=18;b<n1;b++)
        {
            juli[a][b]=sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));//��¼a��b�ľ���
          //  cout<<juli[a][b]<<endl;;
        }
    }//juli[0]~juli[11]��ŵ���12��һ���㵽168��������ľ���
    for(int a=18;a<n1;a++)
    {
        for(int b=18;b<n1;b++)
        {
            juli[a][b]=sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));//��¼a��b�ľ���
           // cout<<juli[a][b]<<endl;
        }
    }//juli[12]~juli[179]��ŵ��Ƕ����㵽������֮��ľ���
 //  A op[n1][n1];
    int i=0;
    int ok[180]={0};//��¼�Ѿ��������ĵ㣬�Ѽ���Ϊ1
           for(i=0;i<18;i++)
              ok[i]=1;//��ȫ����һ��������Ϊ�Ѽ���
    double minLength=999;//�����̹ܵ�����
    int p1,q1;//�������߶����˶˵����
    int m3[180][180]={0};//�������֮���Ƿ����߶�
     int h3=0;
     int h4=1;
    while(h3==0)
    {
        minLength=999;
        for(int a=0;a<n1;a++)
        {
            for(int b=0;b<n1;b++)
            {
                if((minLength>juli[a][b])&&(juli[a][b]!=0)&&(ok[b]==0)&&(ok[a]==1))
                   {
                       minLength=juli[a][b];
                       p1=a;
                       q1=b;
                   }
            }
        }
        ok[q1]=1;
        m3[p1][q1]=1;
        totalLength+=minLength;
         cout<<minLength<<endl;

         for(int yu=0;yu<n1;yu++)
         h4=h4*ok[yu];
         h3=h4;
         h4=1;
    }

    /***for(int x6=0;x6<180;x6++)
    {for(int y6=0;y6<180;y6++)
     cout<<m3[x6][y6]<<"";
     cout<<endl;
    }***/
     
     ofstream out("jieguo.txt");
              for(int x6=0;x6<n1;x6++)
               {
                for(int y6=0;y6<n1;y6++)
                    {
                        //cout<<fixed<<setprecision(2);
                      //  cout<<juzhen[i][j]<<"  ";

	out<<m3[x6][y6];
	if(y6<179)
        out<<" ";
	}
	out<<endl;
	}
	cout<<"�ڶ����ֹܵ��ܳ���Ϊ="<<totalLength<<endl;
    return 0;
}
