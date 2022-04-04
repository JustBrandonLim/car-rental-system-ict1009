#include "Insurance.h"
#include <iostream>

Insurance::Insurance() {
	CustomerAccount newAccount;
	this->insuranceOwner = newAccount;
	this->duration = 0;
	this->description = "Empty insurance.";
}

Insurance::~Insurance() {
	cout << "Insurance deleted." << endl;
}

Insurance::Insurance(CustomerAccount owner, int duration, std::string description) {
	this->insuranceOwner = owner;
	//this->payableAmount = payableAmount;
	this->duration = duration;
	this->description = description;
}

/*
double Insurance::getPayableAmount()
{
	return this->payableAmount;
}*/

int Insurance::getDuration() {
	return this->duration;
}

std::string Insurance::getDescription() 
{
	return this->description;
}

/*
void Insurance::setPayableAmount(double payableAmount) 
{
	this->payableAmount = payableAmount;
}*/

void Insurance::setDuration(int duration) {
	this->duration = duration;
}

void Insurance::setDescription(std::string description)
{
	this->description = description;
}

void Insurance::setInsuranceOwner(CustomerAccount insuranceOwner) {
	this->insuranceOwner = insuranceOwner;
}

CustomerAccount Insurance::getInsuranceOwner() {
	return this->insuranceOwner;
}