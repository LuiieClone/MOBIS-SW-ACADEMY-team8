#include <iostream>
#include "circle.h"

using namespace std;

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
Circle Circle::getCircle()
{
    Circle tmp(30);
    return tmp;
}