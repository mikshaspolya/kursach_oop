#pragma once
#include "Libraries.h"

class RegistrationDTO
{
	int id;
	string name;
	string surname;
	int phone;
	time_t birthday;
	string login;
	string password;
	bool role;

public:
	RegistrationDTO();
	RegistrationDTO(string name, string surname, int phone, time_t birthday, string login, string password, bool role);
	RegistrationDTO(const RegistrationDTO& user);

	void SetId(int id);
	void SetName(string name);
	void SetSurname(string surname);
	void SetPhone(int phone);
	void SetBirthday(time_t birthday);
	void SetLogin(string login);
	void SetPassword(string password);
	void SetRole(bool role);

	int GetId();
	string GetName();
	string GetSurname();
	int GetPhone();
	time_t GetBirthday();
	string GetLogin();
	string GetPassword();
	bool GetRole();
};

