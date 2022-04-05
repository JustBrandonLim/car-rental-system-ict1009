#pragma once

#include <iostream>

#include "CustomerAccount.h"
#include "Car.h"

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

