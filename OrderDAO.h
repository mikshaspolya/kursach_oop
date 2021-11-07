#pragma once
#include "Libraries.h"

class OrderDAO : public BaseDAO<OrderDTO>
{
public:
	static void Create(OrderDTO obj);
	static vector<OrderDTO> Read();
	static void Update(vector<OrderDTO>);
};


