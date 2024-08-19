#ifndef __ICMP_H__
#define __ICMP_H__

// icmp 头部
struct icmp {
	uint8_t icmp_type;
	uint8_t icmp_code;
	uint16_t icmp_cksum;
	// 不同类型的 icmp 报文，后面都不一样
};

// icmp 回显报文头部
struct icmp_echo {
	uint8_t icmp_type;
	uint8_t icmp_code;
	uint16_t icmp_cksum;
	uint16_t icmp_id;
	uint16_t icmp_seq;
};

// icmp 不可达报文头部
struct icmp_unreachable {
	uint8_t icmp_type;
	uint8_t icmp_code;
	uint16_t icmp_cksum;
	uint32_t icmp_unused;
};

#endif //__ICMP_H__

