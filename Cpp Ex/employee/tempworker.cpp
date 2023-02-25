#include "tempworker.h"

TempWorker::TempWorker(string name, int perday, int day):Employee(name, perday)
{
    this->workDay = day;
}
int TempWorker::getPay( ) const {
    return salary*workDay; 
}

void TempWorker::showSalary() const{
    cout << name << " :  일급 : " << salary  << ", 작업일 : " << workDay <<endl;
}