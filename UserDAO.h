#pragma once
#include "BaseDAO.h"

class UserDAO : public BaseDAO<UserDTO>
{
public:
	void Create(UserDTO obj) override;
	vector<UserDTO> Read() override;
	void Update(vector<UserDTO> users) override;
};


