#pragma once
#include "BaseService.h"
#include "CarDTO.h"

class CarService : public BaseService<CarDTO>
{
public:
	void Create(CarDTO obj);
	vector<CarDTO> Read();
	void Update(vector<CarDTO> cars, int idOfCar, int numOfField);
	void Delete(vector<CarDTO> cars, int idOfCar);
	CarDTO* ReadSpecific(int id);

	static int CountNumOfStr();
	static int GetLastId();
	static void UpdateLastId(int newId);
	static void Print(vector<CarDTO> cars);

	ostream& printLine(ostream& stream);
	ostream& printContent(ostream& stream);
};

