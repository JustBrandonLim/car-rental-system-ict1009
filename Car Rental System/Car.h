#pragma once

#include <string>
#include <iostream>

using namespace std;

enum class CarStatus
{
	Available = 0,
	Reserved = 1
};

class Car
{
private:
	string carPlate;
	string model;
	string transmission;
	double rentalRate;
	bool available;
public:
	Car(string carPlate, string model, string transmission, double rentalRate, bool available);
	string getCarPlate();
	string getModel();
	string getTransmission();
	double getRentalRate();
	bool getAvailable();
	void displayCar();
};

