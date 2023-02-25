#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

extern node* HEAD, * TAIL;

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
