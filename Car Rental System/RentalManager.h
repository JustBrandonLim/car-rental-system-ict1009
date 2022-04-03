#pragma once

#include <vector>
#include <algorithm>

#include "Rental.h"

#include "Car.h"
#include "CustomerAccount.h"

class RentalManager
{
private:
	std::vector<Rental> rentals;

public:
	RentalManager();
	std::vector<Rental> getRentals();
	Rental getRentalByAccount(CustomerAccount);
	Rental getRentalByCar(Car);
	void addRental(Rental);
	void cancelRental(Rental);
};