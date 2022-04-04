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
	CollisionInsurance();
	CollisionInsurance(CustomerAccount, int, std::string);
	~CollisionInsurance();
	double getPayableAmount();
	void setPayableAmount(int);
	void submitCarDamages();
	void showCarDamages();
};

