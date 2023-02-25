#include <iostream>
#include "employee.h"
using namespace std;


int main() {

    PermanentWorker p("Aa", 1000);
    TemporaryWorker t("Bb", 10, 30);

    p.showSalary();
    t.showSalary();
    return 0;
}