#pragma once

#include <iostream>

using namespace std;

#include "Account.h"
#include "Car.h"

class Rental
{
protected:
	Account* account;
	Car* car;
	int rentalType;
public:
	Rental(Account* account, Car* car);
	~Rental();
	Account* getAccount();
	Car* getCar();
	int getRentalType();
	virtual void displayRental();
};

