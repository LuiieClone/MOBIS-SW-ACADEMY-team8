#include <stdio.h>

void printData_1(char data[][80], int size)
{
	int i;

	for(i=0; i<size; i++) {
		printf("%s,%s\n", data[i], *data+(i*80));
	}
}

void printData_2(char *data[], int size)
{
	int i;

	for(i=0; i<size; i++) {
		printf("%s,%s\n", data[i], *(data+i));
	}
}

int main(void)
{
	char arr1[3][80] = {"kim", "lee", "park"};
	char *p1[3] = {"kim", "lee", "park"};
	
	printData_1(arr1, 3);
	printf("-------------------------\n");
	printData_2(p1, 3);
	printf("-------------------------\n");
	
	return 0;
}
