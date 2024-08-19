#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
void bubble_sort(int arr[], int len) {
        int i, j, temp;
        for (i = 0; i < len - 1; i++)
                for (j = 0; j < len - 1 - i; j++)
                        if (arr[j] > arr[j + 1]) {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
}
int main() {
int len=10000;
double point[10][2];//???????????
int num=0;
for(int len=10000;len<=20000;len=len+1000)
{
int arr[len];
double Times;
clock_t start,end;
char s1[1000];
char s2[]={"E:\\vsC++\\Althorim\\lab1\\dataset\\data_"};
char s3[1100];
itoa(len,s1,10);
strcat(s2,s1);
//puts(s2);
    FILE *fp=NULL;
    fp=fopen(s2,"r");
     for(int i=0;i<len;i++)
     {
     fscanf(fp,"%d",&arr[i]);
     }
     fclose(fp);
     start=clock();
        bubble_sort(arr, len);
        end=clock();
        Times=(double)(end-start)/CLOCKS_PER_SEC;
        point[num][0]=len;
        point[num][1]=Times;
        num++;
    printf("%f\n",Times);
}
FILE *fp=NULL;
    fp=fopen("E:\\vsC++\\Althorim\\lab1\\point.txt","w");
    for(int i=0;i<10;i++)
    {
   fprintf(fp,"%lf %lf",point[i][0],point[i][1]);
   fprintf(fp,"\n");
    }
    fclose(fp);
        return 0;
}