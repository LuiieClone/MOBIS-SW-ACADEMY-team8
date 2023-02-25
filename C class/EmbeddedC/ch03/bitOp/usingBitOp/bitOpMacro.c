#include <stdio.h>

// loc 위치의 비트를 1로 설정
#define bitSet(data, loc) ((data) | (1 << (loc-1))) //

// loc 위치의 비트를 0으로 초기화
#define bitClear(data, loc) ((data) & ~(1 << (loc-1))) //

// loc 위치의 비트를 0-->1, 1-->0 으로 설정
#define bitToggle(data, loc) ((data) ^ (1 << (loc-1))) //

int main(void)
{
	unsigned short data;
	int pos, menu;
	
	printf("Input a short integer data => ");
	scanf("%hd", &data);
	while(1) {
		do {
			printf("Bit Test(1.Bit Set, 2.Bit Clear, 3.Bit Toggle, 4:Quit) => ");
			scanf("%d", &menu);
		} while (menu<1 || menu>4);
		if(menu == 4) break;
		
		do {
			printf("Bit Position(0~15, -1:Quit) => ");
			scanf("%d", &pos);
		} while (menu<-1 || menu>15);
		if(pos == -1) continue;
		
		switch(menu) {
			case 1:
				printf("Bit_%d Set of 0x%04X => 0x%04X\n", pos, data, bitSet(data, pos));
				break;
			case 2:
				printf("Bit_%d Clear of 0x%04X => 0x%04X\n", pos, data, bitClear(data, pos));
				break;
			case 3:
				printf("Bit_%d Toggle of 0x%04X => 0x%04X\n", pos, data, bitToggle(data, pos));
				break;
		} 
	}
	return 0;
}
