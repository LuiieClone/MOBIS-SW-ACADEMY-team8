#include <stdio.h>
#define bit_check(number, position) ((number>>(position-1))&1)

int main()
{
	int n, pos;
	scanf("%d %d", &n, &pos);
	int answer = bit_check(n, pos);
	printf("n: %d, pos: %d\n", n, pos);
	printf("answer: %d\n", answer);
    return 0;
}
