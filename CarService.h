#pragma once
#include "BaseService.h"

template <class CarDTO>
class CarService : public BaseService<CarDTO>
{
public:
	static void Create(CarDTO obj);
	static vector<CarDTO> Read();
	static void Update(vector<CarDTO> cars, int idOfCar, int numOfField);
	static void Delete(vector<CarDTO> cars, int idOfCar);
	CarDTO* ReadSpecific(int id);

	static int CountNumOfStr();
	static int GetLastId();
	static void UpdateLastId(int newId);
	static void Print(vector<CarDTO> cars);
};

