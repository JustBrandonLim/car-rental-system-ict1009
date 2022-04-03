#pragma once

#include <string>
#include "CustomerAccount.h"

class Account;

class Insurance
{
private:
	CustomerAccount insuranceOwner;
	//double payableAmount;
	int duration;
	std::string description;
public:
	Insurance();
	Insurance(CustomerAccount, int, std::string);
	//double getPayableAmount();
	int getDuration();
	void setDuration(int);
	std::string getDescription();
	//void setPayableAmount(double payableAmount);
	void setDescription(std::string description);
	void setInsuranceOwner(CustomerAccount insuranceOwner);
	CustomerAccount getInsuranceOwner();
};

