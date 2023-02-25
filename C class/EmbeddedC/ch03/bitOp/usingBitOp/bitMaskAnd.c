#include <stdio.h>

int main()
{
	unsigned char data = 0x5B;
	unsigned char mask_h = 0xF0, mask_l = 0x0F;
	unsigned char mask_0 = 0x01, mask_1 = 0x02, mask_2 = 0x04, mask_3 = 0x08;
	unsigned char mask_4 = 0x10, mask_5 = 0x20, mask_6 = 0x40, mask_7 = 0x80;
	
	printf(" 0x%02X & 0x%02X = 0x%02X \n", data, mask_l, data & mask_l);
	printf(" 0x%02X & 0x%02X = 0x%02X \n", data, mask_h, data & mask_h);
	printf(" 0x%02X & 0x%02X = 0x%02X \n", data, mask_0, data & mask_0);
	printf(" 0x%02X & 0x%02X = 0x%02X \n", data, mask_1, data & mask_1);
	printf(" 0x%02X & 0x%02X = 0x%02X \n", data, mask_2, data & mask_2);
	printf(" 0x%02X & 0x%02X = 0x%02X \n", data, mask_3, data & mask_3);
	printf(" 0x%02X & 0x%02X = 0x%02X \n", data, mask_4, data & mask_4);
	printf(" 0x%02X & 0x%02X = 0x%02X \n", data, mask_5, data & mask_5);
	printf(" 0x%02X & 0x%02X = 0x%02X \n", data, mask_6, data & mask_6);
	printf(" 0x%02X & 0x%02X = 0x%02X \n", data, mask_7, data & mask_7);
	return 0;
}
