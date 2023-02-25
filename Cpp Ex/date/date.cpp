#include <iostream>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

class Date {
	int day;
	int month;
	int year;
public:
	Date();
	Date(int y, int m, int d);
	Date(string s);
	void show();
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
};

Date::Date() {
	time_t current;
	time(&current);
	tm *today = localtime(&current);
	year = today->tm_year + 1900;
	month = today->tm_mon + 1;
	day = today->tm_mday;
}

Date::Date(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(string s) {
	int index1 = s.find("/");
	string y = s.substr(0, index1);
	int index2 = s.find("/", index1+1);
	string m = s.substr(index1+1, index2-index1-1);
	string d = s.substr(index2+1, s.length());

	year = stoi(y);
	month = stoi(m);
	day = stoi(d);

	// 기존의 C 라이브러리 함수인 atoi()를 이용하는 방법
	//year = atoi(y.c_str());
	//month = atoi(m.c_str());
	//day = atoi(d.c_str());
}

void Date::show() {
	cout << year << "년" << month << "월" << day << "일" << endl;
}

int main() {
	Date today;
	cout << today.getYear() << "," << today.getMonth() << ',' << today.getDay() << endl;

	Date birth(2014, 3, 20); // 2014년 3월 20일
	Date independenceDay("1945/8/15"); // 1945년 8월 15일
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}
