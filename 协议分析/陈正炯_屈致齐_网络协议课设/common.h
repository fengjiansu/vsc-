#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <map>
#include <string>
#include <assert.h>
#include <stdint.h>
#include <pthread.h>
#include <poll.h>
#include <limits.h>
#include <netinet/tcp.h>
#include<netinet/in.h>
#include <net/if.h>
#include <signal.h>
#include <assert.h>
#include <sys/ioctl.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/epoll.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "log.h"
#include "ip.h"
#include "icmp.h"

void printData(const unsigned char* data, int len, int cols = 16);
int printIp(const struct ip *ip, int len);
void printIcmp(struct icmp* icmp, int len);
void printUnreachable(struct icmp_unreachable* icmp, int len);

#endif // __COMMON_H_HH
