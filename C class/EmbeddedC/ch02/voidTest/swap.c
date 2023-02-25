#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* x, int* y);

int main()
{
	int x, y;
	x = 10; y = 20;
	swap(&x, &y);
	printf("%d %d\n", x, y);

	double nx = 10; double ny = 20;
	swap(&nx, &ny);
	printf("%d %d\n", nx, ny);

    return 0;
}

void swap(void* x, void* y)
{
	void* type;

	type =(void *) x;
	*x = *y;
	*y = t;
}
