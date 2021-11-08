#include "OrderDTO.h"

OrderDTO::OrderDTO()
{
}

OrderDTO::OrderDTO(double cost, int idUser, string name, string surname, int idCar, string brand, string model, tm date)
{
    this->cost = cost;
    this->idUser = idUser;
    this->name = name;
    this->surname = surname;
    this->idCar = idCar;
    this->brand = brand;
    this->model = model;
    this->date.tm_mday = date.tm_mday;
    this->date.tm_mon = date.tm_mon;
    this->date.tm_year = date.tm_year;
}

OrderDTO::OrderDTO(const OrderDTO& order)
{
    this->cost = order.cost;
    this->idUser = order.idUser;
    this->name = order.name;
    this->surname = order.surname;
    this->idCar = order.idCar;
    this->brand = order.brand;
    this->model = order.model;
    this->date.tm_mday = order.date.tm_mday;
    this->date.tm_mon = order.date.tm_mon;
    this->date.tm_year = order.date.tm_year;
}

void OrderDTO::SetId(int id)
{
    this->id = id;
}

void OrderDTO::SetCost(double cost)
{
    this->cost = cost;
}

void OrderDTO::SetIdUser(int idUser)
{
    this->idUser = idUser;
}

void OrderDTO::SetName(string name)
{
    this->name = name;
}

void OrderDTO::SetSurname(string surname)
{
    this->surname = surname;
}

void OrderDTO::SetIdCar(int idCar)
{
    this->idCar = idCar;
}

void OrderDTO::SetBrand(string brand)
{
    this->brand = brand;
}

void OrderDTO::SetModel(string model)
{
    this->model = model;
}

void OrderDTO::SetDate(tm date)
{
    this->date.tm_mday = date.tm_mday;
    this->date.tm_mon = date.tm_mon;
    this->date.tm_year = date.tm_year;
}

int OrderDTO::GetId()
{
    return this->id;
}

double OrderDTO::GetCost()
{
    return this->cost;
}

int OrderDTO::GetIdUser()
{
    return this->idUser;
}

string OrderDTO::GetName()
{
    return this->name;
}

string OrderDTO::GetSurname()
{
    return this->surname;
}

int OrderDTO::GetIdCar()
{
    return this->idCar;
}

string OrderDTO::GetBrand()
{
    return this->brand;
}

string OrderDTO::GetModel()
{
    return this->model;
}

tm OrderDTO::GetDate()
{
    return this->date;
}