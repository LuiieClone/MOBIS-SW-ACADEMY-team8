#include <iostream>
using namespace std;

class Circle{
    public:
    int radius;
    double getArea();
    Circle();
    Circle(int r);
    ~Circle();
};
Circle::Circle()
{
    radius = 1;
    cout<< "radius: "<< radius << endl;
}
Circle::Circle(int r)
{
    radius = r;
    cout<< "radius: "<< radius << endl;
}
Circle::~Circle()
{
    cout<< "radius destroyed" << endl;
}
double Circle::getArea(){
    return 3.14*radius*radius;
}

//전역 객체
Circle globalDonut(300);
Circle globalPizza(400);
void func()
{
    Circle funcDonut(5000);
    Circle funclPizza(6000);
}
int main()
{
    Circle maincDonut;
    Circle mainPizza(2);
    func();
    return 0;
}