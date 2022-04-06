#include "Car.h"

Car::Car(std::string model, std::string plateNumber, std::string transmissionType, double hourlyRate, bool available = true)
{
	this->model = model;
	this->plateNumber = plateNumber;
	this->transmissionType = transmissionType;
	this->dailyRate = hourlyRate;
	this->available = available;
}

std::string Car::getModel()
{
	return this->model;
}

std::string Car::getPlateNumber() 
{
	return this->plateNumber;
}

std::string Car::getTransmissionType() 
{
	return this->transmissionType;
}

double Car::getDailyRate()
{
	return this->dailyRate;
}

bool Car::getAvailable() 
{
	return this->available;
}

void Car::reserveCar()
{
	this->available = false;
}

void Car::unreserveCar()
{
	this->available = true;
}

bool Car::operator>(Car car1) {
	return (this->dailyRate > car1.getDailyRate());
}

bool Car::operator<(Car car1) {
	return (this->dailyRate < car1.getDailyRate());
}
