#pragma once
#include "Libraries.h"

template <class UserDTO>
class UserService : public BaseService<UserDTO>
{
private:
	static bool CompareLogin(string login);
	static bool CompareLoginAndPassword(string login, string password);
	static bool CheckIsAdmin(UserDTO obj);

public:
	static void Create();
	static vector<UserDTO> Read();
	static void Update(UserDTO* obj);
	static void Delete(vector<UserDTO> users, int idOfUser);
	static UserDTO ReadSpecific(int id);
	static void Authorization(UserDTO& auth);
	static void MakeAdmin(vector<UserDTO> users, int idOfUser);

	static int CountNumOfStr();
	static int GetLastId();
	static void UpdateLastId(int newId);
	static void EncryptPassword(string& password);
	static void Print(vector<UserDTO> users);
};

