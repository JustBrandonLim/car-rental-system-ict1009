#pragma once

#include "Insurance.h"
#include "Account.h"

#include <string>

class Account;

class InjuryInsurance : virtual public Insurance
{
public:
	InjuryInsurance(Account, double, std::string);
	void submitInjuries();
};

