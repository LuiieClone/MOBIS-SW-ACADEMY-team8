#include <stdio.h>

int main()
{
	printf(" ~10 = 0x%08X \n", ~10 );
	printf(" ~7 = 0x%08X \n", ~7 );
	printf(" ~0xFFFFFFFF = 0x%08X \n", ~0xFFFFFFFF );
	printf(" ~0x00FF00FF = 0x%08X \n", ~0x00FF00FF );
	printf(" ~0xF0F0F0F0 = 0x%08X \n", ~0xF0F0F0F0 );
	printf(" ~1 = 0x%08X \n", ~1 );
	printf(" -1 = 0x%08X \n", ~1 + 1 );
	return 0;
}
