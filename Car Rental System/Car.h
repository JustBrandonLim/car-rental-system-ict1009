#pragma once

#include <string>

class Car
{
private:
	std::string model;
	std::string plateNumber;
	std::string transmissionType;
	double dailyRate;
	bool available;
public:
	Car(std::string, std::string, std::string, double, bool);
	std::string getModel();
	std::string getPlateNumber();
	std::string getTransmissionType();
	double getDailyRate();
	bool getAvailable();
	void reserveCar();
	void unreserveCar();
	bool operator >(Car);
};

