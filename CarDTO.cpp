#include "CarDTO.h"

CarDTO::CarDTO()
{
}

CarDTO::CarDTO(string brand, string model, string color, string bodyType, double cost, int yearOfManufacturing, string classOfAuto)
{
	this->brand = brand;
	this->model = model;
	this->color = color;
	this->bodyType = bodyType;
	this->yearOfManufacturing = yearOfManufacturing;
	this->cost = cost;
	this->classOfAuto = classOfAuto;
}

CarDTO::CarDTO(const CarDTO& car)
{
	this->brand = car.brand;
	this->model = car.model;
	this->color = car.color;
	this->bodyType = car.bodyType;
	this->yearOfManufacturing = car.yearOfManufacturing;
	this->cost = car.cost;
	this->classOfAuto = car.classOfAuto;
}

void CarDTO::SetId(int id)
{
	this->id = id;
}

void CarDTO::SetBrand(string brand)
{
	this->brand = brand;
}

void CarDTO::SetModel(string model)
{
	this->model = model;
}

void CarDTO::SetColor(string color)
{
	this->color = color;
}

void CarDTO::SetBodyType(string bodyType)
{
	this->bodyType = bodyType;
}

void CarDTO::SetClassOfAuto(string classOfAuto)
{
	this->classOfAuto = classOfAuto;
}

void CarDTO::SetYearOfManufacturing(int yearOfManufacturing)
{
	this->yearOfManufacturing = yearOfManufacturing;
}

void CarDTO::SetCost(double cost)
{
	this->cost = cost;
}

int CarDTO::GetId()
{
	return this->id;
}

string CarDTO::GetBrand()
{
	return this->brand;
}

string CarDTO::GetModel()
{
	return this->model;
}

string CarDTO::GetColor()
{
	return this->color;
}

string CarDTO::GetBodyType()
{
	return this->bodyType;
}

string CarDTO::GetClassOfAuto()
{
	return this->classOfAuto;
}

int CarDTO::GetYearOfManufacturing()
{
	return this->yearOfManufacturing;
}

double CarDTO::GetCost()
{
	return this->cost;
}
