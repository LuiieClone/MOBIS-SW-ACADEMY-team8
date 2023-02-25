// Control(Handler) Class : 사원 객체의 처리 기능을 위한 클래스  
#ifndef _EMPLOYEEMANAGER_H
#define _EMPLOYEEMANAGER_H

#include <iostream>
#include <string>
using namespace std;
#include "employee.h"
#include "tempworker.h"

class EmployeeManager
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeManager();
    ~EmployeeManager();
	void addEmployee(Employee* emp);
	void showAllSalary() const;
	void showTotalSalary() const;
};

#endif