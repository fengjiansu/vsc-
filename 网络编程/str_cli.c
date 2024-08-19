#include"unp.h"
void str_cli(FILE *fp, int sockfd)
{
    char readline[MAXLINE], recvline[MAXLINE];
    while(Fgets(readline, MAXLINE, fp) != NULL)
    {
        Writen(sockfd, readline, strlen(readline));
        if (Readline(sockfd, recvline, MAXLINE) == 0)
        {
            err_quit("str_cli: server terminated prematurely");
        }
        Fputs(recvline, stdout);
    }
}