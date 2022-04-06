#pragma once

#include <string>
#include <iostream>

using namespace std;

#include "Account.h"
#include "CarManager.h"

class AdminAccount : public Account
{
private:
	CarManager* carManager;
public:
	AdminAccount(CarManager* carManager, string username, string password, string name, string dateOfBirth, string address, bool admin);
	bool addCar(string carPlate, string model, string transmission, double rentalRate, bool available);
	bool removeCar(int id);
};