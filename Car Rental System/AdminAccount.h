#pragma once

#include "Account.h"
#include "CarManager.h"
#include "Car.h"
#include <vector>
#include <string>

class Account;

class AdminAccount : public Account {
private:
	CarManager* carManager;
public:
	AdminAccount();
	AdminAccount(std::string, std::string, std::string, std::string, std::string, std::string, CarManager*);
	void addCar(Car);
	void setServicing(Car);
	void removeCar(Car);
	void displayCars();
};
