#include <stdio.h>

int main()
{
	printf(" 10 ^ 7 = %d \n", 10 ^ 7 );
	printf(" 0x0A ^ 0x07 = 0x%02X \n", 0x0A ^ 0x07);
	printf(" 123 ^ 456 = %d \n", 123 ^ 456 );
	printf(" 0xFFFF ^ 0x0000 = 0x%04X \n", 0xFFFF ^ 0x0000 );
	printf(" 0xFFFF ^ 0x715B = 0x%04X \n", 0xFFFF ^ 0x715B );
	return 0;
}
