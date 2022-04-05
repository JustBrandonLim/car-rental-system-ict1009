#include "Rental.h"

Rental::Rental() {}

Rental::Rental(CustomerAccount customerAccount, Car car)
{
	this->customerAccount = customerAccount;
	this->car = car;
}

CustomerAccount Rental::getCustomerAccount() 
{
	return this->customerAccount;
}

Car Rental::getCar() 
{
	return this->car;
}