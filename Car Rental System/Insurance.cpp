#include "Insurance.h"

double Insurance::getPayableAmount()
{
	return this->payableAmount;
}

std::string Insurance::getDescription() 
{
	return this->description;
}

void Insurance::setPayableAmount(double payableAmount) 
{
	this->payableAmount = payableAmount;
}

void Insurance::setDescription(std::string description)
{
	this->description = description;
}