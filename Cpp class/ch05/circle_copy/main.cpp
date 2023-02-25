#include <iostream>
#include "circle.h"
using namespace std;

int main()
{
    Circle c;
    cout << c.getArea() << endl;

    c = getCircle();
    cout << c.getArea() << endl;
}