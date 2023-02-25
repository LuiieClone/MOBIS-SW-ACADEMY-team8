#include <iostream>
#include "employee.h"
#include "temporaryworker.h"
#include "employeemanager.h"

using namespace std;

/*
int main() {

    PermanentWorker p("Aa", 1000);
    TemporaryWorker t("Bb", 10, 30);

    p.showSalary();
    t.showSalary();
    return 0;
}
*/
int main(void)
{
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeManager manager;

    // 직원 등록
    manager.addEmployee(new TemporaryWorker("kim", 100, 15));
    manager.addEmployee(new Employee("lee", 1500));
    manager.addEmployee(new Employee("park", 2000));

    // 이번 달에 지불해야 할 급여의 정보
    manager.showAllSalary();

    // 이번 달에 지불해야 할 급여의 총합
    manager.showTotalSalary();
    return 0;
}