#include "RentalManager.h"

RentalManager::RentalManager()
{

}

void RentalManager::loadRentals()
{
	
}

Rental* RentalManager::getRentalByIndex(int id)
{
	return id >= this->rentals.size() ? NULL : this->rentals[id];
}

Rental* RentalManager::getRentalByCarPlate(string carPlate)
{
	for (Rental* rental : this->rentals)
	{
		if (carPlate == rental->getCar()->getCarPlate())
			return rental;
	}

	return NULL;
}

void RentalManager::addHourlyRental(Account* account, Car* car, double hourlyRate, int hours)
{
	car->setAvailable(false);

	HourlyRental* hourlyRental = new HourlyRental(account, car, hourlyRate, hours);

	Rental* rental = hourlyRental;

	this->rentals.push_back(rental);
}

void RentalManager::addDailyRental(Account* account, Car* car, double dailyRate, int days)
{
	car->setAvailable(false);

	DailyRental* dailyRental = new DailyRental(account, car, dailyRate, days);

	Rental* rental = dailyRental;

	this->rentals.push_back(rental);
}

void RentalManager::cancelRentalByIndex(int id)
{
	Rental* rental = this->getRentalByIndex(id);

	rental->getCar()->setAvailable(true);

	delete rental;

	this->rentals.erase(this->rentals.begin() + id);
}

void RentalManager::displayRentalsByAccountUsername(string username)
{
	cout << "ID\tRental Type\tCar Plate\tTransmission\tCar Model\tTotal Fees" << endl;
	for (int index = 0; index < this->rentals.size(); index++)
	{
		if (username == this->rentals[index]->getAccount()->getUsername())
		{
			if (this->rentals[index]->getRentalType() == 0)
			{
				HourlyRental* hourlyRental = dynamic_cast<HourlyRental*>(this->rentals[index]);
				cout << index << *hourlyRental;
			}
			else if (this->rentals[index]->getRentalType() == 1)
			{
				DailyRental* dailyRental = dynamic_cast<DailyRental*>(this->rentals[index]);
				cout << index << *dailyRental;
			}
		}
	}
}