#pragma once

#include "Insurance.h"
#include "CustomerAccount.h"

#include <string>

class Account;

class TheftInsurance : virtual public Insurance
{
private:
	double payableAmount;
public:
	TheftInsurance(CustomerAccount, int, std::string);
	double getPayableAmount();
	void setPayableAmount(int);
	void submitStolenItems();
	void showStolenItems();
};

