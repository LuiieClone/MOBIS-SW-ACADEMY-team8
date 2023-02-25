#include <stdio.h>

int swapInt(int *dest, int *src);

int main()
{
	int score[] = {10, 20};

	printf("before : score ==> %d,%d\n", score[0], score[1]);
	swapInt(&score[0], &score[1]);
	printf("-------------------------------------\n");
	printf("after  : score ==> %d,%d\n", score[0], score[1]);
}

int swapInt(int *dest, int *src)
{
	int t;
	
	t = *dest;
	*dest = *src;
	*src = t;
}
