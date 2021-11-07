#include "Order.h"

Order::Order()
{
}

Order::Order(double cost, int idUser, string name, string surname, int idCar, string brand, string model, time_t date)
{
    this->cost = cost;
    this->idUser = idUser;
    this->name = name;
    this->surname = surname;
    this->idCar = idCar;
    this->brand = brand;
    this->model = model;
    this->date = date;
}

Order::Order(const Order& order)
{
    this->cost = order.cost;
    this->idUser = order.idUser;
    this->name = order.name;
    this->surname = order.surname;
    this->idCar = order.idCar;
    this->brand = order.brand;
    this->model = order.model;
    this->date = order.date;
}

void Order::SetCost(double cost)
{
    this->cost = cost;
}

void Order::SetIdUser(int idUser)
{
    this->idUser = idUser;
}

void Order::SetName(string name)
{
    this->name = name;
}

void Order::SetSurname(string surname)
{
    this->surname = surname;
}

void Order::SetIdCar(int idCar)
{
    this->idCar = idCar;
}

void Order::SetBrand(string brand)
{
    this->brand = brand;
}

void Order::SetModel(string model)
{
    this->model = model;
}

void Order::SetDate(time_t date)
{
    this->date = date;
}

double Order::GetCost()
{
    return this->cost;
}

int Order::GetIdUser()
{
    return this->idUser;
}

string Order::GetName()
{
    return this->name;
}

string Order::GetSurname()
{
    return this->surname;
}

int Order::GetIdCar()
{
    return this->idCar;
}

string Order::GetBrand()
{
    return this->brand;
}

string Order::GetModel()
{
    return this->model;
}

time_t Order::GetDate()
{
    return this->date;
}
