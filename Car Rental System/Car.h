#pragma once

#include <string>

class Car
{
private:
	std::string model;
	std::string plateNumber;
	double hourlyRate;
	bool servicing;
public:
	Car();
	Car(std::string, std::string, double, bool);
	std::string getPlateNumber();
};

