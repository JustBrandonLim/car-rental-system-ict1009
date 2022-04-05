#pragma once

#include <iostream>
#include <vector>

#include "Rental.h"

class RentalManager
{
private:
	std::vector<Rental> rentals;
	static RentalManager* instance;
	RentalManager();
	RentalManager(const RentalManager&);
	RentalManager& operator=(const RentalManager&);
public:
	static RentalManager* getInstance();
	void addRental(Rental);
	void removeRental(Rental);
	void displayRentals();
};

