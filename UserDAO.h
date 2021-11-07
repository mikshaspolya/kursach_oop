#pragma once
#include "Libraries.h"

class UserDAO : public BaseDAO<UserDTO>
{
public:
	static void Create(UserDTO obj);
	static vector<UserDTO> Read();
	static void Update(vector<UserDTO> users);
};


