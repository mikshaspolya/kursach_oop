#pragma once
#include "Libraries.h"

template <class T1>
class BaseDAO
{
public: 
	virtual void Create(T1 obj) = 0;
	virtual std::vector<T1> Read() = 0;
	virtual void Update(std::vector<T1>) = 0;
};

