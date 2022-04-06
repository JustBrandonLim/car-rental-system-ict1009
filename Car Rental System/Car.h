#pragma once

#include <string>
#include <iostream>

using namespace std;

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
	~Car();
	string getCarPlate();
	string getModel();
	string getTransmission();
	double getRentalRate();
	bool getAvailable();
	void displayCar();
	friend ostream& operator<<(ostream& cout, Car& car);
};

