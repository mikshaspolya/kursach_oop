#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class User
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
	User();
	User(string name, string surname, int phone, tm birthday, string login, string password, bool role);
	User(const User& user);

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

