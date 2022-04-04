#pragma once

#include "Insurance.h"

#include <string>

class InjuryInsurance : virtual public Insurance
{
private:
	double payableAmount;
public:
	InjuryInsurance();
	InjuryInsurance(int, std::string);
	~InjuryInsurance();
	double getPayableAmount();
	void setPayableAmount(int);
	void submitInjuries(std::string);
	void showInjuries(std::string);
};

