#ifndef CARMANAGER_H_
#define CARMANAGER_H_

#pragma once

#include <iostream>
#include <vector>

#include "Car.h"

class CarManager
{
private:
	std::vector<Car> cars;
	static CarManager* instance;
	CarManager();
	CarManager(const CarManager&);
	CarManager& operator=(const CarManager&);
public:
	static CarManager* getInstance();
	void addCar(Car);
	void removeCar(Car);
	void displayCars();
};

#endif