#include "Menu.h"

void MainMenu()
{
	int mainMenuInput;

	UserDTO us;
	UserService usS;

	string login, password;
	do {
		cout << "===== ������� ���� =====" << endl;
		cout << "1. �����" << endl;
		cout << "2. ������������������" << endl;
		cout << "3. �����" << endl;
		cin >> mainMenuInput;

		Validator::Check<int>(mainMenuInput, 1, 3);

		system("cls");

		switch (mainMenuInput)
		{
		case 1:
			usS.Authorization(us);
			break;

		case 2:
			usS.Create(us);
			break;
		}
	} while (mainMenuInput != 3);
}

void MenuAdmin(int id)
{
	UserService usS;

	int adminInput;
	do
	{
		cout << "========= ���� �������������� =========" << endl;
		cout << "1. �������� � ����������� �� �����������" << endl;
		cout << "2. �������� � ����������� � �������������" << endl;
		cout << "3. �������� � ����������� � �������" << endl;
		cout << "4. ����������� ���������� � ����" << endl;
		cout << "5. �������������� ���������� � ����" << endl;
		cout << "6. ����� � ������� ����" << endl;

		cin >> adminInput;
		Validator::Check<int>(adminInput, 1, 6);

		system("cls");

		switch (adminInput)
		{
		case 1:
			MenuCars();
			break;

		case 2:
			MenuUsers();
			break;

		case 3:
			MenuOrders();
			break;

		case 4:
			usS.ReadSpecific(id);

			//Print
			break;

		case 5:
			break;

		}
	} while (adminInput != 6);
}

void MenuCars()
{
	CarService carS;

	int menuCarsInput = 0, addCarInput = 0, clearFileInput = 0;

	do
	{
		int numOfStr = CarService::CountNumOfStr();

		vector<CarDTO> cars = carS.Read();

		CarDTO carDTO;

		int id;
		string brand;
		string model;
		string color;
		string bodyType;
		double cost;
		int yearOfManufacturing;
		string classOfAuto;

		int num;
		
		cout << "===== ���� ��� ������ � ����������� �� ����������� =====" << endl;
		cout << "1. �������� ����������" << endl;
		cout << "2. ������������� ����������" << endl;
		cout << "3. ������� ����������" << endl;
		cout << "4. ����������� ��� ����������" << endl;
		cout << "5. ����������� ��� ����������� ����������" << endl;
		cout << "6. ����� � ���� ��������������" << endl;

		cin >> menuCarsInput;
		Validator::Check<int>(menuCarsInput, 1, 6);

		system("cls");

		switch (menuCarsInput)
		{
		case 1:
			cout << "������� ���������� �� ����������: " << endl;
			cout << "������� ����� ����������: " << endl;
			cin >> brand;

			while (!Validator::CheckName(brand))
			{
				cout << "� �������� ������ ���� ����������� �������, ����������, ���������� �����!" << endl;
				cin >> brand;
			}

			cout << "������� ������ ����������: " << endl;
			cin >> model;

			while (!Validator::CheckName(model))
			{
				cout << "� �������� ������ ���� ����������� �������, ����������, ���������� �����!" << endl;
				cin >> model;
			}

			cout << "������� ���� ����������: " << endl;
			cin >> color;

			cout << "������� ��� ������ ����������: " << endl;
			cin >> bodyType;

			cout << "������� ���� ����������: " << endl;
			cin >> cost;

			cout << "������� ��� ������������ ����������" << endl;
			cin >> yearOfManufacturing;

			cout << "������� ����� ����������" << endl;
			cin >> classOfAuto;

			id = CarService::GetLastId();

			carDTO.SetId(id);
			carDTO.SetBrand(brand);
			carDTO.SetModel(model);
			carDTO.SetColor(color);
			carDTO.SetBodyType(bodyType);
			carDTO.SetCost(cost);
			carDTO.SetYearOfManufacturing(yearOfManufacturing);
			carDTO.SetClassOfAuto(classOfAuto);

			CarService::UpdateLastId(++id);

			carS.Create(carDTO);

			system("cls");

			cout << "���������� ������� ��������!" << endl;

			break;

		case 2:
			system("cls");

			cout << "����� ���������� �� ������ ����������������?" << endl;

			CarService::Print(cars);

			cin >> num;
			Validator::Check<int>(num, 1, --numOfStr);

			cout << "����� ���� �� ������ ���������������?" << endl;

			cout << "1. �����" << endl;
			cout << "2. ������" << endl;
			cout << "3. ����" << endl;
			cout << "4. ���� ������" << endl;
			cout << "5. ����" << endl;
			cout << "6. ��� �������������" << endl;
			cout << "7. ����� ����������" << endl;

			int fieldChoice;
			cin >> fieldChoice;
			Validator::Check<int>(fieldChoice, 1, 7);

			carS.Update(cars, --num, fieldChoice);

			cout << "���������� ������� ��������������!" << endl;
			break;

		case 3: 
			system("cls");

			cout << "����� ���������� �� ������ �������?" << endl;

			CarService::Print(cars);

			cin >> num;
			Validator::Check<int>(num, 1, --numOfStr);

			cout << "�� �������?" << endl;

			cout << "1. ��" << endl;
			cout << "2. ���" << endl;

			int sureChoice;
			cin >> sureChoice;
			Validator::Check<int>(sureChoice, 1, 2);

			if (sureChoice == 1)
			{
				carS.Delete(cars, --num);
				cout << "���������� ��� ������� ������!" << endl;
			}

			break;

		case 4: 
			CarService::Print(cars);
			break;

		case 5: //FilterSortAuto();
			break;
		}
	} while (menuCarsInput != 6);
}

