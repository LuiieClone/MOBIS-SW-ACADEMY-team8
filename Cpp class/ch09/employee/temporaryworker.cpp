#include "employee.h"
#include "temporaryworker.h"

int TemporaryWorker::getPay() const
{
	return salary*date;
}
