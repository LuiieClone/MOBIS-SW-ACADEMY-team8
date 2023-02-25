#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
{
	int choice;
	
	node* HEAD, * TAIL;
	
	HEAD = TAIL = NULL;
	
	load();

	do {
		printf("1. input\n");
		printf("2. output\n");
		printf("3. exit\n");
		scanf("%d", &choice); getchar();
		if(choice == 1){
			inputMember(&HEAD, &TAIL);
		}
		else if(choice==2){
			outputMember();
		}
		else if(choice==3){
			save();
			distroy();
			printf("End of the program\n");
			break;
		}
		else{
			printf("Wrong Input!\n");
		}
	} while(1);
	
	return 0;
}

void distroy()
{
	node* temp, * lpNext;
	temp = HEAD;
	while(temp) { 
		lpNext = temp->next;
		free(temp);
		temp = lpNext;
	}
}	
