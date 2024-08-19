#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
void MergeArray(int *a,int begin,int mid,int end,int *temp)
//将二个有序子数组a[begin...mid]和a[mid+1...end]合并;
{
    int i = begin,j = mid;
    int m = mid + 1,n = end;
    int k = 0;
    //开始合并两个数组；
    while(i <= j && m <= n)
    {
        if(a[i] <= a[m])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[m++];
        }
    }

    while(i <= j)
    {
        temp[k++] = a[i++];
    }

    while(m <= n)
    {
        temp[k++] = a[m++];
    }
    //把temp数组中的结果装回a数组
    for(i = 0; i < k; i++)
    {
        a[begin + i] = temp[i];
    }
}
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin < end)
    {
        int mid = (begin + end) / 2;
        /**
         *  分别递归进行排序，也称为2-路归并；
         */
        MergeSort(a,begin,mid,temp);   //左边有序
        MergeSort(a,mid + 1,end,temp);   //右边有序
        MergeArray(a,begin,mid,end,temp); //将左右两边有序的数组合并
    }
}
int main() {
int len=10000;
double point[100][2];
int num=0;//循环次数
for(int len=10000;len<=100000;len=len+10000)
{
    int temp[len];
int arr[len];
double Times;
clock_t start,end;
char s1[1000];
char s2[]={"E:\\vsC++\\Althorim\\lab1\\dataset\\data_"};    //利用字符数组实现循环文件读写
char s3[1100];
itoa(len,s1,10);  //将十进制数转换为字符
strcat(s2,s1);
//puts(s2);         检验s2是否是正确的文件名
    FILE *fp=NULL;
    fp=fopen(s2,"r");
     for(int i=0;i<len;i++)
     {
     fscanf(fp,"%d",&arr[i]);
     }
     fclose(fp);
     start=clock();
        MergeSort(arr,0,len,temp);
        end=clock();
        Times=(double)(end-start)/CLOCKS_PER_SEC;
        point[num][0]=len;
        point[num][1]=Times;
        num++;
    printf("%f秒。\n",Times);
}
FILE *fp=NULL;
    fp=fopen("E:\\vsC++\\Althorim\\lab1\\point2.txt","w");
    for(int i=0;i<10;i++)
    {
   fprintf(fp,"%lf %lf",point[i][0],point[i][1]);
   fprintf(fp,"\n");
    }
    fclose(fp);
        return 0;
}