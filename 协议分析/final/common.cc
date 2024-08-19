#include "common.h"

void printData(const unsigned char* data, int len, int cols) {
	int i;
	for (i = 0; i < len; ++i) {
		if (i % cols == 0) LOG("| %02x ", data[i]);
		else LOG("%02x ", data[i]);
		if ((i + 1) % cols == 0) LOG("|\n");
	}

	// 补齐空白
	if (i == len && i % cols != 0) {
		while(1) {
			if (i % cols != 0)
				LOG("-- ");
			else { 
				LOG("|\n");
				break;
			}
			++i;
		}
	}
}
int printIp(const struct ip *ip, int len) {
	int iphlen, flag, offset;
	unsigned char *data;

	iphlen = ip->ip_hl<< 2;
	data = (unsigned char*)ip + iphlen;

	len -= iphlen;


	ERR_PRINT("------------ ip header ------------\n");
	WARNING("version:          %d(0x%01x)\n", ip->ip_v,ip->ip_v);
	WARNING("header len:       %d(0x%01x)\n", iphlen, ip->ip_hl);
	WARNING("type of service:  %d(0x%02x)\n", ip->ip_tos, ip->ip_tos);
	WARNING("total len:        %d(0x%04x)\n", ntohs(ip->ip_len),ntohs(ip->ip_len));
	WARNING("id:               %d(0x%04x)\n", ntohs(ip->ip_id), ntohs(ip->ip_id));
	flag = ntohs(ip->ip_off) & 0xe000;
	WARNING("fragment flag:    [RF:%d, DF:%d, MF:%d]\n"
			, flag & IP_RF ? 1:0, flag & IP_DF ? 1:0, flag & IP_MF ? 1:0);
	WARNING("fragment offset:  %d(0x%03x)\n", ntohs(ip->ip_off) & 0x1fff,ntohs(ip->ip_off) & 0x1fff);
	WARNING("ttl:              %d(0x%02x)\n", ip->ip_ttl, ip->ip_ttl);
	WARNING("protocol:         %d(0x%02x)\n", ip->ip_p, ip->ip_p);
	WARNING("checksum:         %d(0x%04x)\n", ntohs(ip->ip_sum),ntohs(ip->ip_sum));
	WARNING("src ip:           %s(0x%08x)\n", inet_ntoa(ip->ip_src),ip->ip_src);
	WARNING("dst ip:           %s(0x%08x)\n", inet_ntoa(ip->ip_dst),ip->ip_dst);
	ERR_PRINT("------------ data ------------\n");
	printData(data, len);
	return 0;
}
void printUnreachable(struct icmp_unreachable* icmp_unreachable, int len)
{
	int hlen;
	hlen = sizeof(struct icmp_unreachable);
	WARNING("unused:          0x%08x\n", icmp_unreachable->icmp_unused);
	printIp((struct ip*)((unsigned char*)icmp_unreachable + hlen),len - hlen);
}
void printEcho(struct icmp_echo* icmp_echo, int len)
{
	unsigned char *data;
	int hlen;
	hlen = sizeof(struct icmp_echo);
	data = (unsigned char*)icmp_echo + hlen;
	len -= hlen;
	WARNING("id:              %d(0x%04x)\n", icmp_echo->icmp_id,icmp_echo->icmp_id);
	WARNING("seq:             %d(0x%04x)\n", icmp_echo->icmp_seq,icmp_echo->icmp_seq);
	ERR_PRINT("------------ data ------------\n");
	printData(data, len);
}
void printIcmp(struct icmp* icmp, int len) {
	int hlen;
	

	ERR_PRINT("------------ icmp header ------------\n");
	WARNING("type:             %d(0x%02x) ", icmp->icmp_type, icmp->icmp_type);
	
	switch(icmp->icmp_type){
		case 0:
			WARNING("Echo Reply\n"); 
			break;
		case 3:
			WARNING("Destination Unreachable\n"); 
			break;
		case 5:
			WARNING("Redirect Message\n");
			break;
		case 8:
			WARNING("Echo Request\n"); 
			break;
		case 9:
			WARNING("Router Advertisement\n");
			break;
		case 10:
			WARNING("Router Solicitation\n");
			break;
		case 11:
			WARNING("Time Exceeded\n");
			break;
		case 12:
			WARNING("Parameter Problem: Bad IP header\n");
			break;
		case 13:
			WARNING("Timestamp\n");
			break;
		case 14:
			WARNING("Timestamp Reply\n");
			break;
		case 15:
			WARNING("Information Request\n");
			break;
		default:
			break;
	}
	
	WARNING("code:             %d(0x%02x) ", icmp->icmp_code, icmp->icmp_code);
	
	switch (icmp->icmp_type){
		case 0:
			switch (icmp->icmp_code){
				case 0:
					WARNING("Echo reply(used to ping)\n");
					break;
				default:
					break;
			}
			break;
		case 3:
			switch (icmp->icmp_code){
				case 0:
					WARNING("Destination network unreachable\n");
					break;
				case 1:
					WARNING("Destination host unreachable\n");
					break;
				case 2:
					WARNING("Destination protocol unreachable\n");
					break;
				case 3:
					WARNING("Destination port unreachable\n");
					break;
				case 4:
					WARNING("Fragmentation required, and DF flag set\n");
					break;
				case 5:
					WARNING("Source route failed\n");
					break;
				case 6:
					WARNING("Destination network unknown\n");
					break;
				case 7:
					WARNING("Destination host unknown\n");
					break;
				case 8:
					WARNING("Source host isolated\n");
					break;
				case 9:
					WARNING("Network administratively prohibited\n");
					break;
				case 10:
					WARNING("Host administratively prohibited\n");
					break;
				case 11:
					WARNING("Network unreachable for ToS\n");
					break;
				case 12:
					WARNING("Host unreachable for ToS\n");
					break;
				case 13:
					WARNING("Communication administratively prohibited\n");
					break;
				case 14:
					WARNING("Host Precedence Violation\n");
					break;
				case 15:
					WARNING("Precedence cutoff in effect\n");
					break;
				default:
					break;
			}
			break;
		case 5:
			switch (icmp->icmp_code){
				case 0:
					WARNING("Redirect Datagram for the Network\n");
					break;
				case 1:
					WARNING("Redirect Datagram for the Host\n");
					break;
				case 2:
					WARNING("Redirect Datagram for the ToS & network\n");
					break;
				case 3:
					WARNING("Redirect Datagram for the ToS & host\n");
					break;
				default:
					break;
			}
		case 8:
			switch (icmp->icmp_code){
				case 0:
					WARNING("Echo request(used to ping)\n");
					break;
				default:
					break;
			}
			break;
		case 9:
			switch (icmp->icmp_code){
				case 0:
					WARNING("Router Advertisement\n");
					break;
				default:
					break;
			}
			break;
		case 10:
			switch (icmp->icmp_code){
				case 0:
					WARNING("Router discovery/selection/solicitation\n");
					break;
				default:
					break;
			}
			break;
		case 11:
			switch (icmp->icmp_code){
				case 0:
					WARNING("TTL expired in transit\n");
					break;
				case 1:
					WARNING("Fragment reassembly time exceeded\n");
					break;
				default:
					break;
			}
			break;
		case 12:
			switch (icmp->icmp_code){
				case 0:
					WARNING("Pointer indicates the error\n");
					break;
				case 1:
					WARNING("Missing a required option\n");
					break;
				case 2:
					WARNING("Bad length\n");
					break;
				default:
					break;
			}
			break;
		case 13:
			switch (icmp->icmp_code){
				case 0:
					WARNING("Timestamp\n");
					break;
				default:
					break;
			}
			break;
		case 14:
			switch (icmp->icmp_code){
				case 0:
					WARNING("Timestamp reply\n");
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}

	WARNING("checksum:         %d(0x%04x)\n", icmp->icmp_cksum, icmp->icmp_cksum);
	
	hlen = sizeof(struct icmp);
	if(icmp->icmp_type==0||icmp->icmp_type==8)
	{
		printEcho((struct icmp_echo*)icmp , len-hlen);
	}
	else if(icmp->icmp_type==3)
	{
		printUnreachable((struct icmp_unreachable*)icmp,len - hlen);
	}
	
}
