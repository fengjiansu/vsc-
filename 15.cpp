#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
#define MAXINT 15
#define Max 4396
#define N 15
void Prim(float c[15][15], int (*number)[2])
{
    int lowcost[MAXINT]; //�洢S�е����Ӧ�������������СȨֵ�ֱ��Ƕ���
    int closest[MAXINT]; //closest[]���鱣�����δ��S�еĵ�������S�а���������ĵ�����һ��,��:closest[i]=1��ʾi�����S�еĵ���1
    bool s[MAXINT];      //bool�ͱ�����S�����ʾi�Ƿ��Ѿ�������S��
    int begin = 0;
    int i, k;
    float sum = 0;
    s[0] = true;            //�ӵ�һ����㿪ʼѰ��,��չ
    for (i = 1; i < N; i++) //�򵥳�ʼ��
    {
        lowcost[i] = c[0][i];
        closest[0] = 0;
        closest[i] = 0; //�������еĵ��Ӧ���Ѿ���S�е�����ĵ���1
        s[i] = false;
    }
    for (i = 0; i < N; i++)
    {
        int min = 1000; //��Сֵ,���һ���ֵ,����������¼lowcost�����е���Сֵ
        int j = -1;
        for (k = 1; k < N; k++) //Ѱ��lowcost�е���Сֵ
        {
            if ((lowcost[k] < min) && (!s[k]))
            {
                min = lowcost[k];
                j = k;
            }
        }
        //cout<<closest[i]<<"->"<<j<<"\n";closest[i]�ǵ�ǰ���� j ���붥������ĵ�
        number[i][0] = closest[j];
        number[i][1] = j;
        sum += c[begin][j];
        s[j] = true;            //��ӵ�j������S��
        for (k = 1; k < N; k++) //��Ϊ�¼�����j��,����Ҫ�����¼����j�㵽δ��S�еĵ�K�е�Ȩֵ�ǲ��ǿ�����˸�С
        {
            if ((c[j][k] < lowcost[k]) && (!s[k]))
            {
                lowcost[k] = c[j][k];
                closest[k] = j;
                begin = j;
            }
        }
    }
    cout<<sum;
}
int main()
{
    
    int number[N - 1][2];
    float matrix[N][15];
    int pointer[N][15];
    int x[] =
        {
            26, 5, 8, 10, 13, 17, 20, 25, 31, 35, 36, 41, 45, 28, 24};
    int y[] = {31, 33, 9, 24, 34, 23, 10, 47, 18, 42, 25, 31, 38, 32, 30};
   
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    pointer[i][j] = 0;
                }
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (i != j)
                        matrix[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                    else
                        matrix[i][j] = Max;
                }
            }
            Prim(matrix, number);
            for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            pointer[number[i][j]][number[i][j + 1]] = 1;
            pointer[number[i][j + 1]][number[i][j]] = 1;
        }
    }
            ofstream outfile, outfile1;
            outfile.open("out15.txt");
            for (int i = 0; i < 15; i++)
            {
                for(int j=0;j<15;j++)
                {
                    outfile <<pointer[i][j] << " " ;
                }
                outfile<<"\n";
            }
                return 0;
        }

