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
                cout<<"升级点为 "<<o<<endl;
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
   int n1=181;//一级二级节点个数
     A p[n1];//存储点的坐标值
//    int lowcost[180][168];//存储S中到达对应的其它各点的最小权值分别是多少
     ifstream in("PonitA.txt");
     for(int i=0;i<n1;i++)
     {
          in>>p[i].x;
        in>>p[i].y;
      // cout<<p[i].x<<" "<<p[i].y<<endl;
     }
      in.close();
        float juli[n1][n1];//存储点与点之间的距离
    for(int a=1;a<13;a++)
    {
        for(int b=13;b<n1;b++)
        {
            juli[a][b]=sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));//记录a和b的距离
          //  cout<<juli[a][b]<<endl;;
        }
    }//juli[0]~juli[11]存放的是12个一级点到168个二级点的距离
    for(int a=13;a<n1;a++)
    {
        for(int b=13;b<n1;b++)
        {
            juli[a][b]=sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));//记录a和b的距离
           // cout<<juli[a][b]<<endl;
        }
    }//juli[12]~juli[179]存放的是二级点到二级点之间的距离
 //  A op[n1][n1];
    int i=0;
    int ok[n1]={0};//记录已经加入树的点，已加入为1
           for(i=1;i<13;i++)
              ok[i]=1;//将全部的一级点设置为已加入
    double minLength=999;
    int p1,q1;//存放最短线段两端端点序号
    for(int yjn=0;yjn<181;yjn++)
    m3[yjn][yjn]=0;//存放两点之间是否有线段
     int h3=0;
     int h4=1;
     double length1[n1][n1]={0};//存放最小生成树节点之间的路径长度
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
    int opp[181]={0};//一级点的序号,若该点是一级点或升级为一级点则值为一
    for(int bbb=1;bbb<13;bbb++)
        opp[bbb]=1;
   len=0;//存放该一级节点出发的管道总长度
    i=1;
    for(int yhb=1;yhb<n1;yhb++)
    {
        if(opp[yhb]==1)
        forLength(yhb);
    }
	/*while(i<181)//遍历所有节点
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
                               //记录下ou,ou将升为一级节点
                               opp[ou]=1;
                               cout<<"输出";
                               cout<<ou<<endl;//将升级的节点输出
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
	cout<<"第二部分管道总长度为="<<totalLength<<endl;*/
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
              int n=13;//n为节点个数
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
                        juli[a][b]=sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));//记录a和b的距离
                      }
                 }

               //   int i=0;
    int ok[n]={0};//记录已经加入树的点，已加入为1

              ok[0]=1;//将中心节点设置为已加入
    double minLength=999;
    int p1,q1;//存放最短线段两端端点序号
    int m3[n][n]={0};//存放两点之间是否有线段
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
	 cout<<"第一部分管道总长度为="<<totalLength<<endl;
              return 0;
          }

*/

