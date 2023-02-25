#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    Stack s = Stack(n);
    while(1){
        break;
    }
    s.push(1);
    s.push(2);
    s.pop();
    s.push(3);
    s.setSize(4);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.pop();
    s.pop();

}