#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int Board[10000][10000];//����
int tile=0;//L�͹��Ƶı��
void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    //tr �������Ͻ��к� tc �������Ͻ��к�
    //dr ���ⷽ���к�   dc ���ⷽ���к�
    //size =2^k ���̹��Ϊ2^k
    if(size==1)
    return;
    int t=tile++;     //L�͹��ƺ�
    int s=size/2;     //�ָ�����
    //�������Ͻ�����
    if(dr<tr+s&&dc<tc+s)        //���ⷽ���ڴ�������
    ChessBoard(tr,tc,dr,dc,s);
    else
    {//�������������ⷽ��
        Board[tr+s-1][tc+s-1]=t;                //��t��L�й��Ƹ������½�
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);       //�������෽��
    }
    //�������Ͻ�������
    if(dr<tr+s&&dc>=tc+s)       //���ⷽ���ڴ�������             
    ChessBoard(tr,tc+s,dr,dc,s);
    else
    {
        Board[tr+s-1][tc+s]=t;                  //��t��L�й��Ƹ������½�
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);      //�������෽��
        
    }
    //�������½�
    if(dr>=tr+s&&dc<tc+s)
    ChessBoard(tr+s,tc,dr,dc,s);     //���ⷽ���ڴ�������  
    else{
        Board[tr+s][tc+s-1]=t;                  //��t��L�й��Ƹ������Ͻ�
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);      //�������෽��
    }   
    //�������½�
    if(dr>=tr+s&&dc>=tc+s)
    ChessBoard(tr+s,tc,dr,dc,s);     //���ⷽ���ڴ�������  
    else
    {
        Board[tr+s][tc+s]=t;                    //��t��L�й��Ƹ������Ͻ�
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);      //�������෽��
    }  
}
int main()
{
    int k=2;
    int size=(int)pow(2,k);
int dr=1;
int dc=0;
Board[dr][dc]=-1;   //�����ⷽ����Ϊ-1
int tr=0,tc=0;
ChessBoard(tr,tc,dr,dc,size);
for(int i=0;i<size;i++)
{
    for(int j=0;j<size;j++)
    printf("%d",Board[j][i]); //������Ľ��
    printf("\n");
}
    return 0;
}