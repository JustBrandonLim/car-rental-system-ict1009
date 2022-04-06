#include "RentalManager.h"

RentalManager::RentalManager()
{

}

void RentalManager::loadRentals()
{
	
}

void RentalManager::addHourlyRental(Account* account, Car* car, double hourlyRate, int hours)
{
	car->setAvailable(false);

	HourlyRental* hourlyRental = new HourlyRental(account, car, hourlyRate, hours, 0);

	Rental* rental = hourlyRental;

	this->rentals.push_back(rental);
}

void RentalManager::addDailyRental(Account* account, Car* car, double dailyRate, int days)
{
	car->setAvailable(false);

	DailyRental* dailyRental = new DailyRental(account, car, dailyRate, days, 1);

	Rental* rental = dailyRental;

	this->rentals.push_back(rental);
}

void RentalManager::displayRentalsByAccountUsername(string username)
{
	cout << "ID\tRental Type\tCar Plate\tCar Model\tTransmission\tTotal Fees" << endl;
	for (int index = 0; index < this->rentals.size(); index++)
	{
		if (username == this->rentals[index]->getAccount()->getUsername())
		{
			if (this->rentals[index]->getRentalType() == 0)
			{
				HourlyRental* hourlyRental = dynamic_cast<HourlyRental*>(this->rentals[index]);
				cout << index << *hourlyRental;
			}
			else
			{
				DailyRental* dailyRental = dynamic_cast<DailyRental*>(this->rentals[index]);
				cout << index << *dailyRental;
			}
		}
	}
}