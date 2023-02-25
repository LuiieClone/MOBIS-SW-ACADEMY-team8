#ifndef _CIRCLE_H_
#define _CIRCLE_H_

class Circle{
    public:
    int radius;
    
    Circle();
    Circle(int r);
    ~Circle();
    
    double getArea();
    Circle getCircle();
    void setRadius(int r) { radius=r; } //인라인
};
#endif