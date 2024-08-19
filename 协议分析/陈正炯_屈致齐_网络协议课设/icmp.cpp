#include "common.h"
using namespace std;
#define BUF_SIZE 4096
char buf[BUF_SIZE];

int main(int argc, char* argv[]) {
	struct sockaddr_in from,from1;
	struct ip *ip,*ip1;
	struct icmp *icmp, *icmp1;
	socklen_t len,len1;
	int nr, nr1,sockfd, sockfd1,iphlen,iphlen1, icmplen,icmplen1;
	
	sockfd1=socket(PF_PACKET, SOCK_RAW, htons( 0x3));
	if (sockfd1 < 0) 
		ERR_EXIT("socket");
	for (;;) {

		//send
		do
		{
		char buf1[BUF_SIZE];
		len1 = sizeof(from1);
		nr1 = recvfrom(sockfd1, buf1, BUF_SIZE, 0, (struct sockaddr*)&from1, &len1);
		if (nr1 < 0) {
			ERR_EXIT("recvfrom");
		}
		
		ip1 = (struct ip*)(buf1+14);
		}while(ip1->ip_p!=1);
		ERR_PRINT("\n---------- from: %s ----------\n", inet_ntoa(from1.sin_addr));
		nr1=nr1-14;
		printIp(ip1, nr1);
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



