#include <stdio.h>

int main(void)
{
	int a[2][3] = { {1,2,3}, {4,5,6}};

	int i,j;
	int *p = a[0], (*q)[3]=a;

	printf("%p\n", *a );
	printf("%p\n", *a+1 );
	printf("%p\n", *a+2 );
	printf("%p\n", *(a+1) );
	printf("%p\n", *(a+1)+1 );
	printf("\n");

	printf("%p\n", a );
	printf("%p\n", a+1 );
	printf("\n");
	/*
	printf("%x\n", p );
	printf("%x\n", p+1 );
	printf("%x\n", p+2 );
	printf("%x\n", p+3 );
	printf("%x\n", p+4 );
	printf("\n");
	printf("%x\n", q );
	printf("%x\n", *q+1 );
	printf("%x\n", *q+2 );
	printf("%x\n", q+1 );
	printf("%x\n", *(q+1)+ 1);
	printf("%x\n", *(q+1)+ 2);
	printf("\n");

	for(i=0; i<2; i++)
		for(j=0;j<3; j++) {
			printf("%x   %d\n", &a[i][j], a[i][j]);
			printf("%x   %d\n", *(a+i)+j, a[i][j]);
			printf("%x   %d\n", p+i*(sizeof(a[0])/sizeof(a[0][0]))+j, a[i][j]);
			printf("%x   %d\n", *(q+i)+j, *(*(q+i)+j));
		}
		*/
}
