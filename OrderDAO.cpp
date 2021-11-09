#include "OrderDAO.h"

void OrderDAO::Create(OrderDTO obj)
{
	tm date = obj.GetDate();
	string d = date.tm_mday + " " + date.tm_mon;
	d += " " + date.tm_year;

	ofstream fout(FILE_ORDERS, ios::app);

	fout << obj.GetId() << " " << obj.GetCost() << " " << obj.GetIdUser() << " " << obj.GetName() << " " << obj.GetSurname() << " " << obj.GetIdCar() <<
			" " << obj.GetBrand() << " " << obj.GetModel() << " " << d << "\n";

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
	tm date;

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
		fin >> date.tm_mday;
		fin >> date.tm_mon;
		fin >> date.tm_year;

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
		tm date = orders[i].GetDate();
		string d = date.tm_mday + " " + date.tm_mon;
		d += " " + date.tm_year;

		fout << orders[i].GetId() << " " << orders[i].GetCost() << " " << orders[i].GetIdUser() << " " << orders[i].GetName() << " " <<
			orders[i].GetSurname() << " " << orders[i].GetIdCar() << " " << orders[i].GetBrand() << " " << orders[i].GetModel() << " " <<
			d << "\n";
	}
	fout.close();
}
