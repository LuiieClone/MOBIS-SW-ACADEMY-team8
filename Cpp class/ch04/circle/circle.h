#ifndef _CIRCLE_H_
#define _CIRCLE_H_

class Circle{
    public:
    int radius;
    double getArea();
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r) { radius=r; } //인라인
};
#endif