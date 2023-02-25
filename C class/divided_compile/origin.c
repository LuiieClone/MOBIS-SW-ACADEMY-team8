#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

node* HEAD, * TAIL;

int main()
{
	int choice;
	
	HEAD = TAIL = NULL;
	
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

	node* temp;
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
	node *temp = HEAD;//not HEAD->next
	while (temp){ //(temp != NULL)
		printf("id: %d\n", temp->id);
		temp = temp->next;
	}
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

void save()
{
	FILE* fp;
	fp = fopen("menu.dat", "wb");
	if(fp == NULL) {
		fprintf(stderr, "cannot open!\n");
		return;
	}

	node *temp = HEAD;//not HEAD->next
	while (temp != NULL){ //(cur != NULL)
		fwrite(temp, sizeof(node), 1, fp);
		temp = temp->next;
	}
	printf("save complete\n");
	fclose(fp);
}

void load() {
	FILE *fp;
	fp = fopen("menu.dat", "rb");
	if(fp == NULL){
		fprintf(stderr, "Cannot Open!");
		return;
	}
	if(feof(fp))
		return;

	node* temp;
	while(1) {
		temp = (node*)malloc(sizeof(node));
		fread(temp, sizeof(node), 1, fp);
		if(feof(fp))
			break;

		temp->next = NULL;
		if (HEAD == NULL) {
			HEAD = TAIL = temp;
		}
		else {
			TAIL->next = temp ;
			TAIL = temp;
		}
	}	
	printf("load complete\n");
	fclose(fp);
}
