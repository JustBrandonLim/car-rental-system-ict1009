#pragma once

#include "Insurance.h"
#include "Account.h"

#include <string>

class Account;

class CollisionInsurance : virtual public Insurance
{
public:
	CollisionInsurance(Account, double, std::string);
	void submitCarDamages();
	void showCarDamages();
};

