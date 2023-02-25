#include "employee.h"

class TempWorker: public Employee {
     int workDay;
public:
    TempWorker(string name, int perday, int day=0);

    int getPay() const;
	void showSalary() const;
};