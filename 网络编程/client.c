#include "unp.h"
int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;

    char *s;

    if(argc != 2)
    {
        err_quit("usage: a.out <IPaddress>");
    }
    sockfd=Socket(AF_INET, SOCK_STREAM,0);
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(4396);
    Inet_pton(AF_INET, argv[1],&servaddr.sin_addr);
    
    Connect(sockfd, (SA*)&servaddr, sizeof(servaddr));
    str_cli(stdin, sockfd); // stdin 文件指针 标志输入
    Close(sockfd);
    return 0;

}