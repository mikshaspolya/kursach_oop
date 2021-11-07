#pragma once
#include "Libraries.h"

class OrderService : public BaseService<OrderService, OrderDTO>
{
public:
	static void Create();
	static vector<OrderDTO> Read();
	//static void Update(OrderDTO* obj);
	static void Delete(vector<OrderDTO> orderd, int idOfOrder);
	static OrderDTO* ReadSpecific(int id);

	static int CountNumOfStr();
	static int GetLastId();
	static void UpdateLastId(int newId);

	static void Print(vector<OrderDTO> orders);
};

