#include"unp.h"
void str_tran( int sockfd)
{
    char readline[MAXLINE];
    int tmp = 'a'-'A';
    if (Readline(sockfd, readline, MAXLINE) == 0)
    {
        err_quit("str_cli: server terminated prematurely");
    }
    for(int i=0; i<strlen(readline); i++)
    {
           if(readline[i]>='a'&&readline[i]<='z')
           {
               readline[i]-=tmp;
           }
           else if(readline[i]>='A'&&readline[i]<='Z')
           {
               readline[i]+=tmp;
           }
    }
    Writen(sockfd, readline, strlen(readline));
}