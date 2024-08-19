
//��·���������� ���ȶ��з�֧�޽編��� 
#include "MinHeap2.h"
#include <iostream>
#include <fstream> 
using namespace std;
ifstream fin("6d8.txt"); 

class BoardNode
{
	friend int BBArrangement(int **,int,int,int *&);
	public:
		operator int() const
		{
			return cd;
		}
	private:
		int *x,			//x[1:n]��¼��·������
			s,			//x[1:s]�ǵ�ǰ�ڵ�����Ӧ�Ĳ�������
			cd,			//x[1:s]���ܶ�
			*now;		//now[j]��x[1:s]�������ӿ�j�е�·����
};
 
int BBArrangement(int **B,int n,int m,int *&bestx);
 
int main()
{
	int m = 5,n = 8;
	int *bestx;
 
	//B={1,2,3,4,5,6,7,8}
	//N1={4,5,6},N2={2,3},N3={1,3},N4={3,6},N5={7,8}
 
	cout<<"m="<<m<<",n="<<n<<endl;
	cout<<"N1={4,5,6},N2={2,3},N3={1,3},N4={3,6},N5={7,8}"<<endl;
	cout<<"��ά����B���£�"<<endl;
 
	//����B
	int **B = new int*[n+1];
	for(int i=1; i<=n; i++)
	{
		B[i] = new int[m+1];
	}
 
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m ;j++)
		{
			fin>>B[i][j];
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
 
	cout<<"��ǰ�����ܶ�Ϊ:"<<BBArrangement(B,n,m,bestx)<<endl;
	cout<<"��������Ϊ��"<<endl;
	for(int i=1; i<=n; i++)
	{
		cout<<bestx[i]<<" ";
	}
	cout<<endl;
 
	for(int i=1; i<=n; i++)
	{
		delete[] B[i];
	}
	delete[] B;
 
	return 0;
}
 
//���·��������������ȶ���ʽ��֧�޽編
int BBArrangement(int **B,int n,int m,int *&bestx)
{
	MinHeap<BoardNode> H(1000);//��ڵ���С��
	BoardNode E;
	E.x = new int[n+1];
	E.s = 0;
	E.cd = 0;
 
	E.now = new int[m+1];
	int *total = new int[m+1];
	//now[i] = x[1:s]�������ӿ�i�е�·����
	//total[i] = ���ӿ�i�еĵ�·����
 
	for(int i=1; i<=m; i++)
	{
		total[i] = 0;
		E.now[i] = 0;
	}
 
	for(int i=1; i<=n; i++)
	{
		E.x[i] = i;//��ʼ����Ϊ1,2,3����n
		for(int j=1;j<=m;j++)
		{
			total[j] += B[i][j];//���ӿ��е�·����
		}
	}
 
	int bestd = m + 1;
	bestx = 0;
 
	do//�ڵ���չ
	{
		if(E.s == n-1)//��һ�����ӽڵ�
		{	
			int ld  = 0;//���һ���·����ܶ�
			for(int j=1; j<=m; j++)
			{
				ld += B[E.x[n]][j];
			}
			if(ld<bestd)//�ܶȸ�С�ĵ�·����
			{
				delete[] bestx;
				bestx = E.x;
				bestd = max(ld,E.cd);
			}
			else
			{
				delete []E.x;
			}
			delete []E.now;
		}
		else//������ǰ��չ�ڵ�����ж��ӽڵ�
		{
			for(int i=E.s+1;i<=n;i++)
			{
				BoardNode N;
				N.now = new int[m+1];
				for(int j=1; j<=m; j++)
				{
					//�²���ĵ�·��
					N.now[j] = E.now[j] + B[E.x[i]][j];
				}
				int ld = 0;//�²���ĵ�·���ܶ�
				for(int j=1; j<=m; j++)
				{
					if(N.now[j]>0 && total[j]!=N.now[j])
					{
						ld++;
					}
				}
				N.cd = max(ld,E.cd);
				if(N.cd<bestd)//���ܲ������õ�Ҷ�ӽڵ�
				{
					N.x = new int[n+1];
					N.s = E.s + 1;
					for(int j=1;j<=n;j++)
					{
						N.x[j] = E.x[j];
					}
					N.x[N.s] = E.x[i];
					N.x[i] = E.x[N.s];
					H.Insert(N);
				}
				else
				{
					delete []N.now;
				}
			}
			delete []E.x;
		}//��ɵ�ǰ�ڵ���չ
		if(H.Size() == 0)
		{
			return bestd;//����չ�ڵ�
		}
		H.DeleteMin(E);			
	}while(E.cd<bestd);
 
	//�ͷ���С�������нڵ�
	do
	{
		delete []E.x;
		delete []E.now;
		if(H.Size() == 0)
		{
			break;
		}
		H.DeleteMin(E);
	}while(true);
	return bestd;
}