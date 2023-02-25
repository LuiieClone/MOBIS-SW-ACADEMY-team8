#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	char name[20];
	int mus;
	int art;
	int exc;
};

void inputMember(struct student *st);
void outputMember(struct student *st);

int main()
{
	int choice;
	struct student st[30];

	do {
		printf("1. input\n");
		printf("2. output\n");
		printf("3. exit\n");
		scanf("%d", &choice); getchar();
		if(choice == 1){
			inputMember(st);
		}
		else if(choice==2){
			outputMember(st);
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
void inputMember(struct student *st)
{
	for(int i=0 ; i<30 ; i++){
		scanf("%s", st[i].name);
		if(strcmp(st[i].name, "...") == 0){
			printf("End of the Input\n");
			break;
		}
		scanf("%d %d %d", &st[i].mus, &st[i].art, &st[i].exc);
	}
}	
//print name, avg. score
void outputMember(struct student *st)
{
	for(int j=0 ; j<30 ; j++){
		int sum = st[j].mus + st[j].art + st[j].exc;
		printf("%s, %d\n", st[j].name, sum%3);
	}
}
