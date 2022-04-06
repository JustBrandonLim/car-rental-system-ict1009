#include "Rental.h"

Rental::Rental(Account* account, Car* car)
{
	this->account = account;
	this->car = car;
}

Rental::~Rental()
{
	cout << "Reservation by " << this->account->getUsername() << " of car " << this->car->getCarPlate() << " has been cancelled." << endl;
}

Account* Rental::getAccount()
{
	return this->account;
}

Car* Rental::getCar()
{
	return this->car;
}

int Rental::getRentalType()
{
	return this->rentalType;
}

void Rental::displayRental()
{
	cout << "Account: " << this->account->getUsername() << endl;
	cout << "Car: " << this->car->getCarPlate() << endl;
}