#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int a[1000][1000];
void Table(int n,int k){
	if(n == 2){                     //�������㹻Сʱ
		a[k][0] = k+1;
		a[k][1] = k+2;
		a[k+1][0] = k+2;
		a[k+1][1] = k+1;
	} 
	else{
		Table(n/2,k);         //����������
		Table(n/2,k+n/2);
		for(int i = k; i < k+n/2; i++){    //����ά������Ͻ�
			for(int j = n/2; j < n; j++){
				a[i][j] = a[i+n/2][j-n/2];
			}
		}
		for(int i = k+n/2; i < k+n; i++){   //����ά������½�
			for(int j = n/2; j < n; j++){
				a[i][j] = a[i-n/2][j-n/2];
			}
		}
	}
}
int main()
{
    int k=3;
    int n=(int)pow(2,k);  //�˶�Ա����
 for(int i=0;i<n;i++)
   a[i][0]=i+1;
    Table(n,0);
    FILE *fpOut;
    if((fpOut=fopen("E:\\vsC++\\Althorim\\lab2\\3\\out.txt","w"))==NULL){
        printf("\nCannot open output file strike any key exit!");
        getchar();
        return -1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {fprintf(fpOut,"%d ",a[j][i]);//���ճ̱�������ļ���
        printf("%d ",a[j][i]);
        }
        fprintf(fpOut,"\n");
        printf("\n");
    }
    return 0;
}