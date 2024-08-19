#include "unp.h"
int main(int argc, char **argv)
{
    int        listenfd, connfd;
    struct     sockaddr_in servaddr, cliaddr;
    char       buff[MAXLINE];

    socklen_t clilen;
    pid_t childpid;

    listenfd = Socket(AF_INET, SOCK_STREAM,0);

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family  = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(4396);

    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    for( ; ; )
    {
        clilen = sizeof(cliaddr);    // 指向套接口地址结构的长度
        connfd = Accept(listenfd,(SA*)&cliaddr, &clilen); //返回客户的协议地址,。以及该地址的大小(套接口地址内的准确字节数)
        if((childpid=Fork())==0)
        {
        Close(listenfd);
        str_tran(connfd);
        exit(0);
        }
        Close(connfd);  // 父进程不关闭listenfd
    }
    return 0;
}