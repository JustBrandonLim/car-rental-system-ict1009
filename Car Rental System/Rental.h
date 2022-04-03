#pragma once

#include <string>

using namespace std;

#include "CustomerAccount.h"
#include "Car.h"

class Account;

class Rental
{
private:
	CustomerAccount customerAccount;
	Car car;
public:
	Rental();
	Rental(CustomerAccount, Car);
	CustomerAccount getCustomerAccount();
	Car getCar();
};
