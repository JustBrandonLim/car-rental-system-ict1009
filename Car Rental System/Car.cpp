#include "Car.h"

Car::Car(string carPlate, string model, string transmission, double rentalRate, bool available)
{
	this->carPlate = carPlate;
	this->model = model;
	this->transmission = transmission;
	this->rentalRate = rentalRate;
	this->available = available;
}

string Car::getCarPlate()
{
	return this->carPlate;
}

string Car::getModel()
{
	return this->model;
}

string Car::getTransmission()
{
	return this->transmission;
}

double Car::getRentalRate()
{
	return this->rentalRate;
}

bool Car::getAvailable()
{
	return this->available;
}

void Car::displayCar()
{
	cout << "Car Plate: " << this->carPlate << endl;
	cout << "Model: " << this->model << endl;
	cout << "Transmission: " << this->transmission << endl;
	cout << "Rental Rate: " << this->rentalRate << endl;
	cout << "Available: " << (this->available ? "Yes" : "No") << endl;
}