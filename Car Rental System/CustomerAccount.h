#pragma once

#include <iostream>

#include "Account.h"
#include "CarManager.h"
#include "RentalManager.h"
#include "Car.h"
#include "Rental.h"

#include "Insurance.h"
#include "CollisionInsurance.h"
#include "InjuryInsurance.h"
#include "TheftInsurance.h"
#include "FullCoverageInsurance.h"

class CustomerAccount : public Account
{
private:
	CarManager* carManager;
	RentalManager* rentalManager;
public:
	CustomerAccount();
	CustomerAccount(CarManager*, RentalManager*, std::string, std::string, std::string, std::string, std::string);
	void doCustomer();
	void rentCar();
};