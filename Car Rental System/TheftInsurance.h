#pragma once

#include "Insurance.h"
#include "Account.h"

#include <string>

class Account;

class TheftInsurance : virtual public Insurance
{
public:
	TheftInsurance(Account, double, std::string);
	void submitStolenItems();
	void showStolenItems();
};

