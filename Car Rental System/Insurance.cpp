#include "Insurance.h"
#include <iostream>

Insurance::Insurance() {
	this->duration = 0;
	this->description = "Empty insurance.";
}

Insurance::~Insurance() {
	cout << "Insurance deleted." << endl;
}

Insurance::Insurance(int duration, std::string description) {
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
