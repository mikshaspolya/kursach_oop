#include "UserDAO.h"

void UserDAO::Create(UserDTO obj)
{
	tm date = obj.GetBirthday();

	string d = date.tm_mday + " " + date.tm_mon;
	d += " " + date.tm_year;

	ofstream fout(FILE_USERS, ios::app);

	fout << obj.GetId() << " " << obj.GetLogin() << " " << obj.GetPassword() << " " << obj.GetName() << " " << obj.GetSurname() << " " << d << " " << obj.GetPhone() << " " << obj.GetRole() << "\n";

	fout.close();
}

vector<UserDTO> UserDAO::Read()
{
	int numOfStr = UserService::CountNumOfStr();

	vector<UserDTO> users;

	int id;
	string name;
	string surname;
	int phone;
	tm birthday;
	string login;
	string password;
	bool role;

	ifstream fin(FILE_USERS);

	for (int i = 0; i < numOfStr - 1; i++) {
		fin >> id;
		fin >> login;
		fin >> password;
		fin >> name;
		fin >> surname;
		fin >> birthday.tm_mday;
		fin >> birthday.tm_mon;
		fin >> birthday.tm_year;
		fin >> phone;
		fin >> role;

		users[i].SetId(id);
		users[i].SetLogin(login);
		users[i].SetPassword(password);
		users[i].SetName(name);
		users[i].SetSurname(surname);
		users[i].SetBirthday(birthday);
		users[i].SetPhone(phone);
		users[i].SetRole(role);
	}
	fin.close();

	return users;
}

void UserDAO::Update(vector<UserDTO> users)
{
	int numOfStr = UserService::CountNumOfStr();

	ofstream fout(FILE_USERS, ios::out);
	for (int i = 0; i < numOfStr - 1; i++)
	{
		tm date = users[i].GetBirthday();

		string d = date.tm_mday + " " + date.tm_mon;
		d += " " + date.tm_year;

		fout << users[i].GetId() << " " << users[i].GetLogin() << " " << users[i].GetPassword() << " " << users[i].GetName() << " " << users[i].GetSurname()
			<< " " << d << " " << users[i].GetPhone() << " " << users[i].GetRole() << endl;
	}
	fout.close();
}
