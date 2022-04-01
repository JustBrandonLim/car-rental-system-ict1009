#include "Insurance.h"
 
Insurance::Insurance(Account owner, double payableAmount, std::string description) {
	this->insuranceOwner = owner;
	this->payableAmount = payableAmount;
	this->description = description;
}

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

Account Insurance::getInsuranceOwner() {
	return this->insuranceOwner;
}