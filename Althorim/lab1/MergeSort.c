#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
void MergeArray(int *a,int begin,int mid,int end,int *temp)
//����������������a[begin...mid]��a[mid+1...end]�ϲ�;
{
    int i = begin,j = mid;
    int m = mid + 1,n = end;
    int k = 0;
    //��ʼ�ϲ��������飻
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
    //��temp�����еĽ��װ��a����
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
         *  �ֱ�ݹ��������Ҳ��Ϊ2-·�鲢��
         */
        MergeSort(a,begin,mid,temp);   //�������
        MergeSort(a,mid + 1,end,temp);   //�ұ�����
        MergeArray(a,begin,mid,end,temp); //�������������������ϲ�
    }
}
int main() {
int len=10000;
double point[100][2];
int num=0;//ѭ������
for(int len=10000;len<=100000;len=len+10000)
{
    int temp[len];
int arr[len];
double Times;
clock_t start,end;
char s1[1000];
char s2[]={"E:\\vsC++\\Althorim\\lab1\\dataset\\data_"};    //�����ַ�����ʵ��ѭ���ļ���д
char s3[1100];
itoa(len,s1,10);  //��ʮ������ת��Ϊ�ַ�
strcat(s2,s1);
//puts(s2);         ����s2�Ƿ�����ȷ���ļ���
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
    printf("%f�롣\n",Times);
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