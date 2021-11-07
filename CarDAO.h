#pragma once
#include "BaseDAO.h"

class CarDAO : public BaseDAO<CarDTO>
{
public:
	static void Create(CarDTO obj);
	static vector<CarDTO> Read();
	static void Update(vector<CarDTO> cars);
};

