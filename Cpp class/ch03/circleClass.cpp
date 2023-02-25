#include <iostream>
using namespace std;

//선언부
class Circle{
    public:
    int radius;
    double getArea();
    //생성자 선언
    Circle();
    Circle(int r);
    //소멸자 선언
    ~Circle();
};
////생성자
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
////소멸자
Circle::~Circle()
{
    cout<< "radius destroyed" << endl;
}

//구현부
double Circle::getArea(){
    return 3.14*radius*radius;
}

int main()
{
    Circle donut; //객체 생성
    donut.radius = 1; //멤버 변수 접근
    double area = donut.getArea(); //멤버 함수 호출
    cout<< area << endl;

    Circle pizza(30);
    area= pizza.getArea();
    cout<< area << endl;

    return 0;
}