#pragma once

#include "Insurance.h"

#include <string>

class CollisionInsurance : virtual public Insurance
{
private:
	double payableAmount;
public:
	CollisionInsurance();
	CollisionInsurance(int, std::string);
	~CollisionInsurance();
	double getPayableAmount();
	void setPayableAmount(int);
	void submitCarDamages(std::string);
	void showCarDamages(std::string);
};

