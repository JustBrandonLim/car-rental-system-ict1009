#pragma once

#include <iostream>

#include "Account.h"
#include "CarManager.h"
#include "Car.h"

class CustomerAccount : public Account
{
private:
	CarManager* carManager;

public:
	CustomerAccount();
	CustomerAccount(CarManager*, std::string, std::string, std::string, std::string, std::string);
	void doCustomer();
	void rentCar();
};

