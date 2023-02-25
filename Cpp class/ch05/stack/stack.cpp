#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

Stack::Stack(const Stack& s)
{
    this->max_size = s.max_size;
    this->top = s.top;
    this->pArray = new int[this->top];

    // for(int i ; i<(this->top) ; i++)
    //     this->pArray[i] = s.pArray[i];

    memcpy(this->pArray, s.pArray, this->top);
}
Stack::Stack()
{
    max_size = 10;
    pArray = new int[max_size];
    cout<< "stack max_size: "<< max_size << endl;
}
Stack::Stack(int n)
{
    max_size = n;
    pArray = new int[max_size];
    cout<< "stack max_size: "<< max_size << endl;
}
Stack::~Stack()
{
    delete [] pArray;
    cout<< "stack destroyed" << endl;
}

//post indexing
/*
void Stack::pop() //using index
{
    cout<< "pop: " << pArray[--top] << endl;
};
bool Stack::pop(int *n) //using pointer
{
    if (top < 0 || max_size == 0)
        return false;-
    *n = pArray[--top];
    return true;
};*/
bool Stack::pop(int &m) //using reference
{
    if (top < 0 || max_size == 0)
        return false;
    m = pArray[--top];
    return true;
};

void Stack::push(int num)
{
    if(top < max_size){
        cout<< "push: " << num << endl;
        pArray[top++] = num;
    }
    else{
        cout<< "**Memory is full!" << endl;
        max_size = max_size + 1;
        cout<< "**Memory is increased to " << max_size << endl;
        setSize(max_size);
        pArray[top++] = num;

    }
};
void Stack::getSize()
{
    cout<< "max_size: " << max_size << endl;
};
void Stack::setSize(int num)
{
    max_size = num;
    cout<< "new max_size: " << max_size << endl;
    //swap!
    int* tmp = pArray;
    pArray = new int[num];
    pArray = tmp;

};
void Stack::getTop()
{
    cout<< "top: " << top << endl;
    
};
void Stack::show()
{
    cout<< "show:";
    for(int i=0 ; i<top ; i++)
        cout<< " " << pArray[i];
    cout << endl;
};