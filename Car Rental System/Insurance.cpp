#include "Insurance.h"
#include <iostream>

int Insurance::getDuration() {
	return this->duration;
}

std::string Insurance::getDescription() 
{
	return this->description;
}

int Insurance::getPaymentStatus() {
	return this->paymentStatus;
}

void Insurance::setDuration(int duration) {
	this->duration = duration;
}

void Insurance::setDescription(std::string description)
{
	this->description = description;
}

void Insurance::setPaymentStatus(int status) {
	this->paymentStatus = status;
}