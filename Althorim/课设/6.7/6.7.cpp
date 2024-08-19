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
    int len(int **,int ii);//�������߳ɱ�
    private:
    int *x;//��¼��·������
   int s; //��ǰ�ڵ��Ӧ������
    int cd; //��ǰ���еĳɱ�
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
    MinHeap<BoardNode> H(1000); //������С��
    BoardNode E;
    E.x=new int[n+1];
    E.s=0;
    E.cd=0;
    for(int i=1;i<=n;i++)
    E.x[i]=i;       //��ʼ����Ϊ1 2 3
    int bested=INT_MAX;
    bestx=0;
    while(E.cd<bested)
    {
        if(E.s==n-1)  //��һ�����ӽڵ�
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
        else         //������ǰ��չ�ڵ�����ж��ӽڵ�
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
			return bested;//����չ�ڵ�
		}
		H.DeleteMin(E);
    }
     	
	//�ͷ���С�������нڵ�
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
void Make2DArray(Type **&x,int rows,int cols)//��̬������ά����
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