#include <stdio.h>

void printData(void *data, int size, int type)
{
	int i;

	for(i=0; i<size; i++) {
		switch(type) {
			case sizeof(char) : 
				printf("%c\n", *((char *)data + i));
				break;
			case sizeof(short) : 
				printf("%hd\n", *((short *)data + i));
				break;
			case sizeof(int) : 
				printf("%d\n", *((int *)data + i));
				break;
		}
	}
}

int main(void)
{
	char charArr[] = "abcde";
	short shortArr[] = {1,2,3,4};
	int intArr[] = {10,20,30};
	void *p;

	p = (void *)charArr;
	printData(p, 5, sizeof(char));
	printf("-------------------------\n");
	p = (void *)shortArr;
	printData(p, 4, sizeof(short));
	printf("-------------------------\n");
	p = (void *)intArr;
	printData(p, 3, sizeof(int));

	return 0;
}
