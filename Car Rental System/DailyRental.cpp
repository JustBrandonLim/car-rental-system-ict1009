#include "DailyRental.h"

DailyRental::DailyRental(Account* account, Car* car, double dailyRate, int days, int rentalType) : Rental(account, car)
{
	this->dailyRate = dailyRate;
	this->days = days;
	this->rentalType = rentalType;
}

double DailyRental::calculateTotalFees()
{
	return this->dailyRate * this->days;
}

void DailyRental::displayRental()
{
	cout << "Account: " << this->account->getUsername() << endl;
	cout << "Car: " << this->car->getCarPlate() << endl;
	cout << "Daily Rate: $" << this->dailyRate << endl;
	cout << "Days: " << this->days << endl;
}

ostream& operator<<(ostream& out, DailyRental& dailyRental) {
	out << "\t" << "Daily\t\t" << dailyRental.getCar()->getCarPlate() << "\t" << dailyRental.getCar()->getTransmission() << "\t\t" << dailyRental.getCar()->getModel() << "\t$" << dailyRental.calculateTotalFees() << endl;
	return out;
}