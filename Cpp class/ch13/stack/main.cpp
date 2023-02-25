#include <iostream>
using namespace std;

#include "stack.h"

int main() {
    MyStack intStack;
    try {
        intStack.push(100); // 푸시 100
        intStack.push(200); // 푸시 200
        cout << intStack.pop() << endl; // 팝 200
        cout << intStack.pop() << endl; // 팝 100
        cout << intStack.pop() << endl; // "Stack Empty" 예외 발생
    }
    catch(const char* s) {
        cout << "예외 발생 : " << s << endl;
    }
}