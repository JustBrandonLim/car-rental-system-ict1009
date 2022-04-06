#pragma once

#include <vector>
#include <iostream>

using namespace std;

#include "Rental.h"
#include "HourlyRental.h"
#include "DailyRental.h"

class RentalManager
{
private:
	vector<Rental*> rentals;
public:
	RentalManager();
	void loadRentals();
	Rental* getRentalByIndex(int id);
	Rental* getRentalByCarPlate(string carPlate);
	void addHourlyRental(Account* account, Car* car, double hourlyRate, int hours);
	void addDailyRental(Account* account, Car* car, double dailyRate, int days);
	void cancelRentalByIndex(int id);
	void displayRentalsByAccountUsername(string username);
};
