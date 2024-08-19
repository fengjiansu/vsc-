#include <bits/stdc++.h>
#include"MinHeap.h"
using namespace std;
class BoardNode{
    friend int BBArrangeBoards(int **,int,int *&);
    public:
    operator int()const 
    {
        return cd;
    }
    int len(int **,int ii);//计算连线成本
    private:
    int *x;//记录电路板排列
   int s; //当前节点对应的排列
    int cd; //当前排列的成本
};
int BoardNode::len(int **conn,int ii)
{
    int sum=0;
    for(int i=1;i<=ii;i++)
    {
        for(int j=i+1;j<=ii;j++)
        {
            int dist=x[i]>x[j]?x[i]-x[j]:x[j]-x[i];
            sum+=conn[i][j]*dist;
        }
    }
    return sum;
}
int BBArrangeBoards(int **conn,int n,int *&bestx)
{
    MinHeap<BoardNode> H(1000); //活结点最小堆
    BoardNode E;
    E.x=new int[n+1];
    E.s=0;
    E.cd=0;
    for(int i=1;i<=n;i++)
    E.x[i]=i;       //初始排列为1 2 3
    int bested=INT_MAX;
    bestx=0;
    while(E.cd<bested)
    {
        if(E.s==n-1)  //仅一个儿子节点
        {
            int ld=E.len(conn,n);
            if(ld<bested)
            {
                delete []bestx;
                bestx=E.x;
                bested=ld;
            }
            else
            {
                delete []E.x;
            }
        }
        else         //产生当前扩展节点的所有儿子节点
        {
            for(int i=E.s+1;i<=n;i++)
            {
                BoardNode N;
                N.x=new int[n+1];
                N.s=E.s+1;
                for(int j=1;j<=n;j++)
                    N.x[j]=E.x[j];
                N.x[N.s]=E.x[i];
                N.x[i]=E.x[N.s];
                N.cd=N.len(conn,N.s);
                if(N.cd<bested)
                H.Insert(N);
                else
                    delete[] N.x; 
            }
            delete[] E.x; 
        }
        if(H.Size() == 0)
		{
			return bested;//无扩展节点
		}
		H.DeleteMin(E);
    }
     	
	//释放做小堆中所有节点
	do
	{
		delete []E.x;
		if(H.Size() == 0)
		{
			break;
		}
		H.DeleteMin(E);
	}while(true);
    return bested;
}
template<class Type>
void Make2DArray(Type **&x,int rows,int cols)//动态创建二维数组
{
    x=new Type*[rows];
    for(int i=0;i<rows;i++)
    x[i]=new Type[cols];
}
int main()
{
     int n;
     int ld;
    ifstream in("input.txt");
    in>>n;
   int * p=new int[n+1];
    int **B;
    Make2DArray(B,n+1,n+1);
    for(int i=1;i<=n+1;i++)
    for(int j=i+1;j<=n;j++)
        in>>B[i][j];
        ld=BBArrangeBoards(B,n,p);
        ofstream out("output.txt");
    cout<<ld<<endl;
    out<<ld<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<p[i]<<" ";
        out<<p[i]<<" ";
    }
    cout<<endl;
    out<<endl;
    in.close();
    out.close();
    return 0;
}