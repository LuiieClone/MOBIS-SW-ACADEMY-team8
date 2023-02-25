#include <stdio.h>
#include <stdlib.h>

//typedef void *(*FP)(int, int);

void *memAlloc(int nelem, int size)
{
	void *p;

	p = malloc(nelem * size);
	return p;
}

int main(void)
{
	void * (*fp)(int, int);          //FP fp;
	int *data;
	int i;

	fp = memAlloc;
	data = (int *)fp(3, sizeof(int));
	for(i=0; i<3; i++) {
		data[i] = 10*i;
	}

	for(i=0; i<3; i++) {
		data[i] = 10*i;
		printf("%d, %d\n", data[i], *(data+i));
	}
	free(data);
	return 0;
}
