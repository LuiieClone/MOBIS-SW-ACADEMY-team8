#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
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
void EmployeeManager::showSomeSalary() // 전 사원 이름, 급여 출력
{
    int n;
    cout << "enter the limit: ";
    cin >> n;
    for_each(empList.begin(), empList.end(), [n](Employee* e){ if(e->getPay() > n) cout << "name : "<< e->getName() << endl; });
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
void EmployeeManager::fileRead(ifstream& fin)
{
    if(!fin) {
        cout << "ERROR!" << endl;
    }
    
    string line;
    while (getline(fin, line))
    {
        vector<string> words;
        string word; //buffer
        istringstream ss(line); //searching: string to input
        while (getline(ss, word, ' ')) //공백 단위로 구분
            words.push_back(word);

        if(words.size() == 2)
        {
            empList.push_back(new Employee(words[0], atoi(words[1].c_str())));
        }
        else if(words.size() == 3)
        {
            empList.push_back(new TemporaryWorker(words[0], atoi(words[1].c_str()), atoi(words[2].c_str())));
        }
    }
    
}