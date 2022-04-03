#pragma once

#include <vector>
#include <algorithm>


#include "Car.h"


class CarManager
{
private:
	std::vector<Car> cars;
public:
	CarManager();
	std::vector<Car> getCars();
	void addCar(Car);
	void removeCar(Car);
	Car getCarByModel(std::string);
	void displayCars();
};