#pragma once

#include <iostream>

using namespace std;

#include "Rental.h"

#include "Account.h"
#include "Car.h"

class DailyRental : virtual public Rental
{
private:
	double dailyRate;
	int days;
public:
	DailyRental(Account* account, Car* car, double dailyRate, int days, int rentalType = 1);
	double calculateTotalFees();
	void displayRental();
	friend ostream& operator<<(ostream& cout, DailyRental& dailyRental);
};

