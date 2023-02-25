#include <stdio.h>

int main()
{
	unsigned char data1 = 'A', data2, data3;
	unsigned char mask;;
	
	data1 = 'A';
	mask = 0xDA;
	data2 = data1 ^ mask;
	printf("0x%02X ^ 0x%02X = 0x%02X\n", data1, mask, data2);
	data3 = data2 ^ mask;
	printf("0x%02X ^ 0x%02X = 0x%02X\n", data2, mask, data3);

	mask = 'a' - 'A';
	data1 = 'a' ^ mask;
	printf("%c ^ 0x%02X = %c\n", 'a', mask , data1);
	data1 = 'A' ^ mask;
	printf("%c ^ 0x%02X = %c\n", 'A', mask , data1);
	return 0;
}
