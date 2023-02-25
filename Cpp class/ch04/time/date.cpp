#include <iostream>
#include <string>
#include <time.h>
#include "date.h"

using namespace std;

Date::Date()
{
    time_t rawtime;
    time( &rawtime );

    struct tm *info;
    info = localtime( &rawtime );
    printf("today: %s", asctime(info));
}
Date::Date(string s)
{
    string tmp = s.substr(0,4);
    year = stoi(tmp);
    tmp = s.substr(5,2);
    month = stoi(tmp);
    tmp = s.substr(7,2);
    day = stoi(tmp);
    cout << "year:  " << year << "month:  " << month << "day:  " << day << endl;
}
Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

void Date::show()
{
    cout << year << ',' << month << ',' << day << endl;
};
int Date::getYear()
{
    return year;
};
int Date::getMonth()
{
    return month;
};
int Date::getDay()
{
    return day;
};