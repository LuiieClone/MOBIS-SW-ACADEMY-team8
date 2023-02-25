#include <iostream>

using namespace std;

class Point{
private:
    int width, height;
public: 
    Point();
    Point(int x, int y);
    ~Point();

    void setXY(int x, int y);
    void show();
    static int x_max, y_max;
};

// static 변수 생성. 전역 공간에 생성
int Point::x_max = 1024;
int Point::y_max = 768;

Point::Point()
{
    width = 0;
    height = 0;
}
Point::Point(int x, int y)
{
    width = x;
    height = y;
}
Point::~Point()
{
    cout<< "Point destroyed" << endl;
};

void Point::setXY(int x, int y){
    if(x < x_max)
        width = x;
    else
        width = x_max;
    
    if(y < y_max)
        height = y;
    else
        height = y_max;
};

void Point::show()
{
    cout << "x: " << width <<", y: " << height << endl;
};



int main()
{
    // static 멤버 함수이용하여 최대 스크린 크기를 1024x768로 설정
    Point p1(100, 100);
    p1.show();

    p1.setXY(2000, 1000);
    p1.show();

    Point p2;
    p2.setXY(512,1000);
    p2.show();

    return 0;
}