#include <iostream>
#include "circle.h"
using namespace std;

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