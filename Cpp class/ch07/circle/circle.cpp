#include <iostream>
#include "circle.h"

using namespace std;

Circle::Circle()
{
    radius = 1;
}
Circle::Circle(int r)
{
    radius = r;
}
Circle::~Circle()
{
}

void Circle::show()
{
    cout<< "radius: "<< radius << endl;
};

Circle Circle::operator+(Circle op2) {
    Circle tmp; // 임시 객체 생성
    tmp.radius = this->radius + op2.radius;
    return tmp; // 더한 결과 리턴
}
bool Circle::operator==(Circle op2) {
    if (radius == op2.radius)
        return 1;
    else
        return 0; // 더한 결과 리턴
}
Circle& Circle::operator+=(Circle op2) {
    radius = radius + op2.radius;
    return *this; // 더한 결과 리턴
}

Circle& Circle::operator++() {
    ++radius;
    return *this;
}
Circle Circle::operator++(int x) {
    Circle tmp = *this;
    radius++;
    return tmp;
}

Circle& Circle::operator--() {
    radius--;
    return *this;
}
Circle Circle::operator--(int x) {
    Circle tmp = *this;
    radius--;
    return tmp;
}

//friend로 전역 함수 불러오기
ostream& operator<<(ostream& os, const Circle& c)
{
    os << c.radius;
    return os;
}

istream& operator>>(istream& is, Circle& c)
{
    is >> c.radius;
    return is;
}