#include <iostream>
#include "stack.h"
using namespace std;

int main(){
    Stack *s = new Stack;
    //Stack s;

    for (int i=0; i<60; i++){
        if (s->getSize() == s->getTop())    
            s->setSize(10);
        s->push(i);
    }

    int num;
    for (int i=0; i<60; i++){
        if (s->pop(&num))
            cout << num << endl;
    }

    delete s;
    return 0;
}


