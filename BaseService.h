#pragma once
#include "Libraries.h"
#include "CarDTO.h"
#include "UserDTO.h"
#include "OrderDTO.h"
#include "CarDAO.h"
#include "UserDAO.h"
#include "OrderDAO.h"
#include "Validator.h"
#include "Menu.h"

template <class T1>
class BaseService
{
public:
	virtual void Create(T1 obj) = 0;
	virtual std::vector<T1> Read() = 0;
	virtual void Update(std::vector<T1> cars, int idOfCar, int numOfField) = 0;
	virtual void Delete(std::vector<T1> cars, int idOfCar) = 0;
	virtual T1* ReadSpecific(int id) = 0;
};
