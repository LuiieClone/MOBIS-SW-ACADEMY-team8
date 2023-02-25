#include <stdio.h>

void printData_1(short data[])
{
	int i;

	for(i=0; i<5; i++) {
		printf("%d,%d\n", data[i], *(data+i));
	}
}

void printData_2(short *data)
{
	int i;

	for(i=0; i<5; i++) {
		printf("%d,%d\n", data[i], *(data+i));
	}
}

int main(void)
{
	short arr1[5] = {1, 2, 3, 4, 5};
	short *p1 = arr1;
	int i;

	for(i=0; i<5; i++) {
		printf("%d,%d\n", arr1[i], p1[i]);
		printf("%d,%d\n", *(arr1+i), *(p1+i));
	}

	printf("-------------------------\n");
	printData_1(arr1);
	printf("-------------------------\n");
	printData_2(arr1);

	return 0;
}
