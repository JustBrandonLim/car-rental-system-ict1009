#include "Rental.h"

Rental::Rental(Account account, string startDate, string endDate)
{
	this->rentedBy = account;
	this->startDate = startDate;
	this->endDate = endDate;
}

Account Rental::getRentedBy()
{
	return this->rentedBy;
}

string Rental::getStartDate()
{
	return this->startDate;
}

string Rental::getEndDate()
{
	return this->endDate;
}
