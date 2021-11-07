#include "UserDAO.h"

void UserDAO::Create(UserDTO obj)
{
	ofstream fout(FILE_USERS, ios::app);

	fout << obj.GetId() << " " << obj.GetLogin() << " " << obj.GetPassword() << " " << obj.GetName() << " " << obj.GetSurname() << " " << obj.GetBirthday() << " " << obj.GetPhone() << " " << obj.GetRole() << "\n";

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
	time_t birthday;
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
		fin >> birthday;
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
		fout << users[i].GetId() << " " << users[i].GetLogin() << " " << users[i].GetPassword() << " " << users[i].GetName() << " " << users[i].GetSurname()
			<< " " << users[i].GetBirthday() << " " << users[i].GetPhone() << " " << users[i].GetRole() << endl;
	}
	fout.close();
}
