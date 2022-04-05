#include "RentalManager.h"

RentalManager::RentalManager() {}

RentalManager* RentalManager::instance = NULL;

RentalManager* RentalManager::getInstance()
{
	if (!RentalManager::instance)
	{
		RentalManager::instance = new RentalManager();
	}

	return RentalManager::instance;
}

void RentalManager::addRental(Rental rental)
{
	this->rentals.push_back(rental);
}

void RentalManager::removeRental(Rental rental)
{
	//cars.erase(std::remove(cars.begin(), cars.end(), car), cars.end());
}

void RentalManager::displayRentals() {
	for (Rental rental : this->rentals) {
		//std::cout << rental.getCustomerAccount().getName() << std::endl;;
	}
}