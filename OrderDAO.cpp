#include "OrderDAO.h"

void OrderDAO::Create(OrderDTO obj)
{
	ofstream fout(FILE_ORDERS, ios::app);

	fout << obj.GetId() << " " << obj.GetCost() << " " << obj.GetIdUser() << " " << obj.GetName() << " " << obj.GetSurname() << " " << obj.GetIdCar() << " " << obj.GetBrand() << " " << obj.GetModel() << " " << obj.GetDate() << "\n";

	fout.close();
}

vector<OrderDTO> OrderDAO::Read()
{
	int numOfStr = OrderService::CountNumOfStr();

	vector<OrderDTO> orders;

	int id;
	double cost;
	int idUser;
	string name;
	string surname;
	int idCar;
	string brand;
	string model;
	time_t date;

	ifstream fin(FILE_USERS);

	for (int i = 0; i < numOfStr - 1; i++) {
		fin >> id;
		fin >> cost;
		fin >> cost;
		fin >> name;
		fin >> surname;
		fin >> cost;
		fin >> brand;
		fin >> model;
		fin >> date;

		orders[i].SetId(id);
		orders[i].SetCost(cost);
		orders[i].SetIdUser(idUser);
		orders[i].SetName(name);
		orders[i].SetSurname(surname);
		orders[i].SetIdCar(idCar);
		orders[i].SetBrand(brand);
		orders[i].SetModel(model);
		orders[i].SetDate(date);
	}
	fin.close();

	return orders;
}

void OrderDAO::Update(vector<OrderDTO> orders)
{
	int numOfStr = OrderService::CountNumOfStr();

	ofstream fout(FILE_ORDERS, ios::out);
	for (int i = 0; i < numOfStr - 1; i++)
	{
		fout << orders[i].GetId() << " " << orders[i].GetCost() << " " << orders[i].GetIdUser() << " " << orders[i].GetName() << " " << orders[i].GetSurname() << " " << orders[i].GetIdCar() << " " << orders[i].GetBrand() << " " << orders[i].GetModel() << " " << orders[i].GetDate() << "\n";
	}
	fout.close();
}
