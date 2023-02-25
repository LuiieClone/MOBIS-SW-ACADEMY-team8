#include "stack.h"

Stack::Stack() : size(10), top(0) 
{
    size = 10;
    top = 0;
    pStack = new int[10]; // 10개짜리 배열 포인터 메모리 할당
}

Stack::~Stack()
{
    delete [] pStack;
}

bool Stack::push(int n)
{
    if (top < 0 || size == top)
        return false;
    pStack[top] = n;
    top++;
    return true;
}

bool Stack::pop(int *n)
{
    if (top < 0 || size == 0)
        return false;
    top--;
    *n = pStack[top];
    return true;
}

void Stack::setSize(int n)    // n : +10
{
    int* tStack = new int[size+n];
    for(int i=0; i<size; i++)
        tStack[i] = pStack[i];
    delete[] pStack;
    pStack = tStack;
    size += n;
}

 