#include <iostream>
#include <cmath>
#include<ctime>
#include<cstring>
using namespace std;
class PointX
{
  public:
  int operator<=(PointX a)const
  {
    return (x<=a.x);
  }
  int ID;
  float x,y;
    PointX & operator=( PointX b)
  {
    ID=b.ID;
    x=b.x;
    y=b.y;
    return *this;
  }
};
class PointY
{
  public:
     int operator<=(PointY a)const
  {
    return (y<=a.y);
  }
  int p;           //ͬһ��������X�е�����
  float x,y;
     PointY & operator=( PointY a)
  {
    p=a.p;
    x=a.x;
    y=a.y;
    return *this;
  }
};
template<class Type>
inline float distance (const Type &u,const Type &v)
{
  float dx=u.x-v.x;
  float dy=u.y-v.y;
  return sqrt(dx*dx+dy*dy);
}
template<class Type>
void Merge(Type c[],Type d[],int l,int m,int r)           //�ϲ�c[l:m]��c[m+1:r]��d[l:r];
{
  int i=l,j=m+1,k=l;
  while ((i<=m)&&(j<=r))
  {
    if(c[i]<=c[j])
    d[k++]=c[i++];                  //����߸��Ƶ�d
    else
      d[k++]=c[j++];                //���ұ߸��Ƶ�d
    if(i>m)
    {
      for(int q=j;q<=r;q++)        //�������ʣ�µ�
      {                      
        d[k++]=c[q];
      }
    }
    if(j>r)
    {
      for(int q=i;q<=m;q++)        //�����ұ�ʣ�µ�
      {
        d[k++]=c[q];
      }
    }
  }
}

template<class Type>
void Mergepass(Type x[],Type y[],int s,int n)    //�ϲ���СΪS������������
{
  int i=0;
  while(i<=n-2* s)
  {
    Merge(x,y,i,i+s-1,i+2*s-1);//�ϲ���СΪs������2��������
    i=i+2*s;
  }
  if(i+s<n)                         //ʣ�µ�Ԫ�ظ�������2s
  Merge(x,y,i,i+s-1,n-1);      
  else
  {
    for(int j=i;j<=n-1;j++)
    y[j]=x[j];
  }
}
template<class Type>
void Mergesort(Type a[],int n)
{
    
  Type *b =new Type [n];
  int s=1;
  while(s<n)
  {
    Mergepass(a,b,s,n);//�ϲ�������b
    s+=s;
    Mergepass(b,a,s,n);//�ϲ�������a
    s+=s;
  }
}

void closest(PointX X[],PointY Y[],PointY Z[],int l,int r,PointX& a,PointX& b,float& d)
{
  if(r-l==1)                //���������
  {
    a=X[l];
    b=X[r];
    d=distance(X[l],X[r]);
    return;
  }
  if(r-l==2)               //3�������
  {
    float d1=distance(X[l],X[l+1]);
    float d2=distance(X[l+1],X[r]);
    float d3=distance(X[l],X[r]);
    if(d1<=d2&&d1<=d3)
    {
      a=X[l];
      b=X[l+1];
      d=d1;
      return;
    }
    if(d2<=d3)
    {
      a=X[l+1];
      b=X[r];
      d=d2;
    }
    else
    {
      a=X[l];
   b=X[r];
d=d3;
    }
    return;
  }
  //����3�����
  int m=(l+r)/2;
  int f=l,g=m+1;
  for(int i=l;i<=r;i++)
  {
    if(Y[i].p>m)
    Z[g++]=Y[i];
    else
    {
      Z[f++]=Y[i];
    }
  }
  closest(X,Z,Y,l,m,a,b,d);
  float dr;
  PointX ar,br;
  closest(X,Z,Y,m+1,r,ar,br,dr);
  if(dr<d)
  {
    a=ar;
    b=br;
    d=dr;
  }
  Merge(Z,Y,l,m,r);     //�ع�����Y
  //d�������ĵ�����Z��
  int k=1;
  for(int i=l;i<=r;i++)
  {
   if(fabs(Y[m].x-Y[i].x)<d)
   Z[k++]=Y[i];
  }
  for(int i=l;i<k;i++)
  {
    for(int j=i+1;j<k && Z[j].y-Z[i].y<d;j++)
    {
      float dp=distance(Z[i],Z[j]);
      if(dp<d)
      {
        d=dp;
        a=X[Z[i].p];
        b=X[Z[j].p];
      }
    }
  }
}
bool Cpair2(PointX X[],int n,PointX& a,PointX& b,float& d)
{
  if(n<2)
  return false;
  Mergesort(X,n);
  PointY *Y =new PointY[n];
  for(int i=0;i<n;i++)                  //X���Ƶ�Y
  {
    Y[i].p=i;
    Y[i].x=X[i].x;
    Y[i].y=X[i].y;
  }
  Mergesort(Y,n);
  PointY *Z=new PointY [n];
 
  closest(X,Y,Z,0,n-1,a,b,d);
  delete []Y;
  delete []Z;
  return true;
}
int main()
 {
   int n;
   double Times;
   int num=0;
   float d;
   float point[100][2];       //�������ʱ��
  float result[100][5];       //��������Ժ;���
clock_t start,end;
  for(int len=1000;len<=10000;len=len+1000)
  {
  char s1[1000];
char s2[]={"E:\\vsC++\\Althorim\\lab2\\dataset\\more\\data_"};
char s3[1100];
itoa(len,s1,10);
strcat(s2,s1);                                            //���ж��ļ���ȡ
  FILE *fp;
  if((fp=fopen(s2,"r"))==NULL){
        printf("\nCannot open input file strike any key exit!");
        getchar();
        return -1;
    }
    fscanf(fp,"%d",&n);
      PointX X[n];
      PointX a,b;
    for(int i=0;i<n;i++)
    {
      X[i].ID=i+1;
        fscanf(fp,"%f %f",&X[i].x,&X[i].y);
    }
     fclose(fp);
   // printf("%f %f\n",X[i].x,X[i].y);
     start=clock();
    Cpair2(X,n,a,b,d);
     end=clock();
        Times=(double)(end-start)/CLOCKS_PER_SEC;
        point[num][0]=len;                   //������ʱ�����Point
        point[num][1]=Times;
        result[num][0]=a.x;
        result[num][1]=a.y;                      //��ȡ������
        result[num][2]=b.x;
        result[num][3]=b.y;
        result[num][4]=d;
        num++;
  FILE *fpOut,*fpOut1;
  if((fpOut=fopen("E:\\vsC++\\Althorim\\lab2\\4\\output.txt","w"))==NULL){
        printf("\nCannot open output file strike any key exit!");
        getchar();           //output���ʱ�临�Ӷ�
        return -1;
    }
     if((fpOut1=fopen("E:\\vsC++\\Althorim\\lab2\\4\\result.txt","w"))==NULL){
        printf("\nCannot open output file strike any key exit!");
        getchar();          //result������
        return -1;
    }
    for(int i=0;i<10;i++)
    {
      fprintf(fpOut1,"%f %f %f  %f distance is %f",result[i][0],result[i][1],result[i][2],result[i][3],result[i][4]);
      fprintf(fpOut1,"\n");
    }
   for(int i=0;i<10;i++)
    {
   fprintf(fpOut,"%f %f",point[i][0],point[i][1]);
   fprintf(fpOut,"\n");
    }
    fclose(fpOut);
    fclose(fpOut1);
  }
    return 0;
}