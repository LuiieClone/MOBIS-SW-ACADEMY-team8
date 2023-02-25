#include <stdio.h>
#include <stdlib.h>

void inputMember();
void outputMember();
void distroy();

typedef struct node{
	int id;
	struct node* next;
} Node;

//struct node* HEAD, * TAIL;
Node* HEAD, * TAIL;

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

void inputMember()
{
	printf("inputMember()\n");

	//struct node* temp;
	Node* temp;
	temp = (struct node*) malloc(sizeof(struct node));
	printf("ID? ");
	scanf("%d", &temp->id); getchar();
//Linked List connect with conditions
	//initialiazation
	temp->next = NULL;
	//is this node is the first one?
	if (HEAD == NULL) {
		HEAD = TAIL = temp;
	} else { 
		TAIL->next = temp; //NULL to tmp(new address)
		TAIL=temp; //TAIL is pointing temp
	}
}

void outputMember()
{
	printf("outputMember()\n");
	//print from HEAD to TAIL
	//struct node *curr = HEAD;//not HEAD->next
	Node *curr = HEAD;//not HEAD->next
	while (curr){ //(cur != NULL)
		printf("id: %d\n", curr->id);
		curr = curr->next;
	}
}


void distroy()
{
	//struct node* temp, * lpNext;
	Node* temp, * lpNext;
	temp = HEAD;
	while(temp) { 
		lpNext = temp->next;
		free(temp);
		temp = lpNext;
	}
}
