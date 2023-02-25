#include <iostream>
#include <string>
using namespace std;

// 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
class Point {
protected:
    int x, y; //한 점 (x,y) 좌표값
public:
    // int x, y; //한 점 (x,y) 좌표값
    Point();
    Point(int x, int y);
    ~Point();
    void set(int x, int y) { this->x = x; this->y = y; };
    void showPoint() {
        cout << "(" << x << "," << y << ")" << endl;
    };
};
Point::Point(){ cout << "부모, Point 기본 생성자" << endl; };
Point::Point(int x, int y)
{
    cout << "부모, Point 매개변수 생성자" << endl;
    this->x = x;
    this->y = y;
};
Point::~Point(){  };

class ColorPoint: public Point
{
    string color;
public:
    ColorPoint();
    ColorPoint(int x, int y) : Point(x, y)
    {
        cout << "자식, ColorPoint 매개변수 생성자" << endl;
    };
    ~ColorPoint();
    void setColor(string color) { this->color = color; };
    void showColorPoint();
    bool equals(ColorPoint p);
};
ColorPoint::ColorPoint(){ cout << "자식, ColorPoint 기본 생성자" << endl; };
ColorPoint::~ColorPoint(){  };

void ColorPoint::showColorPoint(){
    cout << color << ": ";
    //Point로부터 상속받은 함수 호출
    showPoint();
};
bool ColorPoint::equals(ColorPoint p) {
    if(x == p.x && y == p.y && color == p.color)
        return true;
    else
        return false;
};

int main() {
    Point p; // 기본 클래스의 객체 생성
    p.set(2,3);
    // p.x = 5;
    // p.y = 5;
    p.showPoint();

    // ColorPoint cp; // 파생 클래스의 객체 생성
    ColorPoint cp(30, 40); // 파생 클래스의 객체 생성
    // cp.x = 10;
    // cp.y = 10;
    // cp.set(3,4);
    // cp.setColor("Red");
    cp.showColorPoint();

    ColorPoint cp2;
    cp2.set(3,4);
    cp2.setColor("Red");
    cout << ((cp.equals(cp2))?"true":"false");
}
/*
int main()
{
    // Point p; // 기본 클래스의 객체 생성
    ColorPoint cp; // 파생 클래스의 객체 생성
    // cp.set(3,4); // 기본 클래스의 멤버 호출
    // cp.setColor("Red"); // 파생 클래스의 멤버 호출
    // cp.showColorPoint(); // 파생 클래스의 멤버 호출
    // ColorPoint* pDer = &cp;
    ColorPoint* pDer;
    // Point* pBase = pDer; //업 캐스팅
    Point* pBase = &cp; //다운 캐스팅

    pBase->set(3, 4);
    pBase->showPoint();

    pDer = (ColorPoint*) pBase;
    pDer->setColor("Blue");
    pDer->showColorPoint();

    return 0;
}*/