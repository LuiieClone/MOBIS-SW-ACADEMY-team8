#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(int radius=1) { this->radius = radius; }
    int getRadius() { return radius; }
};

template <class T>
void myswap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}


int main()
{
    Circle a(10), b;
    cout << "a: " << a.getRadius() << ", b:" << b.getRadius() << endl;
    myswap(a, b);
    cout << "a: " << a.getRadius() << ", b:" << b.getRadius() << endl;
}