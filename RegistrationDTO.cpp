#include "RegistrationDTO.h"

RegistrationDTO::RegistrationDTO()
{
}

RegistrationDTO::RegistrationDTO(string name, string surname, int phone, time_t birthday, string login, string password, bool role)
{
	this->name = name;
	this->surname = surname;
	this->phone = phone;
	this->birthday = birthday;
	this->login = login;
	this->password = password;
	this->role = role;
}

RegistrationDTO::RegistrationDTO(const RegistrationDTO& user)
{
	this->name = user.name;
	this->surname = user.surname;
	this->phone = user.phone;
	this->birthday = user.birthday;
	this->login = user.login;
	this->password = user.password;
	this->role = user.role;
}

void RegistrationDTO::SetId(int id)
{
	this->id = id;
}

void RegistrationDTO::SetName(string name)
{
	this->name = name;
}

void RegistrationDTO::SetSurname(string surname)
{
	this->surname = surname;
}

void RegistrationDTO::SetPhone(int phone)
{
	this->phone = phone;
}

void RegistrationDTO::SetBirthday(time_t birthday)
{
	this->birthday = birthday;
}

void RegistrationDTO::SetLogin(string login)
{
	this->login = login;
}

void RegistrationDTO::SetPassword(string password)
{
	this->password = password;
}

void RegistrationDTO::SetRole(bool role)
{
	this->role = role;
}

int RegistrationDTO::GetId()
{
	return this->id;
}

string RegistrationDTO::GetName()
{
	return this->name;
}

string RegistrationDTO::GetSurname()
{
	return this->surname;
}

int RegistrationDTO::GetPhone()
{
	return this->phone;
}

time_t RegistrationDTO::GetBirthday()
{
	return this->birthday;
}

string RegistrationDTO::GetLogin()
{
	return this->login;
}

string RegistrationDTO::GetPassword()
{
	return this->password;
}

bool RegistrationDTO::GetRole()
{
	return this->role;
}