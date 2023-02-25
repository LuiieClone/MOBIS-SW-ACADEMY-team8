#include <iostream>
#include <string>
#include "date.h"
using namespace std;

int main() {
    //Date variable_name
    Date today; // 오늘 날짜
    Date birth(2014, 3, 20); // 2014년 3월 20일
    // Date independenceDay("1945/8/15"); // 1945년 8월 15일
    // independenceDay.show();
    cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}