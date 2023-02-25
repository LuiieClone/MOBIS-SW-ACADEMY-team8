#include <iostream>
using namespace std;

struct StructCircle{
private:
    int radius;
public:
    //구조체의 생성자
    StructCircle(int r) { radius = r; };
    double getArea();
};

double StructCircle::getArea() {
    return 3.14*radius*radius;
}

int main()
{
    StructCircle waffle(10);
    cout << waffle.getArea() << endl;
    return 0;
}