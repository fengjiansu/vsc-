#include <bits/stdc++.h>
using namespace std;
int  multiple,result=0;
int median(int *arr,int start,int end )
{
    return arr[(start+end)/2];//如偶数取左边的为中位数
}
void split(int*arr,int med,int start,int end,int *startleft,int *endright)//找到中位数的最左端start1和最右端end1
{
  for(int i=0;i<end;i++)
  {
      if(arr[i]==med)
      {
          *startleft=i;
          break;
      }
  }
  for(int i=end;i>start;i--)
  {
      if(arr[i]==med)
      {
          *endright=i;
          break;
      }
  }
}
void mode(int *arr,int start,int end)
{
    multiple=end/2;
    int startleft,endright;
    int med=median(arr,start,end);//找到中位数
    split(arr,med,start,end,&startleft,&endright);//找到中位数左端，右端
    if(multiple<=endright-startleft+1)
    {
        multiple=endright-startleft+1;//计算重数
          result=med;
     }
    if(startleft-start>multiple)//如果左边个数大于重数再递归
    mode(arr,start,startleft-1);
    if(end-endright>multiple)//如果右边个数大于重数再递归
    mode(arr,endright+1,end);
}
int main()
{
    int num=7;
    int arr[num];
   ifstream in("input.txt");
    ofstream out("output.txt");
    for(int i=0;i<num;i++)
    {
     in>>arr[i];
    }  
    sort(arr,arr+num);
   mode(arr,0,num-1);
  out<<result<<endl<<multiple;
    return 0;
}