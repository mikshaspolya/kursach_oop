#include "OrderService.h"

void OrderService::Create()
{
}

vector<OrderDTO> OrderService::Read()
{
	return OrderDAO::Read();
}

//void OrderService::Update(OrderDTO* obj)
//{
//}

void OrderService::Delete(vector<OrderDTO> orderd, int idOfOrder)
{
	orderd.erase(orderd.begin() + idOfOrder);

	OrderDAO::Update(orderd);
}

OrderDTO* OrderService::ReadSpecific(int id)
{
	return nullptr;
}

int OrderService::CountNumOfStr()
{
	int numOfLines = 0;

	string buff;

	ifstream fin(FILE_ORDERS);
	if (fin.is_open())
	{
		for (int i = 0; !fin.eof(); i++) {
			getline(fin, buff, '\n');
			numOfLines++;
		}
	}
	else cout << "Этот файл не существует!" << endl;

	fin.close();

	return numOfLines;
}

int OrderService::GetLastId()
{
	int lastId[3];

	ifstream fin(FILE_LAST_ID);

	for (int i = 0; i < 3; i++)
	{
		fin >> lastId[i];
	}

	fin.close();

	return lastId[2];
}

void OrderService::UpdateLastId(int newId)
{
	int lastId[3];

	ifstream fin(FILE_LAST_ID);

	for (int i = 0; i < 3; i++)
	{
		fin >> lastId[i];
	}

	fin.close();

	ofstream fout(FILE_LAST_ID);

	lastId[2] = newId;

	for (int i = 0; i < 3; i++)
	{
		fout << lastId[i] << " ";
	}

	fout.close();
}

void OrderService::Print(vector<OrderDTO> orders)
{
}
