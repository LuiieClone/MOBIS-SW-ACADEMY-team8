#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

// 사원 객체의 속성 및 제어를 위한 클래스
class Employee
{
protected:
	string name;
	int salary;
public:
	Employee(string name, int money);
 
	int getPay() const;
	void showSalary() const;
};

class PermanentWorker: public Employee
{
public:
	PermanentWorker(string name, int money): Employee(name, money) {};
};

class TemporaryWorker: public Employee
{
private:
	int date;
public:
	TemporaryWorker(string name, int money, int date): Employee(name, money)
	{
		this->date = date;
	};
	int getPay() const;
};
#endif