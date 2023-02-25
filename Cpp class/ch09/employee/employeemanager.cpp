#include <iostream>
#include "employee.h"
#include "employeemanager.h"

using namespace std;

EmployeeManager::EmployeeManager()
{
    empNum = 0;
}
EmployeeManager::~EmployeeManager()
{
    
}
void EmployeeManager::addEmployee(Employee* emp) // 사원 (월급여, 일급여) 등록
{
    empList[empNum] = emp;
    empNum += 1;
}  
void EmployeeManager::showAllSalary() const // 전 사원 이름, 급여 출력
{
    for(int i=0 ; i<=empNum; i++){
        (*empList[i]).showSalary();
        //포인터 배열에 들어있는 포인터 배열이 가리키는 값
    }
}
void EmployeeManager::showTotalSalary() const // 급여 총 합 계산
{
    int total = 0;
    for(int i=0 ; i<=empNum; i++){
        total += (*empList[i]).getPay();
    }
    cout<<"show total salary : "<< total;
}