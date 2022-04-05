#pragma once

#include <iostream>

#include "Account.h"
#include "CarManager.h"
#include "RentalManager.h"
#include "Car.h"

class AdminAccount : public Account
{
private:
	CarManager* carManager;
	RentalManager* rentalManager;
public:
	AdminAccount();
	AdminAccount(CarManager*, RentalManager*, std::string, std::string, std::string, std::string, std::string);
	void doAdmin();
	void addCar(Car);
	void removeCar(Car);
};

