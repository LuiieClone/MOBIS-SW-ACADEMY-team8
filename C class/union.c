#include <stdio.h>

int main()
{
	union iptype {
		char ip1[4];
		int ip2;
	} ipaddr;
	
	//printf("size = %ld\n", sizeof(ipaddr));
	ipaddr.ip2 = 0x12345678;
	printf("%x %x %x %x\n", ipaddr.ip1[0], ipaddr.ip1[1] , ipaddr.ip1[2] , ipaddr.ip1[3]);
    return 0;
}

