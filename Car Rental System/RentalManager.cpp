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

	/*
	for (Rental rental : this->rentals)
	{
		/*if (rental.getCar() == car)
		{
			return rental;
		}


	}
	*/
	return this->rentals[0];
}

Rental RentalManager::getRentalByCar(Car car)
{
	/*
	for (Rental rental : this->rentals)
	{
		/*if (rental.getCar() == car)
		{
			return rental;
		}


	}
	*/
	return this->rentals[0];
}

void RentalManager::addRental(Rental rental)
{
	this->rentals.push_back(rental);
}

void RentalManager::cancelRental(Rental rental)
{
	//this->rentals.erase(std::remove(this->rentals.begin(), this->rentals.end(), rental), this->rentals.end());
}
