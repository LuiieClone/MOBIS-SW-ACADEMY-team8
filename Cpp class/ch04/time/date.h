#ifndef _STACK_H_
#define _STACK_H_

class Date{
private:
    int year;
    int month;
    int day;
  
public:
    Date();
    Date(string s);
    Date(int y, int m, int d);

    void show();
    int getYear();
    int getMonth();
    int getDay();
};
#endif