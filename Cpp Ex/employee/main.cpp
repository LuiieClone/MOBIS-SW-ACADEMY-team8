#include <iostream>
#include <string>
using namespace std;
#include "employeeManager.h"

int main(void)
{
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeManager manager;

	// 직원 등록
	manager.addEmployee(new TempWorker("kim", 1000));
	manager.addEmployee(new Employee("lee", 1500));
	manager.addEmployee(new Employee("park", 2000));

	// 이번 달에 지불해야 할 급여의 정보
	manager.showAllSalary();	

	// 이번 달에 지불해야 할 급여의 총합
	manager.showTotalSalary();
	return 0;
}