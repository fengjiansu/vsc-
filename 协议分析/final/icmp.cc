#include "common.h"

#define BUF_SIZE 4096
char buf[BUF_SIZE];
char buf1[BUF_SIZE];

int main(int argc, char* argv[]) {
	struct sockaddr_in from,from1;
	struct ip *ip,*ip1;
	struct icmp *icmp, *icmp1;
	socklen_t len,len1;
	int nr, nr1,sockfd, sockfd1,iphlen,iphlen1, icmplen,icmplen1;
	
	sockfd1=socket(PF_PACKET, SOCK_RAW, htons( 0x3));
	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0) 
		ERR_EXIT("socket");
	if (sockfd1 < 0) 
		ERR_EXIT("socket");
	for (;;) {
		len = sizeof(from);
		
		nr = recvfrom(sockfd, buf, BUF_SIZE, 0, (struct sockaddr*)&from, &len);
		if (nr < 0) {
			ERR_EXIT("recvfrom");
		}
		

		// 打印ip地址
		
		ERR_PRINT("---------- from: %s ----------\n", inet_ntoa(from.sin_addr));

		
		// buf 是 ip 首部开始第一个字节的地址
		
	  	ip = (struct ip*)buf;	
		// ip 头部长度
		
		iphlen = (ip->ip_hl) << 2;

		// 拿到 icmp 首地址
		
		icmp = (struct icmp*)((char*)ip + iphlen);
		// icmp 报文长度
		
		icmplen = nr - iphlen;
		
		// 输出icmp报头
		printIcmp(icmp, icmplen);

		len1 = sizeof(from1);
		nr1 = recvfrom(sockfd1, buf1, BUF_SIZE, 0, (struct sockaddr*)&from1, &len1);
		
		if (nr1 < 0) {
			ERR_EXIT("recvfrom");
		}
		printf("%s",buf1);
		ERR_PRINT("\n----------send from: %s ----------\n", inet_ntoa(from1.sin_addr));
		ip1 = (struct ip*)(buf1-14);
		
		iphlen1 = (ip1->ip_hl) << 2;
		printf("%d%d",ip1->ip_v,ip1->ip_hl);
		if(ip1->ip_p==1)
		{
			icmp1 = (struct icmp*)((char*)ip1 + iphlen1);
			icmplen1 = nr1 - iphlen1;
			printIcmp(icmp1, icmplen1);
		}
		
		

	}
}



