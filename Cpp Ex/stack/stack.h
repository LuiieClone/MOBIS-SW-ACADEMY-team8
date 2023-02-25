#ifndef _STACK_H
#define _STACK_H

class Stack{
    int size;               // 기본 10
    int top;
    int* pStack;
public:
    Stack();
    ~Stack();
    bool push(int n);
    bool pop(int *n);
    void setSize(int n);    // n : +10
    int getSize() { return size; }
    int getTop() { return top; }
};

#endif