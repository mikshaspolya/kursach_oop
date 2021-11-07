#include "Menu.h"

void MainMenu()
{
	int mainMenuInput;

	UserDTO us;

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
			UserService::Authorization(us);
			break;

		case 2:
			UserService::Create();
			break;
		}
	} while (mainMenuInput != 3);
}

void MenuAdmin(int id)
{
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
			UserService::ReadSpecific(id);

			//Print
			break;

		case 5:
			break;

		}
	} while (adminInput != 6);
}

void MenuCars()
{
	int menuCarsInput = 0, addCarInput = 0, clearFileInput = 0;

	do
	{
		int numOfStr = CarService::CountNumOfStr();

		vector<CarDTO> cars = CarService::Read();

		CarDTO carDTO;

		int id;
		string brand;
		string model;
		string color;
		string bodyType;
		double cost;
		int yearOfManufacturing;
		string classOfAuto;
		
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

			CarService::Create(carDTO);

			system("cls");

			cout << "���������� ������� ��������!" << endl;

			break;

		case 2:
			system("cls");

			cout << "����� ���������� �� ������ ����������������?" << endl;

			CarService::Print(cars);

			int num;

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

			CarService::Update(cars, --num, fieldChoice);

			cout << "���������� ������� ��������������!" << endl;
			break;

		case 3: 
			system("cls");

			cout << "����� ���������� �� ������ �������?" << endl;

			CarService::Print(cars);

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
				CarService::Delete(cars, --num);
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
	int menuUsersInput, delUserInput;

	do
	{
		int numOfStr = UserService::CountNumOfStr();

		vector<UserDTO> users = UserService::Read();

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
				UserService::Delete(users, --num);
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

			UserService::MakeAdmin(users, --numOfUser);

			break;
		}
	} while (menuUsersInput != 5);
}

void MenuOrders()
{
	int menuOrdersInput;

	do
	{
		int numOfStr = OrderService::CountNumOfStr();

		vector<OrderDTO> orders = OrderService::Read();

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
				OrderService::Delete(orders, --num);
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
	int userMenuInput;

	do
	{
		int numOfStr = UserService::CountNumOfStr();

		vector<CarDTO> cars = CarService::Read();

		UserDTO user;

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
			user = UserService::ReadSpecific(id);

			//Print

			/*cout << "ID\t" << "Login\t" << setw(9) << "\tName\t\t" << setw(11) << "Surname\t " << "Birthday\t   " << "Phone" << endl;

			cout << setw(1) << me.id << "\t" << left << setw(10) << me.login << "\t" << left << setw(10)
				<< me.name << "\t  " << left << setw(10) << me.surname << "\t " << left << me.birthday.day << "." << me.birthday.month << "."
				<< me.birthday.year << "\t   " << me.phone << endl;*/
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