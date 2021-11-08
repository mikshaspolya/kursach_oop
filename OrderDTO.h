#pragma once
#include <iostream>
#include <string>
using namespace std;

class OrderDTO
{
	int id;
	double cost;
	int idUser;
	string name;
	string surname;
	int idCar;
	string brand;
	string model;
	tm date;

public:
	OrderDTO();
	OrderDTO(double cost, int idUser, string name, string surname, int idCar, string brand, string model, tm date);
	OrderDTO(const OrderDTO& order);

	void SetId(int id);
	void SetCost(double cost);
	void SetIdUser(int idUser);
	void SetName(string name);
	void SetSurname(string surname);
	void SetIdCar(int idCar);
	void SetBrand(string brand);
	void SetModel(string model);
	void SetDate(tm date);

	int GetId();
	double GetCost();
	int GetIdUser();
	string GetName();
	string GetSurname();
	int GetIdCar();
	string GetBrand();
	string GetModel();
	tm GetDate();
};

