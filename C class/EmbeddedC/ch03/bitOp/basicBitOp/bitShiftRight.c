#include <stdio.h>

#define  MAX(i,j)   (i)>(j)? i:j


int main()
{
	int a = 10;

	printf("%d", MAX(10, 5));
	printf ("%d(0x%08X) : Right Shift 1 -> %d(0x%08X)\n", a, a, a>>1, a>>1);
	printf ("%d(0x%08X) : Right Shift 2 -> %d(0x%08X)\n", a, a, a>>2, a>>2);
	printf ("%d(0x%08X) : Right Shift 3 -> %d(0x%08X)\n", a, a, a>>3, a>>3);
	return 0;
}
