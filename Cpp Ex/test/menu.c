#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

node* HEAD, * TAIL;

int main()
{
	int choice;

	HEAD=TAIL=NULL;

    load();

	do {
		printf("1. input\n");
		printf("2. output\n");
		printf("3. exit\n");
		printf("Select --> ");
		scanf("%d", &choice); getchar();
		switch(choice) {
			case 1:
				inputMember(); // 함수 호출
				break;
			case 2:
				outputMember(); // 함수호출
				break;
			case 3:
				save();
				destroy_list();
				printf("program end\n");
				break;
			default:
				printf("Wrong Choice\n");
				break;
		}

	} while( choice!=3 );
	return 0;
}

// 함수 정의 
void destroy_list()
{
	struct node* temp, *lpNext;

	temp=HEAD;
	while(temp) {
		lpNext=temp->next;
		free(temp);
		temp=lpNext;
	}
	
}



