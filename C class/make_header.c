#include <stdio.h>
#include <stdlib.h>
#include "make_header.h"

Node* HEAD, * TAIL;

int main()
{
	int choice;
	
	load();

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

void inputMember()
{
	printf("inputMember()\n");

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
	Node *curr = HEAD;//not HEAD->next
	while (curr){ //(cur != NULL)
		printf("id: %d\n", curr->id);
		curr = curr->next;
	}
}


void distroy()
{
	Node* temp, * lpNext;
	temp = HEAD;
	while(temp) { 
		lpNext = temp->next;
		free(temp);
		temp = lpNext;
	}
}

void save()
{
	FILE* fp;
	fp = fopen("menu.dat", "wb");
	if(fp == NULL) {
		fprintf(stderr, "cannot open!\n");
		return;
	}
	Node *temp = HEAD;//not HEAD->next
	while (temp){ //(cur != NULL)
		fwrite(temp, sizeof(struct node), 1, fp);
		temp = temp->next;
	}
	fclose(fp);
}

void load() {
	FILE *fp;
	fp = fopen("menu.dat", "rb");
	Node* tmp_p;
	while(1) {
		tmp_p = (Node*)malloc(sizeof(Node));
		if(fread(tmp_p, sizeof(Node), 1, fp) == 0) {
			free(tmp_p);
			break;
		}	
		if (HEAD == NULL) {
			HEAD = TAIL = tmp_p;
		}
		else {
			TAIL->next = tmp_p ;
			TAIL = tmp_p;
		}
	}	
	printf("load complete\n");
	fclose(fp);
}
