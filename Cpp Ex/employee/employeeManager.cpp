// Control(Handler) Class : 사원 객체의 처리 기능을 위한 클래스  
#include "employeeManager.h"

EmployeeManager::EmployeeManager() { 
    this->empNum = 0; 
}

void EmployeeManager::addEmployee(Employee* emp)
{
	empList[empNum++]=emp;
}

void EmployeeManager::showAllSalary() const
{
	for(int i=0; i<empNum; i++)
		empList[i]->showSalary();
}

void EmployeeManager::showTotalSalary() const
{
	int sum=0;
	for(int i=0; i<empNum; i++)
		sum+=empList[i]->getPay();
	cout<<"salary sum: "<<sum<<endl;
}

EmployeeManager::~EmployeeManager()
{
	for(int i=0; i<empNum; i++)
		delete empList[i];
}