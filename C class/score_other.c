#include <stdio.h>

void inputMember();
void outputMember();

char students[30][20];
int score1[30];
int score2[30];
int score3[30];


int main()
{
	int choice;
	int result;

	do {
		printf("1. input\n");
		printf("2. output\n");
		printf("3. exit\n");
		scanf("%d", &choice); getchar();
		if(choice == 1){
			result = inputMember();
		}
		else if(choice==2){
			outputMember(result);
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

//Define functions
void inputMember()
{
	for (int i = 0; i < 30; i++){
		scanf("%s", name[i]);
		if (name[i][0] == '.' && name[i][1] == '.' && name[i][2] == '.')
			break;
		scanf("%d %d %d", &music[i], &art[i], &pe[i]);
	}		
}

void outputMember()
{
	for (int i = 0; i < 30; i++){
		if (name[i][0] == '.' && name[i][1] == '.' && name[i][2] == '.')
			break;
		printf("%s %d\n", name[i], (music[i] + art[i] + pe[i]) / 3);
	}	
}
