#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void inputMember(node** HEAD, node** TAIL)
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
    if (*HEAD == NULL) {
        *HEAD = *TAIL = temp;
    } else {
        *TAIL->next = temp; //NULL to tmp(new address)
        *TAIL=temp; //TAIL is pointing temp
    }
}

void outputMember()
{
    printf("outputMember()\n");
    //print from HEAD to TAIL
    node *temp = HEAD;//not HEAD->next
    while (temp){ //(temp != NULL)
        printf("\tid: %d\n", temp->id);
        temp = temp->next;
    }
}
