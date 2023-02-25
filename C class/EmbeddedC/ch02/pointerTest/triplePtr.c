#include <stdio.h>
int main(void)
{
	int n1 = 10, n2 = 20;
	int *ip1 = &n1, *ip2 = &n2;
	int **ipp = &ip1;
	
	printf("n1:%d, n2:%d, *ip1:%d, *ip2:%d\n", n1, n2, *ip1, *ip2);
	printf("&n1:%p, ip1:%p\n", &n1, ip1);
	printf("&ip1:%p, ipp:%p\n", &ip1, ipp);
	printf("n1:%d, *ip1:%d, **ipp:%d\n", n1, *ip1, **ipp);
	printf("---------------------------------------------\n");
	n1++; n2++;
	printf("&n1:%p, ip1:%p\n", &n1, ip1);
	printf("&ip1:%p, ipp:%p\n", &ip1, ipp);
	printf("n1:%d, *ip1:%d, **ipp:%d\n", n1, *ip1, **ipp);
	printf("---------------------------------------------\n");
	ipp = &ip2;
	printf("&n2:%p, ip2:%p\n", &n2, ip2);
	printf("&ip2:%p, ipp:%p\n", &ip2, ipp);
	printf("n2:%d, *ip2:%d, **ipp:%d\n", n2, *ip2, **ipp);
	return 0;
}
