#include "Rental.h"

Rental::Rental()
{

}

Rental::Rental(CustomerAccount customerAccount, Car car, DateTime startDateTime, DateTime endDateTime)
{
	this->customerAccount = customerAccount;
	this->car = car;
	this->startDateTime = startDateTime;
	this->endDateTime = endDateTime;
}

CustomerAccount Rental::getCustomerAccount()
{
	return this->customerAccount;
}

Car Rental::getCar()
{
	return this->car;
}

DateTime Rental::getStartDateTime()
{
	return this->startDateTime;
}

DateTime Rental::getEndDateTime()
{
	return this->endDateTime;
}

double Rental::getTotalFees()
{
	double carHourlyRate = 2.0;
	double insuranceHourlyRate = 1.5;

	return (this->endDateTime.hour - this->startDateTime.hour) * carHourlyRate * insuranceHourlyRate;
}