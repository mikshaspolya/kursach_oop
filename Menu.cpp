#include "Menu.h"

void MainMenu()
{
	int mainMenuInput;

	UserDTO us;
	UserService usS;

	string login, password;
	do {
		cout << "===== Главное меню =====" << endl;
		cout << "1. Войти" << endl;
		cout << "2. Зарегистрироваться" << endl;
		cout << "3. Выход" << endl;
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
		cout << "========= Меню администратора =========" << endl;
		cout << "1. Работать с информацией об автомобилях" << endl;
		cout << "2. Работать с информацией о пользователях" << endl;
		cout << "3. Работать с информацией о заказах" << endl;
		cout << "4. Просмотреть информацию о себе" << endl;
		cout << "5. Оредактировать информацию о себе" << endl;
		cout << "6. Выйти в главное меню" << endl;

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
		
		cout << "===== Меню для работы с информацией об автомобилях =====" << endl;
		cout << "1. Добавить автомобиль" << endl;
		cout << "2. Редактировать автомобиль" << endl;
		cout << "3. Удалить автомобиль" << endl;
		cout << "4. Просмотреть все автомобили" << endl;
		cout << "5. Сортировать или фильтровать автомобили" << endl;
		cout << "6. Выйти в меню администратора" << endl;

		cin >> menuCarsInput;
		Validator::Check<int>(menuCarsInput, 1, 6);

		system("cls");

		switch (menuCarsInput)
		{
		case 1:
			cout << "Введите информацию об автомобиле: " << endl;
			cout << "Введите бренд автомобиля: " << endl;
			cin >> brand;

			while (!Validator::CheckName(brand))
			{
				cout << "В названии бренда есть запрещенные символы, пожалуйста, попробуйте снова!" << endl;
				cin >> brand;
			}

			cout << "Введите модель автомобиля: " << endl;
			cin >> model;

			while (!Validator::CheckName(model))
			{
				cout << "В названии модели есть запрещенные символы, пожалуйста, попробуйте снова!" << endl;
				cin >> model;
			}

			cout << "Введите цвет автомобиля: " << endl;
			cin >> color;

			cout << "Введите тип кузова автомобиля: " << endl;
			cin >> bodyType;

			cout << "Введите цену автомобиля: " << endl;
			cin >> cost;

			cout << "Введите год производства автомобиля" << endl;
			cin >> yearOfManufacturing;

			cout << "Введите класс автомобиля" << endl;
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

			cout << "Автомобиль успешно добавлен!" << endl;

			break;

		case 2:
			system("cls");

			cout << "Какой атвомобиль вы хотите отредакатировать?" << endl;

			CarService::Print(cars);

			cin >> num;
			Validator::Check<int>(num, 1, --numOfStr);

			cout << "Какое поле вы хотите отредактировать?" << endl;

			cout << "1. Бренд" << endl;
			cout << "2. Модель" << endl;
			cout << "3. Цвет" << endl;
			cout << "4. Типа кузова" << endl;
			cout << "5. Цена" << endl;
			cout << "6. Год произваодства" << endl;
			cout << "7. Класс автомобиля" << endl;

			int fieldChoice;
			cin >> fieldChoice;
			Validator::Check<int>(fieldChoice, 1, 7);

			carS.Update(cars, --num, fieldChoice);

			cout << "Автомобиль успешно отредактирован!" << endl;
			break;

		case 3: 
			system("cls");

			cout << "Какой атвомобиль вы хотите удалить?" << endl;

			CarService::Print(cars);

			cin >> num;
			Validator::Check<int>(num, 1, --numOfStr);

			cout << "Вы уверены?" << endl;

			cout << "1. да" << endl;
			cout << "2. нет" << endl;

			int sureChoice;
			cin >> sureChoice;
			Validator::Check<int>(sureChoice, 1, 2);

			if (sureChoice == 1)
			{
				carS.Delete(cars, --num);
				cout << "Автомобиль был успешно удален!" << endl;
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

		cout << "===== Меню для работы с информацией о пользователях =====" << endl;
		cout << "1. Просмотреть всех пользователей" << endl;
		cout << "2. Удалить пользователя" << endl;
		cout << "3. Сортровать или фильтровать поьлзователей" << endl;
		cout << "4. Назначить пользователя администратором" << endl;
		cout << "5. Выйти в меню администратора" << endl;

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

			cout << "Какого пользователя вы хотите удалить?" << endl;

			UserService::Print(users);

			int num;

			cin >> num;
			Validator::Check<int>(num, 1, --numOfStr);

			cout << "Вы уверены?" << endl;

			cout << "1. да" << endl;
			cout << "2. нет" << endl;

			int sureChoice;
			cin >> sureChoice;
			Validator::Check<int>(sureChoice, 1, 2);

			if (sureChoice == 1)
			{
				usS.Delete(users, --num);
				cout << "Пользователь был успешно удален!" << endl;
			}

			break;

		case 3: //FilterSortUser();
			break;

		case 4:
			cout << "Выберите пользователя, которого хотите сделать администратором" << endl;

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

		cout << "===== Меню для работы с информацией о заказах =====" << endl;
		cout << "1. Просмотреть все заказы" << endl;
		cout << "2. Удалить заказ" << endl;
		cout << "3. Сортировать или фильтровать заказы" << endl;
		cout << "4. Выйти в меню администратора" << endl;

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

			cout << "Какой заказ вы хотите удалить?" << endl;

			OrderService::Print(orders);

			int num;

			cin >> num;
			Validator::Check<int>(num, 1, --numOfStr);

			cout << "Вы уверены?" << endl;

			cout << "1. да" << endl;
			cout << "2. нет" << endl;

			int sureChoice;
			cin >> sureChoice;
			Validator::Check<int>(sureChoice, 1, 2);

			if (sureChoice == 1)
			{
				orS.Delete(orders, --num);
				cout << "Заказ был успешно удален!" << endl;
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

		cout << "======== Меню пользователя ========" << endl;
		cout << "1. Просмотреть информацию о себе" << endl;
		cout << "2. Отредактировать информацию о себе" << endl;
		cout << "3. Просмотреть каталог автомобилей" << endl;
		cout << "4. Сортировать или фильтровать автомобили" << endl;
		cout << "5. Сделать заказ" << endl;
		cout << "6. Просмотреть собственные заказы" << endl;
		cout << "7. Вернуться в главное меню" << endl;

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