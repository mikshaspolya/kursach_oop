#pragma once
#include <iostream>
#include<string>
using namespace std;

class Order
{
	double cost;
	int idUser;
	string name;
	string surname;
	int idCar;
	string brand;
	string model;
	time_t date;

public:
	Order();
	Order(double cost, int idUser, string name, string surname, int idCar, string brand, string model, time_t date);
	Order(const Order& order);

	void SetCost(double cost);
	void SetIdUser(int idUser);
	void SetName(string name);
	void SetSurname(string surname);
	void SetIdCar(int idCar);
	void SetBrand(string brand);
	void SetModel(string model);
	void SetDate(time_t date);

	double GetCost();
	int GetIdUser();
	string GetName();
	string GetSurname();
	int GetIdCar();
	string GetBrand();
	string GetModel();
	time_t GetDate();
};

