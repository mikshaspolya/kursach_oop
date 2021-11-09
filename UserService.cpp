#include "UserService.h"

void UserService::Create(UserDTO usDTO)
{
	UserDAO usDAO;

	int id;
	string name;
	string surname;
	int phone;
	struct tm* birthday;
	string login;
	string password;
	bool role;

	bool date = false, uniqueness = false, check = false;

	cout << "������� ���������� � ����: " << endl;

	cout << "������� ���� ���: "; 
	cin >> name;

	while (!Validator::CheckName(name))
	{
		cout << "� ����� ���� ����������� �������, ����������, ���������� �����!" << endl;
		cin >> name;
	}

	cout << "������� ���� �������: "; 
	cin >> surname;

	while (!Validator::CheckName(surname))
	{
		cout << "� ������� ���� ����������� �������, ����������, ���������� �����!" << endl;
		cin >> surname;
	}

	cout << "������� ��� ����� �������� (7 ����): "; 
	cin >> phone;
	
	while (!Validator::CheckPhone(phone))
	{
		cout << "� �������� ���� ����������� �������, ����������, ���������� �����!" << endl;
		cin >> phone;
	}

	cout << "������� ��� ���� ��������: ";
	cin >> birthday->tm_mday;
	cin >> birthday->tm_mon;
	cin >> birthday->tm_year;

	while (!Validator::CheckDate(*birthday))
	{
		cout << "����� ���� �� ����������, ����������, ���������� �����!" << endl;
		cin >> birthday->tm_mday;
		cin >> birthday->tm_mon;
		cin >> birthday->tm_year;
	}

	cout << "������� ��� ������� �����: "; 
	cin >> login;

	while (UserService::CompareLogin(login) || !Validator::CheckLogin(login))
	{
		if (UserService::CompareLogin(login))
		{
			cout << "������������ � ����� �� ������� ��� ����������, ����������, �������� ������!" << endl;
			cin >> login;
		}
		if (!Validator::CheckLogin(login))
		{
			cout << "� ������ ���� ����������� �������, ����������, �������� ������!" << endl;
			cin >> login;
		}
	}

	unsigned char p;

	cout << "������� ������: ";
	do
	{
		p = _getch();

		if (p == 13) break;
		if (p == '\b' && !password.empty())
		{
			cout << '\b';
			cout << ' ';
			cout << '\b';

			password.pop_back();
			continue;
		}
		if (isalnum((unsigned char)p))
		{
			cout << '*';
			password.push_back(p);
		}

	} while (true);


	while (!Validator::CheckPassword(password))
	{
		cout << "� ������ ���� ����������� �������, ����������, �������� ������!" << endl;

		do
		{
			p = _getch();

			if (p == 13) break;
			if (p == '\b' && !password.empty())
			{
				cout << '\b';
				cout << ' ';
				cout << '\b';

				password.pop_back();
				continue;
			}
			if (isalnum((unsigned char)p))
			{
				cout << '*';
				password.push_back(p);
			}
		} while (true);
	}

	EncryptPassword(password);

	role = false;

	id = GetLastId();

	usDTO.SetId(id);
	usDTO.SetName(name);
	usDTO.SetSurname(surname);
	usDTO.SetPhone(phone);
	usDTO.SetBirthday(*birthday);
	usDTO.SetLogin(login);
	usDTO.SetPassword(password);
	usDTO.SetRole(role);

	UpdateLastId(++id);

	system("cls");

	usDAO.Create(usDTO);

	cout << "�� ������� ������������������ " << name << "! ������� � ���� �������." << endl;
}

vector<UserDTO> UserService::Read()
{
	UserDAO usDAO;
	return usDAO.Read();
}

void UserService::Update(vector<UserDTO> users, int idOfUser, int numOfField)
{
}

void UserService::Delete(vector<UserDTO> users, int idOfUser)
{
	UserDAO usDAO;

	users.erase(users.begin() + idOfUser);

	usDAO.Update(users);
}

UserDTO* UserService::ReadSpecific(int id)
{
	//return UserService*();
}

