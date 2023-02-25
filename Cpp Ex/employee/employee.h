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
 
	virtual int getPay() const;
	virtual void showSalary() const;
};
#endif