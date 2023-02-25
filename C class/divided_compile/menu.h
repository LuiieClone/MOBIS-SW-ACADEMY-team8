#ifndef _MENU_H_
#define _MENU_H_

void inputMember();
void outputMember();
void distroy();
void load();
void save();

typedef struct node{
    int id;
    struct node* next;
} node;

#endif
