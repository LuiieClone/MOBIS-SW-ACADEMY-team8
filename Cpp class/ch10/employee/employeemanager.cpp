#include <iostream>
#include <vector>
#include <algorithm>
#include "employee.h"
#include "employeemanager.h"

using namespace std;

EmployeeManager::EmployeeManager() { }
EmployeeManager::~EmployeeManager() { }
void EmployeeManager::addEmployee(Employee* emp) // 사원 (월급여, 일급여) 등록
{
    empList.push_back(emp);
}  
void EmployeeManager::showAllSalary() // 전 사원 이름, 급여 출력
{
    // vector<Employee*>::iterator it;
    sort(empList.begin(), empList.end(), [](Employee* a, Employee*b){return a->getName() < b->getName();});
    for_each(empList.begin(), empList.end(), [](Employee* e){cout << "name : "<< e->getName();	cout<<" 월 급여 : "<< e->getPay() <<endl;});
}
void EmployeeManager::showSomeSalary(int lim) // 전 사원 이름, 급여 출력
{
    for_each(empList.begin(), empList.end(), [lim](Employee* e){ if(e->getPay() > lim) cout << "name : "<< e->getName() << endl; });
}
void EmployeeManager::showTotalSalary() // 급여 총 합 계산
{
    int total = 0;
    // vector<Employee*>::iterator it;
    for(auto it=empList.begin() ; it!=empList.end() ; it++){
        total += (*it)->getPay();
    }
    cout<<"show total salary : "<< total << endl;
}