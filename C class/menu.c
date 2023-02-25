#include <stdio.h>

void inputMember();
void outputMember();

int main()
{
	int choice;

	do {
		printf("1. input\n");
		printf("2. output\n");
		printf("3. exit\n");
		scanf("%d", &choice); getchar();
		if(choice == 1){
			inputMember();
		}
		else if(choice==2){
			outputMember();
		}
		else if(choice==3){
			printf("End of the program\n");
			break;
		}
		else{
			printf("Wrong Input!\n");
		}
	} while(1);
	
	return 0;
}

void inputMember()
{
	printf("inputMember()\n");
}

void outputMember()
{
	printf("outputMember()\n");
}
