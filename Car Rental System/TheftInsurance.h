#pragma once

#include "Insurance.h"

#include <string>

class TheftInsurance : virtual public Insurance
{
private:
	double payableAmount;
public:
	virtual ~TheftInsurance() = default;
	double getPayableAmount();
	void setPayableAmount(int);
	void submitStolenItems(std::string, std::string);
	void showStolenItems(std::string);
};

