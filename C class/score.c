#include <stdio.h>

int inputMember();
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
//input variables: name, score1~3
//exit when "..."
int inputMember()
{
	int i;
	for(i=0 ; i<30 ; i++){
		scanf("%s", students[i]);
		if(students[i][0] == '.' && students[i][1] == '.' && students[i][2] == '.'){
			printf("End of the Input\n");
			break;
		}
		scanf("%d", &score1[i]);
		scanf("%d", &score2[i]);
		scanf("%d", &score3[i]);
	}
	return i;
}	
//print name, avg. score
void outputMember(int result)
{
	for(int j=0 ; j<result ; j++){
		int sum = score1[j] + score2[j] + score3[j];
		printf("%s, %d\n", students[j], sum%result);
	}
}
