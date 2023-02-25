#include <iostream>
using namespace std;

//함수 선언
class Rect;
//1. 전역함수
bool equals(Rect r, Rect s);

//함수 정의
class Rect
{
    int width, height;
public:
    Rect(int width, int height)
    {
        this->width = width;
        this->height = height;
    };
    //프렌드 1유형
    friend bool equals(Rect r, Rect s);
};
//외부함수
bool equals(Rect r, Rect s) 
{
    if(r.width == s.width && r.height == s.height)
        return true;
    else
        return false;
};

int main()
{
    Rect a(3, 4), b(4, 5);
    if(equals(a, b))
        cout << "Equal!" << endl;
    else
        cout << "NOT Equal!" << endl;
    return 0;
}