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

    bool pop(int &n);
    void push(int num);
    void getSize();
    void setSize(int num);
    void getTop();
    void show();
    
    Stack(const Stack& c);
    Stack();
    Stack(int n);
    ~Stack();
};
#endif