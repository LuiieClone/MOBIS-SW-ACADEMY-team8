#ifndef _CIRCLE_H_
#define _CIRCLE_H_

class Circle{
public:    
    int radius;
    Circle();
    Circle(int r);
    ~Circle();
    
    void show();

    Circle operator+ (Circle op2);
    bool operator== (Circle op2);
    Circle& operator+= (Circle op2);

    Circle& operator++ ();
    Circle operator++ (int x);
    Circle& operator-- ();
    Circle operator-- (int x);

    friend ostream& operator<<(ostream& os, const Circle& c);
    friend istream& operator>>(istream& is, Circle& c);
};

#endif