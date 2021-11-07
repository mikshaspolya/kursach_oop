#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <regex>
#include <windows.h>

#include "BaseDAO.h"
#include "BaseService.h"
#include "Car.h"
#include "CarDAO.h"
#include "CarDTO.h"
#include "CarService.h"
#include "Menu.h"
#include "Order.h"
#include "OrderDAO.h"
#include "OrderDTO.h"
#include "OrderService.h"
#include "RegistrationDTO.h"
#include "User.h"
#include "UserDAO.h"
#include "UserDTO.h"
#include "UserService.h"
#include "Validator.h"
#include "Validator.h"

using namespace std;

const bool IS_ADMIN = true;

const string FILE_USERS = "passwordUser.txt";
const string FILE_ORDERS = "orders.txt";
const string FILE_CARS = "cars.txt";
const string FILE_LAST_ID = "lastId.txt";

