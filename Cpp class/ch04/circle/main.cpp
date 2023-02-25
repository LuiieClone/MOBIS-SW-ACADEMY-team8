#include <iostream>
#include "circle.h"
using namespace std;

int main()
{
/*
    //객체 이름으로 멤버 접근
    Circle donut;
    cout<< donut.getArea() << endl;

    //객체 포인터로 멤버 접근
    Circle *p;
    p = &donut;
    cout<< p->getArea() << endl;
    cout<< (*p).getArea() << endl;
*/
    //객체 배열
    Circle sausage[3];

    sausage[0].setRadius(1);
    sausage[1].setRadius(10);
    sausage[2].setRadius(3.14);

    for(int i=0 ; i<3 ; i++)
        cout<< sausage[i].getArea() << endl;    

    //포인터를 이용해 객체 배열 접근하기
    Circle *p;
    p = sausage;
    for(int i=0 ; i<3 ; i++)
        cout<< p->getArea() << endl;  
        p++;
    return 0;
}