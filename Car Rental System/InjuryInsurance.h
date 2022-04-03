#pragma once

#include "Insurance.h"
#include "CustomerAccount.h"

#include <string>

class Account;

class InjuryInsurance : virtual public Insurance
{
private:
	double payableAmount;
public:
	InjuryInsurance(CustomerAccount, int, std::string);
	double getPayableAmount();
	void setPayableAmount(int);
	void submitInjuries();
	void showInjuries();
};

