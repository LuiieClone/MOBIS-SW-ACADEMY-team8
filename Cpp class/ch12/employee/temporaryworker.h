#ifndef _TEMOIRARY_H_
#define _TEMOIRARY_H_

#include <iostream>
#include <string>
using namespace std;

class TemporaryWorker: public Employee
{
private:
	int date;
public:
	TemporaryWorker(string name, int money, int date): Employee(name, money)
	{
		this->date = date;
	};
	int getPay() const;
};
#endif