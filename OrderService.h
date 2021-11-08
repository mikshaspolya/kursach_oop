#pragma once
#include "BaseService.h"
#include "OrderDTO.h"

class OrderService : public BaseService<OrderDTO>
{
public:
	void Create(OrderDTO obj) override;
	vector<OrderDTO> Read() override;
	void Update(vector<OrderDTO> orders, int idOfOrder, int numOfField) override;
	void Delete(vector<OrderDTO> orders, int idOfOrder) override;
	OrderDTO* ReadSpecific(int id) override;

	static int CountNumOfStr();
	static int GetLastId();
	static void UpdateLastId(int newId);

	static void Print(vector<OrderDTO> orders);

	ostream& printLine(ostream& stream);
	ostream& printContent(ostream& stream);
};

