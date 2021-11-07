#pragma once
#include "Libraries.h"

class Validator
{
public:
	template <class T>
	static void Check(T& value, T lim1, T lim2);


	static bool CheckLogin(string login);
	static bool CheckPassword(string password);
	static bool CheckDate(struct tm d);
	static bool CheckPhone(int phone);
	static bool CheckName(string name);
	static bool CheckBrand(string brand);
	static bool CheckModel(string model);
	//static bool Check(string name);
};

template<class T>
inline void Validator::Check(T& value, T lim1, T lim2)
{
	while (cin.fail() || (value < lim1) || (value > lim2))
	{
		cin.clear();
		cin.ignore(256, '\n');

		cout << "Неверный ввод! Попробуйте снова!" << endl;

		cin >> value;
	}
}
