#include "RentalManager.h"

RentalManager::RentalManager() 
{
	
}

std::vector<Rental> RentalManager::getRentals() 
{
	return this->rentals;
}

Rental RentalManager::getRentalByAccount(CustomerAccount customerAccount)
{
	for (Rental rental : this->rentals)
	{
		// Check if account name == the other account name
		/*if (rental.getCar() == car)
		{
			return rental;
		}*/
	}
}

Rental RentalManager::getRentalByCar(Car car) 
{
	for (Rental rental : this->rentals) 
	{
		// Check if carplate == the other car plate
		/*if (rental.getCar() == car)
		{
			return rental;
		}*/
	}
}

void RentalManager::addRental(Rental rental) 
{
	this->rentals.push_back(rental);
}

void RentalManager::cancelRental(Rental rental)
{
	this->rentals.erase(std::remove(this->rentals.begin(), this->rentals.end(), rental), this->rentals.end());
}