#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

extern node* HEAD,*TAIL;


void save()
{
    FILE* fp;

    fp = fopen("menu.dat", "wb");
    if(fp==NULL) {
        fprintf(stderr, "can not open menu.dat\n");
        return;
    }

    node* temp;
    temp=HEAD;

    while(temp) {
        fwrite(temp, sizeof(node), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
}

void load()
{

    FILE* fp;

    fp = fopen("menu.dat", "rb");
    if(fp==NULL) {
        fprintf(stderr, "can not open menu.dat\n");
        return;
    }

    if(feof(fp)) return;

    node* temp;

    while(1) {
        temp=(struct node*) malloc(sizeof(struct node));
        fread(temp, sizeof(node),1, fp);
        if(feof(fp)) break;
        temp->next=NULL;
        if(HEAD==NULL) {        // first node
            HEAD=TAIL=temp;
        } else {                //
            TAIL->next=temp;
            TAIL=temp;
        }
    }
}

