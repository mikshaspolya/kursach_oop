#include "Car.h"

Car::Car()
{
}

Car::Car(string brand, string model, string color, string bodyType, double cost, int yearOfManufacturing, string classOfAuto)
{
	this->brand = brand;
	this->model = model;
	this->color = color;
	this->bodyType = bodyType;
	this->yearOfManufacturing = yearOfManufacturing;
	this->cost = cost;
	this->classOfAuto = classOfAuto;
}

Car::Car(const Car& car)
{
	this->brand = car.brand;
	this->model = car.model;
	this->color = car.color;
	this->bodyType = car.bodyType;
	this->yearOfManufacturing = car.yearOfManufacturing;
	this->cost = car.cost;
	this->classOfAuto = car.classOfAuto;
}

void Car::SetId(int id)
{
	this->id = id;
}

void Car::SetBrand(string brand)
{
	this->brand = brand;
}

void Car::SetModel(string model)
{
	this->model = model;
}

void Car::SetColor(string color)
{
	this->color = color;
}

void Car::SetBodyType(string bodyType)
{
	this->bodyType = bodyType;
}

void Car::SetClassOfAuto(string classOfAuto)
{
	this->classOfAuto = classOfAuto;
}

void Car::SetYearOfManufacturing(int yearOfManufacturing)
{
	this->yearOfManufacturing = yearOfManufacturing;
}

void Car::SetCost(double cost)
{
	this->cost = cost;
}

int Car::GetId()
{
	return this->id;
}

string Car::GetBrand()
{
	return this->brand;
}

string Car::GetModel()
{
	return this->model;
}

string Car::GetColor()
{
	return this->color;
}

string Car::GetBodyType()
{
	return this->bodyType;
}

string Car::GetClassOfAuto()
{
	return this->classOfAuto;
}

int Car::GetYearOfManufacturing()
{
	return this->yearOfManufacturing;
}

double Car::GetCost()
{
	return this->cost;
}
