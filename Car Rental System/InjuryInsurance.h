#pragma once

#include "Insurance.h"

#include <string>

class InjuryInsurance : virtual public Insurance
{
private:
	double payableAmount;
public:
	virtual ~InjuryInsurance() = default;
	double getPayableAmount();
	void setPayableAmount(int);
	void submitInjuries(std::string, std::string);
	void showInjuries(std::string);
};

