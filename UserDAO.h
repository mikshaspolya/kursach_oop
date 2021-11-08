#pragma once
#include "BaseDAO.h"
#include "UserDTO.h"

class UserDAO : public BaseDAO<UserDTO>
{
public:
	void Create(UserDTO obj) override;
	vector<UserDTO> Read() override;
	void Update(vector<UserDTO> users) override;
};


