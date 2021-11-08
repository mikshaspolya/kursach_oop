#pragma once
#include "BaseService.h"
#include "UserDTO.h"

class UserService : public BaseService<UserDTO>
{
private:
	static bool CompareLogin(string login);
	static bool CompareLoginAndPassword(string login, string password);
	static bool CheckIsAdmin(UserDTO obj);

public:
	void Create(UserDTO obj);
	vector<UserDTO> Read();
	void Update(vector<UserDTO> users, int idOfUser, int numOfField);
	void Delete(vector<UserDTO> users, int idOfUser);
	UserDTO* ReadSpecific(int id);

	void Authorization(UserDTO& auth);
	void MakeAdmin(vector<UserDTO> users, int idOfUser);

	static int CountNumOfStr();
	static int GetLastId();
	static void UpdateLastId(int newId);
	static void EncryptPassword(string& password);
	static void Print(vector<UserDTO> users);

	ostream& printLine(ostream& stream);
	ostream& printContent(ostream& stream);
};

