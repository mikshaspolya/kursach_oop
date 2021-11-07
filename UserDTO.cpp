#include "UserDTO.h"

UserDTO::UserDTO()
{
}

UserDTO::UserDTO(string name, string surname, int phone, tm birthday, string login, string password, bool role)
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

UserDTO::UserDTO(const UserDTO& user)
{
	this->name = user.name;
	this->surname = user.surname;
	this->phone = user.phone;
	this->birthday = user.birthday;
	this->login = user.login;
	this->password = user.password;
	this->role = user.role;
}

void UserDTO::SetId(int id)
{
	this->id = id;
}

void UserDTO::SetName(string name)
{
	this->name = name;
}

void UserDTO::SetSurname(string surname)
{
	this->surname = surname;
}

void UserDTO::SetPhone(int phone)
{
	this->phone = phone;
}

void UserDTO::SetBirthday(tm birthday)
{
	this->birthday.tm_mday = birthday.tm_mday;
	this->birthday.tm_mon = birthday.tm_mon;
	this->birthday.tm_year = birthday.tm_year;
}

void UserDTO::SetLogin(string login)
{
	this->login = login;
}

void UserDTO::SetPassword(string password)
{
	this->password = password;
}

void UserDTO::SetRole(bool role)
{
	this->role = role;
}

int UserDTO::GetId()
{
	return this->id;
}

string UserDTO::GetName()
{
	return this->name;
}

string UserDTO::GetSurname()
{
	return this->surname;
}

int UserDTO::GetPhone()
{
	return this->phone;
}

tm UserDTO::GetBirthday()
{
	return this->birthday;
}

string UserDTO::GetLogin()
{
	return this->login;
}

string UserDTO::GetPassword()
{
	return this->password;
}

bool UserDTO::GetRole()
{
	return this->role;
}