#include <stdio.h>

int main()
{
	char c;
	double d;
	char* cp = &c;
	double* dp = &d;

	printf("%p %p\n", cp, dp);
	printf("%p %p\n", &c, &d);
	//printf("%p %p\n", c, d);
	cp++; dp++;
	printf("%p %p\n", cp, dp);
	printf("%p %p\n", &c, &d);
	return 0;
}
