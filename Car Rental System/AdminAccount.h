#pragma once

#include <iostream>

#include "Account.h"
#include "CarManager.h"
#include "Car.h"

class AdminAccount : public Account
{
private:
	CarManager* carManager;

public:
	AdminAccount();
	AdminAccount(CarManager*, std::string, std::string, std::string, std::string, std::string);
	void doAdmin();
	void addCar(Car);
	void removeCar(Car);
};

