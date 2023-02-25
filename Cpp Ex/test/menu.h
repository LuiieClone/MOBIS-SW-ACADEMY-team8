#ifndef _MENU_H_
#define _MENU_H_
// 함수 선언
void inputMember();
void outputMember();
void destroy_list();
void load();
void save();

typedef struct node {
    int id;
    struct node* next;
} node;
#endif

