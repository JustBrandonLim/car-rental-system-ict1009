#pragma once

#include "CustomerAccount.h"
#include "Car.h"

#include "DateTime.h"

class Account;
class Car;

class Rental
{
private:
	CustomerAccount customerAccount;
	Car car;
	DateTime startDateTime;
	DateTime endDateTime;
	double totalFees;
	//TODO: Insurance?
public:
	Rental();
	Rental(CustomerAccount, Car, DateTime, DateTime);
	CustomerAccount getCustomerAccount();
	Car getCar();
	DateTime getStartDateTime();
	DateTime getEndDateTime();
	double getTotalFees();
};
