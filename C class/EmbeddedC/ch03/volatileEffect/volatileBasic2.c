#include <stdio.h>

int cnt1=1;
volatile int cnt2=1;
	
int main(void)
{
	while(1) {
		if(cnt1 == 0x10) break;
		cnt1++;
	}
	
	while(1) {
		if(cnt2 == 0x10) break;
		cnt2++;
	}
	
	return 0;
}
