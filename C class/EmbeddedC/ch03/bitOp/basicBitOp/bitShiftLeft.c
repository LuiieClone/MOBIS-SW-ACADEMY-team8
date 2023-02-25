#include <stdio.h>

int main()
{
	int a = 1;
	printf ("%d(0x%08X) : Left Shift 1 -> %d(0x%08X)\n", a, a, a<<1, a<<1);
	printf ("%d(0x%08X) : Left Shift 2 -> %d(0x%08X)\n", a, a, a<<2, a<<2);
	printf ("%d(0x%08X) : Left Shift 3 -> %d(0x%08X)\n", a, a, a<<3, a<<3);
	return 0;
}
