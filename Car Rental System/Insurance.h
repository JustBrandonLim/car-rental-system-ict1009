#pragma once

#include <string>

using namespace std;


class Insurance
{
private:
	double payableAmount;
	int duration;
	std::string description;
	bool paymentStatus = false;
public:
	virtual ~Insurance() = default;
	int getDuration();
	void setDuration(int);
	std::string getDescription();
	virtual double getPayableAmount() = 0;
	virtual void setPayableAmount(int) = 0;
	void setDescription(std::string description);
	void setPaymentStatus(int);
	int getPaymentStatus();
};

