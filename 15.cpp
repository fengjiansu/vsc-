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
    int lowcost[MAXINT]; //存储S中到达对应的其它各点的最小权值分别是多少
    int closest[MAXINT]; //closest[]数组保存的是未在S中的点所到达S中包含的最近的点是哪一个,如:closest[i]=1表示i最靠近的S中的点是1
    bool s[MAXINT];      //bool型变量的S数组表示i是否已经包括在S中
    int begin = 0;
    int i, k;
    float sum = 0;
    s[0] = true;            //从第一个结点开始寻找,扩展
    for (i = 1; i < N; i++) //简单初始化
    {
        lowcost[i] = c[0][i];
        closest[0] = 0;
        closest[i] = 0; //现在所有的点对应的已经在S中的最近的点是1
        s[i] = false;
    }
    for (i = 0; i < N; i++)
    {
        int min = 1000; //最小值,设大一点的值,后面用来记录lowcost数组中的最小值
        int j = -1;
        for (k = 1; k < N; k++) //寻找lowcost中的最小值
        {
            if ((lowcost[k] < min) && (!s[k]))
            {
                min = lowcost[k];
                j = k;
            }
        }
        //cout<<closest[i]<<"->"<<j<<"\n";closest[i]是当前顶点 j 是离顶点最近的点
        number[i][0] = closest[j];
        number[i][1] = j;
        sum += c[begin][j];
        s[j] = true;            //添加点j到集合S中
        for (k = 1; k < N; k++) //因为新加入了j点,所以要查找新加入的j点到未在S中的点K中的权值是不是可以因此更小
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