void UserService::Authorization(UserDTO& auth)
{
	string login;
	string password;

	bool check = false;

	cout << "������� �����: ";
	cin >> login;

	cout << "������� ������: ";
	cin >> password;

	UserService::EncryptPassword(password);

	system("cls");

	if (!UserService::CompareLoginAndPassword(login, password))
		 cout << "����������� ������� ����� ��� ������!" << endl;
}

void UserService::MakeAdmin(vector<UserDTO> users, int idOfUser)
{
	UserDAO usDAO;

	users[idOfUser].SetRole(true);

	usDAO.Update(users);
}

int UserService::CountNumOfStr()
{
	int numOfLines = 0;

	string buff;

	ifstream fin(FILE_USERS);
	if (fin.is_open())
	{
		for (int i = 0; !fin.eof(); i++) {
			getline(fin, buff, '\n');
			numOfLines++;
		}
	}
	else cout << "���� ���� �� ����������!" << endl;

	fin.close();

	return numOfLines;
}

int UserService::GetLastId()
{
	int lastId[3];

	ifstream fin(FILE_LAST_ID);

	for (int i = 0; i < 3; i++)
	{
		fin >> lastId[i];
	}

	fin.close();

	return lastId[0];
}

void UserService::UpdateLastId(int newId)
{
	int lastId[3];

	ifstream fin(FILE_LAST_ID);

	for (int i = 0; i < 3; i++)
	{
		fin >> lastId[i];
	}

	fin.close();

	ofstream fout(FILE_LAST_ID);

	lastId[0] = newId;

	for (int i = 0; i < 3; i++)
	{
		fout << lastId[i] << " ";
	}

	fout.close();
}

void UserService::EncryptPassword(string& password)
{

}

void UserService::Print(vector<UserDTO> users)
{
	int numOfStr = UserService::CountNumOfStr();

	cout << "+";
	for (int j = 0; j < 8; j++)
	{
		cout << &printLine;
	}
	cout << endl;

	cout << &printContent << "�������������" << &printContent << "���" << &printContent << "�������" << &printContent << "�������" << &printContent <<
		"���� ��������" << &printContent << "�����" << &printContent << "����";
	cout << "|" << endl;

	cout << "+";
	for (int j = 0; j < 8; j++)
	{
		cout << &printLine;
	}
	cout << endl;

	for (int i = 0; i < numOfStr - 1; i++)
	{
		tm d = users[i].GetBirthday();
		string date = d.tm_mday + " " + d.tm_mon;
		date += " " + d.tm_year;

		cout << &printContent << users[i].GetId() << &printContent << users[i].GetName() << &printContent << users[i].GetSurname() << &printContent <<
				users[i].GetPhone() << &printContent << date << &printContent << users[i].GetLogin() << &printContent << users[i].GetRole();
		cout << "|" << endl;
		cout << "+";
		for (int j = 0; j < 8; j++)
		{
			cout << &printLine;
		}
		cout << endl;
	}
}

ostream& UserService::printLine(ostream& stream)
{
	stream << "-------------+";
	return stream;
}

ostream& UserService::printContent(ostream& stream)
{
	stream.setf(ios::right);
	stream << "|" << setw(13) << setfill(' ');
	return stream;
}

bool UserService::CompareLogin(string login)
{
	UserService us;

	vector<UserDTO> users = us.Read();

	int numOfStr = UserService::CountNumOfStr();

	bool result = false;

	for (int i = 0; i < numOfStr - 1; i++)
	{
		if (login == users[i].GetLogin())
			result = true;
	}

	return result;
}

bool UserService::CompareLoginAndPassword(string login, string password)
{
	UserService us;

	vector<UserDTO> users = us.Read();

	int numOfStr = UserService::CountNumOfStr();
	int id = -1;

	bool result = false;

	for (int i = 0; i < numOfStr - 1; i++)
	{
		if (login == users[i].GetLogin() && password == users[i].GetPassword())
		{
			id = i;
			result = true;
		}
	}

	if (id != -1)
	{
		if (UserService::CheckIsAdmin(users[id]))
			MenuAdmin(id);
		else MenuUser(id);
	}

	return result;
}
bool UserService::CheckIsAdmin(UserDTO obj)
{
	bool result = false;

	if (obj.GetRole()) result = true;

	return result;
}
