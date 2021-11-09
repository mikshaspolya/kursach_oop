#pragma once
#include "Libraries.h"
#include "CarDTO.h"
#include "UserDTO.h"
#include "OrderDTO.h"
#include "CarService.h"
#include "UserService.h"
#include "OrderService.h"


template <class T1>
class BaseDAO
{
public: 
	virtual void Create(T1 obj) = 0;
	virtual std::vector<T1> Read() = 0;
	virtual void Update(std::vector<T1>) = 0;
};

