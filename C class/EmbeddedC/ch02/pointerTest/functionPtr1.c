#include <stdio.h>

typedef int (*FP)(int, int);

int add(int d1, int d2) {
	return d1+d2;
}
int sub(int d1, int d2) {
	return d1-d2;
}
int mul(int d1, int d2) {
	return d1*d2;
}
int div(int d1, int d2) {
	if(d2) return d1/d2;
	else { printf("Zero Dived Error!!\n"); return 0; }
}

int main(void)
{
	int no, rst;
	//int (*fp)(int, int);
	FP fp;
	
	while(1) {
		do {
			printf("\nSelect(1.add, 2.sub, 3.mul, 4.div, 0.quit) => ");
			scanf("%d", &no);
		} while(no<0 || no>4);

		switch(no) {
			case 1: fp = add; break;
			case 2: fp = sub; break;
			case 3: fp = mul; break;
			case 4: fp = div; break;
			default : return 0;
		}
		rst = fp(30, 10);
		printf("rst => %d\n", rst);
	}

	return 0;
}
