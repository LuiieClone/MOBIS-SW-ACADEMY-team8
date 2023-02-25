#ifndef _EmployeeManager_H
#define _EmployeeManager_H

#include <string>
#include <vector>
#include "employee.h"
#include "temporaryworker.h"

using namespace std;

class EmployeeManager
{
private:
    vector<Employee*> empList;
public:
    EmployeeManager();
    ~EmployeeManager();
    void addEmployee(Employee* emp); // 사원 (월급여, 일급여) 등록
    void showAllSalary(); // 전 사원 이름, 급여 출력
    void showSomeSalary(int lim);
    void showTotalSalary(); // 급여 총 합 계산
};

#endif