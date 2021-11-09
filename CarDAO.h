#pragma once
#include "BaseDAO.h"

class CarDAO : public BaseDAO<CarDTO>
{
public:
	void Create(CarDTO obj) override;
	vector<CarDTO> Read() override;
	void Update(vector<CarDTO> cars) override;
};

