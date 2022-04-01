#pragma once

#include <string>

class Insurance
{
private:
	double payableAmount;
	std::string description;
public:
	double getPayableAmount();
	std::string getDescription();
	void setPayableAmount(double payableAmount);
	void setDescription(std::string description);
};

