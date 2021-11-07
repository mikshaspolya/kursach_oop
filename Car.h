#pragma once

#include <iostream>
#include <string>

using namespace std;

class Car
{
	int id;
	string brand;
	string model;
	string color;
	string bodyType;
	double cost;
	int yearOfManufacturing;
	string classOfAuto;

public:
	Car();
	Car(string brand, string model, string color, string bodyType, double cost, int yearOfManufacturing, string classOfAuto);
	Car(const Car& car);

	void SetId(int id);
	void SetBrand(string brand);
	void SetModel(string model);
	void SetColor(string color);
	void SetBodyType(string bodyType);
	void SetClassOfAuto(string classOfAuto);
	void SetYearOfManufacturing(int yearOfManufacturing);
	void SetCost(double cost);

	int GetId();
	string GetBrand();
	string GetModel();
	string GetColor();
	string GetBodyType();
	string GetClassOfAuto();
	int GetYearOfManufacturing();
	double GetCost();
};

