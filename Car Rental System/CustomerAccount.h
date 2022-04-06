#pragma once

#include <iostream>

#include "Account.h"
#include "CarManager.h"

#include "Car.h"

#include "Insurance.h"
#include "CollisionInsurance.h"
#include "InjuryInsurance.h"
#include "TheftInsurance.h"
#include "FullCoverageInsurance.h"

class CustomerAccount : public Account
{
private:
	CarManager* carManager;
	std::vector<std::unique_ptr<Insurance>> insurances;
	std::vector<std::unique_ptr<Insurance>> newInsurances;
	bool insuranceCheck[4] = { false };
public:
	CustomerAccount();
	CustomerAccount(CarManager*, std::string, std::string, std::string, std::string, std::string);
	void doCustomer();
	void doInsurance();
	void displayInsurance();
	void storeInsuranceDetails();
	void readInsuranceDetails();
	void submitClaims();
	void doReserve();
	void doUnreserved();
	void doDisplayCars();
	void doCompare();
	void doPayment();
};