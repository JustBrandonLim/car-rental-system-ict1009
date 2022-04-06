#pragma once

#include <iostream>

using namespace std;

#include "Rental.h"

#include "Account.h"
#include "Car.h"

class HourlyRental : public Rental
{
private:
	double hourlyRate;
	int hours;
public:
	HourlyRental(Account* account, Car* car, double hourlyRate, int hours, int rentalType = 0);
	double calculateTotalFees();
	void displayRental();
	friend ostream& operator<<(ostream& cout, HourlyRental& hourlyRental);
};

