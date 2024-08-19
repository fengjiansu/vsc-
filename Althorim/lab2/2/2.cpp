#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int Board[10000][10000];//棋盘
int tile=0;//L型骨牌的编号
void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    //tr 棋盘左上角行号 tc 棋盘左上角列号
    //dr 特殊方格行号   dc 特殊方格列号
    //size =2^k 棋盘规格为2^k
    if(size==1)
    return;
    int t=tile++;     //L型骨牌号
    int s=size/2;     //分割棋盘
    //覆盖左上角棋盘
    if(dr<tr+s&&dc<tc+s)        //特殊方格在此棋盘中
    ChessBoard(tr,tc,dr,dc,s);
    else
    {//此棋盘中无特殊方格
        Board[tr+s-1][tc+s-1]=t;                //用t号L行骨牌覆盖右下角
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);       //覆盖其余方格
    }
    //覆盖右上角子棋盘
    if(dr<tr+s&&dc>=tc+s)       //特殊方格在此棋盘中             
    ChessBoard(tr,tc+s,dr,dc,s);
    else
    {
        Board[tr+s-1][tc+s]=t;                  //用t号L行骨牌覆盖左下角
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);      //覆盖其余方格
        
    }
    //覆盖左下角
    if(dr>=tr+s&&dc<tc+s)
    ChessBoard(tr+s,tc,dr,dc,s);     //特殊方格在此棋盘中  
    else{
        Board[tr+s][tc+s-1]=t;                  //用t号L行骨牌覆盖右上角
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);      //覆盖其余方格
    }   
    //覆盖右下角
    if(dr>=tr+s&&dc>=tc+s)
    ChessBoard(tr+s,tc,dr,dc,s);     //特殊方格在此棋盘中  
    else
    {
        Board[tr+s][tc+s]=t;                    //用t号L行骨牌覆盖左上角
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);      //覆盖其余方格
    }  
}
int main()
{
    int k=2;
    int size=(int)pow(2,k);
int dr=1;
int dc=0;
Board[dr][dc]=-1;   //将特殊方格设为-1
int tr=0,tc=0;
ChessBoard(tr,tc,dr,dc,size);
for(int i=0;i<size;i++)
{
    for(int j=0;j<size;j++)
    printf("%d",Board[j][i]); //输出最后的结果
    printf("\n");
}
    return 0;
}