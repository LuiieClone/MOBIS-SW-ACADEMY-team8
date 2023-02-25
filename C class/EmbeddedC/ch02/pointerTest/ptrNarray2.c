#include <stdio.h>

int main(void)
{
	short arr1[5] = {1, 2, 3, 4, 5};
	short *p1 = arr1;
	int i;

	for(i=0, p1=arr1; i<5; i++, p1++) {
		printf("%d,%d\n", arr1[i], *p1);
	}
	
	for(i=0, p1=arr1; i<5; i++, p1++) {
		printf("%d,%d\n", *p1, *(arr1+i));
	}

	return 0;
}
