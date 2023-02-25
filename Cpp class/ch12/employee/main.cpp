#include <iostream>
#include <fstream>
#include "employee.h"
#include "temporaryworker.h"
#include "employeemanager.h"

using namespace std;


int main(void)
{
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeManager manager;

    // 직원 등록
    ifstream fin("sawon.txt");
    // const char* file = "sawon.txt";
    // ifstream fin(file);
    manager.fileRead(fin);

    // 이번 달에 지불해야 할 급여의 정보
    cout << "**showAllSalary" <<endl;
    manager.showAllSalary();
    cout << "**showSomeSalary" <<endl;
    manager.showSomeSalary();

    // 이번 달에 지불해야 할 급여의 총합
    manager.showTotalSalary();
    return 0;
}