void MenuUsers()
{
	UserService usS;

	int menuUsersInput, delUserInput;

	do
	{
		int numOfStr = UserService::CountNumOfStr();

		vector<UserDTO> users = usS.Read();

		cout << "===== ���� ��� ������ � ����������� � ������������� =====" << endl;
		cout << "1. ����������� ���� �������������" << endl;
		cout << "2. ������� ������������" << endl;
		cout << "3. ���������� ��� ����������� �������������" << endl;
		cout << "4. ��������� ������������ ���������������" << endl;
		cout << "5. ����� � ���� ��������������" << endl;

		cin >> menuUsersInput;
		Validator::Check<int>(menuUsersInput, 1, 5);

		system("cls");

		switch (menuUsersInput)
		{
		case 1: 
			UserService::Print(users);
			break;

		case 2:
			system("cls");

			cout << "������ ������������ �� ������ �������?" << endl;

			UserService::Print(users);

			int num;

			cin >> num;
			Validator::Check<int>(num, 1, --numOfStr);

			cout << "�� �������?" << endl;

			cout << "1. ��" << endl;
			cout << "2. ���" << endl;

			int sureChoice;
			cin >> sureChoice;
			Validator::Check<int>(sureChoice, 1, 2);

			if (sureChoice == 1)
			{
				usS.Delete(users, --num);
				cout << "������������ ��� ������� ������!" << endl;
			}

			break;

		case 3: //FilterSortUser();
			break;

		case 4:
			cout << "�������� ������������, �������� ������ ������� ���������������" << endl;

			UserService::Print(users);

			int numOfUser;
			cin >> numOfUser;

			Validator::Check<int>(numOfUser, 1, --numOfStr);

			usS.MakeAdmin(users, --numOfUser);

			break;
		}
	} while (menuUsersInput != 5);
}

void MenuOrders()
{
	OrderService orS; //!!!!!!!!!!!!!!!!!!!!

	int menuOrdersInput;

	do
	{
		int numOfStr = OrderService::CountNumOfStr();

		vector<OrderDTO> orders = orS.Read();

		cout << "===== ���� ��� ������ � ����������� � ������� =====" << endl;
		cout << "1. ����������� ��� ������" << endl;
		cout << "2. ������� �����" << endl;
		cout << "3. ����������� ��� ����������� ������" << endl;
		cout << "4. ����� � ���� ��������������" << endl;

		cin >> menuOrdersInput;
		Validator::Check<int>(menuOrdersInput, 1, 4);

		system("cls");

		switch (menuOrdersInput)
		{
		case 1: 
			OrderService::Print(orders);
			break;

		case 2: 
			system("cls");

			cout << "����� ����� �� ������ �������?" << endl;

			OrderService::Print(orders);

			int num;

			cin >> num;
			Validator::Check<int>(num, 1, --numOfStr);

			cout << "�� �������?" << endl;

			cout << "1. ��" << endl;
			cout << "2. ���" << endl;

			int sureChoice;
			cin >> sureChoice;
			Validator::Check<int>(sureChoice, 1, 2);

			if (sureChoice == 1)
			{
				orS.Delete(orders, --num);
				cout << "����� ��� ������� ������!" << endl;
			}

			break;

		case 3: //FilterSortRecords();
			break;
		}
	} while (menuOrdersInput != 4);
}

void MenuCarsFilter();
void MenuCarsSort();
void MenuUsersFilter();
void MenuUsersSort();
void MenuOrdersFilter();
void MenuOrdersSort();

void MenuUser(int id)
{
	CarService carS;
	UserService usS;

	int userMenuInput;

	do
	{
		int numOfStr = UserService::CountNumOfStr();

		vector<CarDTO> cars = carS.Read();

		UserDTO* user;

		cout << "======== ���� ������������ ========" << endl;
		cout << "1. ����������� ���������� � ����" << endl;
		cout << "2. ��������������� ���������� � ����" << endl;
		cout << "3. ����������� ������� �����������" << endl;
		cout << "4. ����������� ��� ����������� ����������" << endl;
		cout << "5. ������� �����" << endl;
		cout << "6. ����������� ����������� ������" << endl;
		cout << "7. ��������� � ������� ����" << endl;

		cin >> userMenuInput;
		Validator::Check<int>(userMenuInput, 1, 7);

		system("cls");

		switch (userMenuInput)
		{
		case 1:
			user = usS.ReadSpecific(id);   //!!!!!!

			//Print

			break;

		case 2:
			break;

		case 3: 
			CarService::Print(cars);
			break;

		case 4: 
			break;

		case 5: 
			break;

		case 6:
			break;
		}
	} while (userMenuInput != 7);
}