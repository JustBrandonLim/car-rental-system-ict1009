#pragma once

#include "Account.h"
#include "CarManager.h"
#include "Car.h"
#include <vector>
#include <string>

class Account;

class AdminAccount : public Account {
private:
	CarManager carManager;
	std::string adminId;
public:
	AdminAccount();
	AdminAccount(std::string, std::string, std::string, std::string, std::string, std::string, CarManager);
	std::string getAdminId();
	void addCar(Car);
	//void editCar(Car);
	void removeCar(Car);
	void displayCars();
};
