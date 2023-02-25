#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack s(10);
  
    s.push(123);
    s.push(456);
    s.show();

    Stack s2 = s;
    cout << "s2: ";
    s2.show();

  /*
    int mm = 0;
    int& m = mm;

    s.push(1);
    s.push(2);
    s.pop(m);
    cout << m << endl;
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop(m);
    cout << m << endl;
    s.push(6);
    s.push(7);
    s.show();
*/
}