#include <stdio.h>

void printData(short *data, int size)
{
	int i;

	for(i=0; i<size; i++) {
		printf("%d,%d\n", data[i], *(data+i));
	}
}

int main(void)
{
	short arr1[5] = {1, 2, 3, 4, 5};
	short arr2[] = {10, 20, 30};
	short arr3[4] = {100, 200, 300, 400};
	short *p[] = {arr1, arr2, arr3};
	int i;

	for(i=0; i<3; i++) {
		printData(p[i], 3);
		printf("-------------------------\n");
	}

	return 0;
}
