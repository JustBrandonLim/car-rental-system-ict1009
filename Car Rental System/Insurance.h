#pragma once

#include <string>
#include "Account.h"

class Account;

class Insurance
{
private:
	Account insuranceOwner;
	double payableAmount;
	std::string description;
public:
	Insurance(Account, double, std::string);
	double getPayableAmount();
	std::string getDescription();
	void setPayableAmount(double payableAmount);
	void setDescription(std::string description);
	Account getInsuranceOwner();
};

