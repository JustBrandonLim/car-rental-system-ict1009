#pragma once

#include <string>

using namespace std;


class Insurance
{
private:
	//CustomerAccount insuranceOwner;
	//double payableAmount;
	int duration;
	std::string description;
public:
	Insurance();
	Insurance(int, std::string);
	~Insurance();
	//double getPayableAmount();
	int getDuration();
	void setDuration(int);
	std::string getDescription();
	//void setPayableAmount(double payableAmount);
	void setDescription(std::string description);
};

