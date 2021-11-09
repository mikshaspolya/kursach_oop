#pragma once
#include "BaseDAO.h"

class OrderDAO : public BaseDAO<OrderDTO>
{
public:
	void Create(OrderDTO obj) override;
	vector<OrderDTO> Read() override;
	void Update(vector<OrderDTO>) override;
};


