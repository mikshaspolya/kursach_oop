#pragma once
#include "Libraries.h"
#include <iomanip>

template <class T1>
class BaseService
{
public:
	virtual T1* Create(T1 obj) = 0;
	virtual std::vector<T1> Read() = 0;
	virtual void Update(std::vector<T1> cars, int idOfCar, int numOfField) = 0;
	virtual void Delete(std::vector<T1> cars, int idOfCar) = 0;
	virtual T1* ReadSpecific(int id) = 0;

	virtual int CountNumOfStr() = 0;
	virtual int GetLastId() = 0;
	virtual void UpdateLastId(int newId) = 0;

	virtual ostream& printLine(ostream& stream);
	virtual ostream& printContent(ostream& stream);
};
