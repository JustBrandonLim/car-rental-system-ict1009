#pragma once

#include "Insurance.h"
#include "CustomerAccount.h"

#include <string>

class Account;

class CollisionInsurance : virtual public Insurance
{
private:
	double payableAmount;
public:
	CollisionInsurance(CustomerAccount, int, std::string);
	double getPayableAmount();
	void setPayableAmount(int);
	void submitCarDamages();
	void showCarDamages();
};

