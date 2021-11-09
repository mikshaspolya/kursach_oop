#include "CarService.h"

void CarService::Create(CarDTO obj)
{
	CarDAO carDAO;
	carDAO.Create(obj);
}

vector<CarDTO> CarService::Read()
{
	CarDAO carDAO;
	return carDAO.Read();
}

void CarService::Update(vector<CarDTO> cars, int idOfCar, int numOfField)
{
	CarDAO carDAO;

	string brand;
	string model;
	string color;
	string bodyType;
	double cost;
	int yearOfManufacturing;
	string classOfAuto;

	switch (numOfField)
	{
	case 1:
		cout << "Введите новое значение поля Бренд" << endl;
		cin >> brand;

		while (!Validator::CheckName(brand))
		{
			cout << "В названии бренда есть запрещенные символы, пожалуйста, попробуйте снова!" << endl;
			cin >> brand;
		}

		cars[idOfCar].SetBrand(brand);
		break;

	case 2:
		cout << "Введите новое значение поля Модель" << endl;
		cin >> model;

		while (!Validator::CheckName(model))
		{
			cout << "В названии модели есть запрещенные символы, пожалуйста, попробуйте снова!" << endl;
			cin >> model;
		}

		cars[idOfCar].SetModel(model);
		break;

	case 3:
		cout << "Введите новое значение поля Цвет" << endl;
		cin >> color;

		cars[idOfCar].SetColor(color);
		break;

	case 4:
		cout << "Введите новое значение поля Тип кузова" << endl;
		cin >> bodyType;

		cars[idOfCar].SetBodyType(bodyType);
		break;

	case 5:
		cout << "Введите новое значение поля Цена" << endl;
		cin >> cost;

		cars[idOfCar].SetCost(cost);
		break;

	case 6:
		cout << "Введите новое значение поля Год производства" << endl;
		cin >> yearOfManufacturing;

		cars[idOfCar].SetYearOfManufacturing(yearOfManufacturing);
		break;

	case 7:
		cout << "Введите новое значение поля Класс автомобиля" << endl;
		cin >> classOfAuto;

		cars[idOfCar].SetClassOfAuto(classOfAuto);
		break;
	}

	carDAO.Update(cars);
}

void CarService::Delete(vector<CarDTO> cars, int idOfCar)
{
	CarDAO carDAO;

	cars.erase(cars.begin() + idOfCar);

	carDAO.Update(cars);
}

CarDTO* CarService::ReadSpecific(int id)
{
	return nullptr;
}

int CarService::CountNumOfStr()
{
	int numOfLines = 0;

	string buff;

	ifstream fin(FILE_CARS);
	if (fin.is_open())
	{
		for (int i = 0; !fin.eof(); i++) {
			getline(fin, buff, '\n');
			numOfLines++;
		}
	}
	else cout << "Этот файл не существует!" << endl;

	fin.close();

	return numOfLines;
}

int CarService::GetLastId()
{
	int lastId[3];

	ifstream fin(FILE_LAST_ID);

	for (int i = 0; i < 3; i++)
	{
		fin >> lastId[i];
	}

	fin.close();

	return lastId[1];
}

void CarService::UpdateLastId(int newId)
{
	int lastId[3];

	ifstream fin(FILE_LAST_ID);

	for (int i = 0; i < 3; i++)
	{
		fin >> lastId[i];
	}

	fin.close();

	ofstream fout(FILE_LAST_ID);

	lastId[1] = newId;

	for (int i = 0; i < 3; i++)
	{
		fout << lastId[i] << " ";
	}

	fout.close();
}

void CarService::Print(vector<CarDTO> cars)
{
	int numOfStr = CarService::CountNumOfStr();

	cout << "+";
	for (int j = 0; j < 8; j++)
	{
		cout << &printLine;
	}
	cout << endl;

	cout << &printContent << "Идентификатор" << &printContent << "Модель" << &printContent << "Цвет" << &printContent <<
		"Тип кузова" << &printContent << "Цена ($)" << &printContent << "Год пр-ва" << &printContent << "Класс авто";
	cout << "|" << endl;

	cout << "+";
	for (int j = 0; j < 8; j++)
	{
		cout << &printLine;
	}
	cout << endl;

	for (int i = 0; i < numOfStr - 1; i++)
	{
		cout << &printContent << cars[i].GetId() << &printContent << cars[i].GetBrand() << &printContent << cars[i].GetModel() << &printContent << 
				cars[i].GetColor() << &printContent << cars[i].GetBodyType() << &printContent << cars[i].GetCost() << &printContent <<
				cars[i].GetYearOfManufacturing() << &printContent << cars[i].GetClassOfAuto();
		cout << "|" << endl;
		cout << "+";
		for (int j = 0; j < 8; j++)
		{
			cout << &printLine;
		}
		cout << endl;
	}
}

ostream& CarService::printLine(ostream& stream)
{
	stream << "-------------+";
	return stream;
}

ostream& CarService::printContent(ostream& stream)
{
	stream.setf(ios::right);
	stream << "|" << setw(13) << setfill(' ');
	return stream;
}
