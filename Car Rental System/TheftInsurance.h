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
	TheftInsurance();
	TheftInsurance(CustomerAccount, int, std::string);
	~TheftInsurance();
	double getPayableAmount();
	void setPayableAmount(int);
	void submitStolenItems();
	void showStolenItems();
};

