#include <iostream>
#include "stack.h"

using namespace std;

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
void Stack::pop()
{
    cout<< "pop: " << pArray[--top] << endl;
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