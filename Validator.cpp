#include "Validator.h"

bool Validator::CheckLogin(string login)
{
	bool res = false;

	regex regular("^[a-zA-Z][a-zA-Z0-9-_\.]{1,20}$");

	if (regex_match(login.c_str(), regular))
		res = true;

	return res;
}

bool Validator::CheckPassword(string password)
{
	bool res = false;

	regex regular("(?=^.{8,}$)((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$");

	if (regex_match(password.c_str(), regular))
		res = true;

	return res;
}

bool Validator::CheckDate(struct tm d)
{
	bool res = false;
	int dayInYear = 365;

	if (d.tm_year % 4 == 0 && d.tm_year % 100 != 0 || d.tm_year % 400 == 0)  dayInYear = 366;

	if (dayInYear == 365)
	{
		if (d.tm_mon == 4 || d.tm_mon == 6 || d.tm_mon == 9 || d.tm_mon == 11)
		{
			if (d.tm_mday <= 30) res = true;
		}
		else
		{
			if (d.tm_mon == 2)
			{
				if (d.tm_mday <= 28) res = true;
			}
			else if (d.tm_mday <= 31) res = true;
		}
	}
	else
	{
		if (d.tm_mon == 4 || d.tm_mon == 6 || d.tm_mon == 9 || d.tm_mon == 11)
		{
			if (d.tm_mday <= 30) res = true;
		}
		else
		{
			if (d.tm_mon == 2)
			{
				if (d.tm_mday <= 29) res = true;
			}
			else if (d.tm_mday <= 31) res = true;
		}
	}

	return res;
}

bool Validator::CheckPhone(int phone)
{
	bool res = false;

	char* ph;
	itoa(phone, ph, 10);

	regex regular("^[1-9]+[0-9]*$");

	if (regex_match(ph, regular))
		res = true;

	return res;
}

bool Validator::CheckName(string name)
{
	bool res = false;

	regex regular("[À-ß¨A-Z]{1}[à-ÿ¸a-z]{1,15}");

	if (regex_match(name.c_str(), regular))
		res = true;

	return res;
}

bool Validator::CheckBrand(string brand)
{
	bool res = false;

	regex regular("[À-ß¨A-Z]{1}[à-ÿ¸a-z\\s]{1,15}");

	if (regex_match(brand.c_str(), regular))
		res = true;

	return res;
}

bool Validator::CheckModel(string model)
{
	bool res = false;

	regex regular("[À-ß¨A-Z]{1}[à-ÿ¸a-z\\s]{1,15}");

	if (regex_match(model.c_str(), regular))
		res = true;

	return res;
}
