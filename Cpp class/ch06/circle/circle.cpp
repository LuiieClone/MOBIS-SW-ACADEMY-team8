#include <iostream>
#include "circle.h"

using namespace std;

// static 변수 생성. 전역 공간에 생성
int Circle::left_circle = 0; // 10으로 초기화
int Circle::getNumOfCircles() {
        return left_circle;
    };

Circle::Circle()
{
    radius = 1;
    cout<< "radius: "<< radius << endl;
    left_circle += 1;
}
Circle::Circle(int r)
{
    radius = r;
    cout<< "radius: "<< radius << endl;
    left_circle += 1;
}
Circle::~Circle()
{
    cout<< "radius destroyed" << endl;
    left_circle -= 1;
}

double Circle::getArea(){
    return 3.14*radius*radius;
}
Circle Circle::getCircle()
{
    Circle tmp(30);
    return tmp;
}