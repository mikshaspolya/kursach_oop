#pragma once
#include "Libraries.h"
#include "CarDTO.h"
#include "UserDTO.h"
#include "OrderDTO.h"
#include "CarService.h"
#include "UserService.h"
#include "OrderService.h"
#include "Validator.h"

void MainMenu();
void MenuAdmin(int id);
void MenuCars();
void MenuUsers();
void MenuOrders();
void MenuCarsFilter();
void MenuCarsSort();
void MenuUsersFilter();
void MenuUsersSort();
void MenuOrdersFilter();
void MenuOrdersSort();
void MenuUser(int id);
