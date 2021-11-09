#include "OrderService.h"

void OrderService::Create(OrderDTO obj)
{
}

vector<OrderDTO> OrderService::Read()
{
	OrderDAO orDAO;
	return orDAO.Read();
}

void OrderService::Update(vector<OrderDTO> orders, int idOfOrder, int numOfField)
{
}

void OrderService::Delete(vector<OrderDTO> orderd, int idOfOrder)
{
	OrderDAO orDAO;

	orderd.erase(orderd.begin() + idOfOrder);

	orDAO.Update(orderd);
}

OrderDTO* OrderService::ReadSpecific(int id)
{
	return nullptr;
}

int OrderService::CountNumOfStr()
{
	int numOfLines = 0;

	string buff;

	ifstream fin(FILE_ORDERS);
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

int OrderService::GetLastId()
{
	int lastId[3];

	ifstream fin(FILE_LAST_ID);

	for (int i = 0; i < 3; i++)
	{
		fin >> lastId[i];
	}

	fin.close();

	return lastId[2];
}

void OrderService::UpdateLastId(int newId)
{
	int lastId[3];

	ifstream fin(FILE_LAST_ID);

	for (int i = 0; i < 3; i++)
	{
		fin >> lastId[i];
	}

	fin.close();

	ofstream fout(FILE_LAST_ID);

	lastId[2] = newId;

	for (int i = 0; i < 3; i++)
	{
		fout << lastId[i] << " ";
	}

	fout.close();
}

void OrderService::Print(vector<OrderDTO> orders)
{
	int numOfStr = OrderService::CountNumOfStr();

	cout << "+";
	for (int j = 0; j < 7; j++)
	{
		cout << &printLine;
	}
	cout << endl;

	cout << &printContent << "Идентификатор" << &printContent << "Имя" << &printContent << "Фамилия" << &printContent << "Бренд" << &printContent <<
		"Модель" << &printContent << "Цена" << &printContent << "Дата покупки";
	cout << "|" << endl;

	cout << "+";
	for (int j = 0; j < 7; j++)
	{
		cout << &printLine;
	}
	cout << endl;

	for (int i = 0; i < numOfStr - 1; i++)
	{
		tm d = orders[i].GetDate();
		string date = d.tm_mday + " " + d.tm_mon;
		date += " " + d.tm_year;

		cout << &printContent << orders[i].GetId() << &printContent << orders[i].GetName() << &printContent << orders[i].GetSurname() << &printContent <<
			orders[i].GetBrand() << &printContent << orders[i].GetModel() << &printContent << orders[i].GetCost() << &printContent << date;
		cout << "|" << endl;
		cout << "+";
		for (int j = 0; j < 7; j++)
		{
			cout << &printLine;
		}
		cout << endl;
	}
}

ostream& OrderService::printLine(ostream& stream)
{
	stream << "-------------+";
	return stream;
}

ostream& OrderService::printContent(ostream& stream)
{
	stream.setf(ios::right);
	stream << "|" << setw(13) << setfill(' ');
	return stream;
}


