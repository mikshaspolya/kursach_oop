#pragma once
#include "Libraries.h"

class UserDTO
{
	int id;
	string name;
	string surname;
	int phone;
	struct tm birthday;
	string login;
	string password;
	bool role;

public:
	UserDTO();
	UserDTO(string name, string surname, int phone, tm birthday, string login, string password, bool role);
	UserDTO(const UserDTO& user);

	void SetId(int id);
	void SetName(string name);
	void SetSurname(string surname);
	void SetPhone(int phone);
	void SetBirthday(tm birthday);
	void SetLogin(string login);
	void SetPassword(string password);
	void SetRole(bool role);

	int GetId();
	string GetName();
	string GetSurname();
	int GetPhone();
	tm GetBirthday();
	string GetLogin();
	string GetPassword();
	bool GetRole();
};

