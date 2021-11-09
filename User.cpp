#include "User.h"

User::User()
{
}

User::User(string name, string surname, int phone, tm birthday, string login, string password, bool role)
{
	this->name = name;
	this->surname = surname;
	this->phone = phone;
	this->birthday.tm_mday = birthday.tm_mday;
	this->birthday.tm_mon = birthday.tm_mon;
	this->birthday.tm_year = birthday.tm_year;
	this->login = login;
	this->password = password;
	this->role = role;
}

User::User(const User& user)
{
	this->name = user.name;
	this->surname = user.surname;
	this->phone = user.phone;
	this->birthday = user.birthday;
	this->login = user.login;
	this->password = user.password;
	this->role = user.role;
}

void User::SetId(int id)
{
	this->id = id;
}

void User::SetName(string name)
{
	this->name = name;
}

void User::SetSurname(string surname)
{
	this->surname = surname;
}

void User::SetPhone(int phone)
{
	this->phone = phone;
}

void User::SetBirthday(tm birthday)
{
	this->birthday.tm_mday = birthday.tm_mday;
	this->birthday.tm_mon = birthday.tm_mon;
	this->birthday.tm_year = birthday.tm_year;
}

void User::SetLogin(string login)
{
	this->login = login;
}

void User::SetPassword(string password)
{
	this->password = password;
}

void User::SetRole(bool role)
{
	this->role = role;
}

int User::GetId()
{
	return this->id;
}

string User::GetName()
{
	return this->name;
}

string User::GetSurname()
{
	return this->surname;
}

int User::GetPhone()
{
	return this->phone;
}

tm User::GetBirthday()
{
	return this->birthday;
}

string User::GetLogin()
{
	return this->login;
}

string User::GetPassword()
{
	return this->password;
}

bool User::GetRole()
{
	return this->role;
}
