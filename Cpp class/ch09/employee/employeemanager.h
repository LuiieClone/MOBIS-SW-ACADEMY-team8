#ifndef _EmployeeManager_H
#define _EmployeeManager_H

#include <string>
#include "employee.h"
#include "temporaryworker.h"

using namespace std;

class EmployeeManager
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeManager();
    ~EmployeeManager();
    void addEmployee(Employee* emp); // 사원 (월급여, 일급여) 등록
    void showAllSalary() const; // 전 사원 이름, 급여 출력
    void showTotalSalary() const; // 급여 총 합 계산
};

#endif