#ifndef _STACK_H_
#define _STACK_H_

class Stack{
    public:
    int max_size;
    int top = 0;
    int *pArray;
    //여기 선언해놓고 main에서 또 
    //int *pArray = int[n];선언하면
    //Segmentation fault

    void pop();
    void push(int num);
    void getSize();
    void setSize(int num);
    void getTop();
    
    Stack();
    Stack(int n);
    ~Stack();
};
#endif