#include "Car.h"

Car::Car() {}

Car::Car(std::string model, std::string plateNumber, double hourlyRate, bool servicing = false)
{
	this->model = model;
	this->plateNumber = plateNumber;
	this->hourlyRate = hourlyRate;
	this->servicing = servicing;
}

std::string Car::getPlateNumber() 
{
	return this->plateNumber;
}