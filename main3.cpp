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
double len;
double juli[181][181];
int m3[181][181];
void forLength(int o)
{
    int n1=181;
    for(int ui;ui<181;ui++)
    {
        if(m3[o][ui]==1)
        {
            len+=juli[o][ui];
            if(len>40)
                cout<<"������Ϊ "<<o<<endl;
            int mn[n1]={0};
            mn[ui]=1;
            for(int i=13;i<n1;i++)
            {
                if(mn[i]==1)
                    forLength(mn[i]);
            }
        }
    }
}
int main()
{
    long double totalLength=0;
   int n1=181;//һ�������ڵ����
     A p[n1];//�洢�������ֵ
//    int lowcost[180][168];//�洢S�е����Ӧ�������������СȨֵ�ֱ��Ƕ���
     ifstream in("PonitA.txt");
     for(int i=0;i<n1;i++)
     {
          in>>p[i].x;
        in>>p[i].y;
      // cout<<p[i].x<<" "<<p[i].y<<endl;
     }
      in.close();
        float juli[n1][n1];//�洢�����֮��ľ���
    for(int a=1;a<13;a++)
    {
        for(int b=13;b<n1;b++)
        {
            juli[a][b]=sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));//��¼a��b�ľ���
          //  cout<<juli[a][b]<<endl;;
        }
    }//juli[0]~juli[11]��ŵ���12��һ���㵽168��������ľ���
    for(int a=13;a<n1;a++)
    {
        for(int b=13;b<n1;b++)
        {
            juli[a][b]=sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));//��¼a��b�ľ���
           // cout<<juli[a][b]<<endl;
        }
    }//juli[12]~juli[179]��ŵ��Ƕ����㵽������֮��ľ���
 //  A op[n1][n1];
    int i=0;
    int ok[n1]={0};//��¼�Ѿ��������ĵ㣬�Ѽ���Ϊ1
           for(i=1;i<13;i++)
              ok[i]=1;//��ȫ����һ��������Ϊ�Ѽ���
    double minLength=999;
    int p1,q1;//�������߶����˶˵����
    for(int yjn=0;yjn<181;yjn++)
    m3[yjn][yjn]=0;//�������֮���Ƿ����߶�
     int h3=0;
     int h4=1;
     double length1[n1][n1]={0};//�����С�������ڵ�֮���·������
    while(h3==0)
    {
        minLength=999;
        for(int a=1;a<n1;a++)
        {
            for(int b=1;b<n1;b++)
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
        length1[p1][q1]=minLength;
        totalLength+=minLength;
         cout<<minLength<<endl;
         for(int yu=1;yu<n1;yu++)
         h4=h4*ok[yu];
         h3=h4;
         h4=1;
    }
    int opp[181]={0};//һ��������,���õ���һ���������Ϊһ������ֵΪһ
    for(int bbb=1;bbb<13;bbb++)
        opp[bbb]=1;
   len=0;//��Ÿ�һ���ڵ�����Ĺܵ��ܳ���
    i=1;
    for(int yhb=1;yhb<n1;yhb++)
    {
        if(opp[yhb]==1)
        forLength(yhb);
    }
	/*while(i<181)//�������нڵ�
    {
        if(opp[i]==1)
        {
            for(int ou=13;ou<181;ou++)
          {
            if(m3[i][ou]==1)
            {
                len=juli[i][ou];
                for(int bn=13;bn<181;bn++)
                    if(m3[ou][bn]==1)
                       {cout<<"001"<<endl<<endl;
                           len+=juli[ou][bn];
                           if(len>40)
                           {
                               //��¼��ou,ou����Ϊһ���ڵ�
                               opp[ou]=1;
                               cout<<"���";
                               cout<<ou<<endl;//�������Ľڵ����
                           }
                       }
            }
          }
        }
        i++;
    }*/
 /*   for(int x6=1;x6<n1;x6++)
    {for(int y6=1;y6<n1;y6++)
     cout<<m3[x6][y6]<<"";
     cout<<endl;
    }
     ofstream out("jieguo.txt");
              for(int x6=1;x6<n1;x6++)
               {
                for(int y6=1;y6<n1;y6++)
                    {
                        //cout<<fixed<<setprecision(2);
                      //  cout<<juzhen[i][j]<<"  ";
	out<<m3[x6][y6];
	if(y6<(n1-1))
        out<<" ";
	}
	out<<endl;
	}
	cout<<"�ڶ����ֹܵ��ܳ���Ϊ="<<totalLength<<endl;*/
    return 0;
}

/*
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
class B
{
    public:
          int x;
          int y;
          B()
          {
              x=0;
              y=0;
          }
};
          int main()
          {
              int n=13;//nΪ�ڵ����
              B p[n];
              ifstream in("PonitB.txt");
              for(int i=0;i<n;i++)
              {
                  in>>p[i].x;
                  in>>p[i].y;
              }
              in.close();
              float juli[n][n];
              for(int a=0;a<12;a++)
                 {
                   for(int b=12;b<n;b++)
                      {
                        juli[a][b]=sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));//��¼a��b�ľ���
                      }
                 }

               //   int i=0;
    int ok[n]={0};//��¼�Ѿ��������ĵ㣬�Ѽ���Ϊ1

              ok[0]=1;//�����Ľڵ�����Ϊ�Ѽ���
    double minLength=999;
    int p1,q1;//�������߶����˶˵����
    int m3[n][n]={0};//�������֮���Ƿ����߶�
     int h3=0;
     int h4=1;
  double totalLength=0;
    while(h3==0)
    {
        minLength=999;
        for(int a=0;a<n;a++)
        {
            for(int b=0;b<n;b++)
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
          for(int yu=0;yu<n;yu++)
         h4=h4*ok[yu];
         h3=h4;
         h4=1;
    }
        ofstream out("jieguo.txt");
              for(int x6=0;x6<n;x6++)
               {
                for(int y6=0;y6<n;y6++)
                    {
                        //cout<<fixed<<setprecision(2);
                      //  cout<<juzhen[i][j]<<"  ";
	                 out<<m3[x6][y6];
                    	if(y6<12)
                    out<<" ";
	                }
	                out<<endl;
	           }
	 cout<<"��һ���ֹܵ��ܳ���Ϊ="<<totalLength<<endl;
              return 0;
          }

*/

