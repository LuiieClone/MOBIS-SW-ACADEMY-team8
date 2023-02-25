#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

extern node* HEAD, *TAIL;

// 함수 정의
void inputMember()
{
    printf("inputMember()\n");

    node* temp;

    temp=(struct node*) malloc(sizeof(struct node));
    printf("id? ");
    scanf("%d", &temp->id); getchar();
    temp->next=NULL;

#ifdef DEBUG
    printf("id = %d, next : %p\n", temp->id, temp->next);
#endif


    if(HEAD==NULL) {        // first node
        HEAD=TAIL=temp;
    } else {                //
        TAIL->next=temp;
        TAIL=temp;
    }

}

void outputMember()
{
    printf("outputMember()\n");
    node* temp;

    temp=HEAD;
    while(temp) {
        printf("id : %d\n", temp->id);
        temp=temp->next;
    }
}


