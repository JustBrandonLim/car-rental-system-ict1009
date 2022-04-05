#pragma once

#include "Insurance.h"

#include <string>

class CollisionInsurance : virtual public Insurance
{
private:
	double payableAmount;
public:
	virtual ~CollisionInsurance() = default;
	double getPayableAmount() override;
	void setPayableAmount(int) override;
	void submitCarDamages(std::string, std::string);
	void showCarDamages(std::string);
};

