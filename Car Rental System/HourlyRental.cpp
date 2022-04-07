#include "HourlyRental.h"

HourlyRental::HourlyRental(Account* account, Car* car, double hourlyRate, int hours, int rentalType) : Rental(account, car)
{
	this->hourlyRate = hourlyRate;
	this->hours = hours;
	this->rentalType = rentalType;
}

double HourlyRental::calculateTotalFees()
{
	return this->hourlyRate * this->hours;
}

void HourlyRental::displayRental()
{
	cout << "Account: " << this->account->getUsername() << endl;
	cout << "Car: " << this->car->getCarPlate() << endl;
	cout << "Hourly Rate: $" << this->hourlyRate << endl;
	cout << "Hours: " << this->hours << endl;
}

ostream& operator<<(ostream& out, HourlyRental& hourlyRental) {
	out << "\t" << "Hourly\t\t" << hourlyRental.getCar()->getCarPlate() << "\t\t" << hourlyRental.getCar()->getTransmission() << "\t\t" << hourlyRental.getCar()->getModel() << "\t$" << hourlyRental.calculateTotalFees() << endl;
	return out;
}