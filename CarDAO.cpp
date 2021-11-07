#include "CarDAO.h"

void CarDAO::Create(CarDTO obj)
{
	ofstream fout(FILE_CARS, ios::app);

	fout << obj.GetId() << " " << obj.GetBrand() << " " << obj.GetModel() << " " << obj.GetColor() << " " << obj.GetBodyType() << " " << obj.GetCost() << " " << obj.GetYearOfManufacturing() << " " << obj.GetClassOfAuto() << "\n";

	fout.close();
}

vector<CarDTO> CarDAO::Read()
{
	int numOfStr = CarService::CountNumOfStr();

	vector<CarDTO>cars;

	int id;
	string brand;
	string model;
	string color;
	string bodyType;
	double cost;
	int yearOfManufacturing;
	string classOfAuto;

	ifstream fin(FILE_CARS);

	for (int i = 0; i < numOfStr - 1; i++) {
		fin >> id;
		fin >> brand;
		fin >> model;
		fin >> color;
		fin >> bodyType;
		fin >> cost;
		fin >> yearOfManufacturing;
		fin >> classOfAuto;

		cars[i].SetId(id);
		cars[i].SetBrand(brand);
		cars[i].SetModel(model);
		cars[i].SetColor(color);
		cars[i].SetBodyType(bodyType);
		cars[i].SetCost(cost);
		cars[i].SetYearOfManufacturing(yearOfManufacturing);
		cars[i].SetClassOfAuto(classOfAuto);
	}
	fin.close();

	return cars;
}

void CarDAO::Update(vector<CarDTO> cars)
{
	int numOfStr = CarService::CountNumOfStr();

	ofstream fout(FILE_CARS, ios::out);
	for (int i = 0; i < numOfStr - 1; i++)
	{
		fout << cars[i].GetId() << " " << cars[i].GetBrand() << " " << cars[i].GetModel() << " " << cars[i].GetColor() << " " << cars[i].GetBodyType() << " " << cars[i].GetCost() << " " << cars[i].GetYearOfManufacturing() << " " << cars[i].GetClassOfAuto() << "\n";
	}
	fout.close();
}
