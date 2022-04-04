#pragma once

#include "Insurance.h"

#include <string>

class TheftInsurance : virtual public Insurance
{
private:
	double payableAmount;
public:
	TheftInsurance();
	TheftInsurance(int, std::string);
	~TheftInsurance();
	double getPayableAmount();
	void setPayableAmount(int);
	void submitStolenItems(std::string);
	void showStolenItems(std::string);
};

