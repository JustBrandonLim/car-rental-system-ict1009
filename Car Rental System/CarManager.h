#pragma once

#include <vector>
#include "Car.h"

class CarManager
{
private:
	static CarManager* s_instance;
	std::vector<Car> cars;
	CarManager(){};
public:
	static CarManager* getInstance(){
		if(!s_instance)
			s_instance = new CarManager;
		return s_instance;
	std::vector<Car> getCars();
	void addCar(Car);
	void removeCar(Car);
	Car getCarByModel(std::string);
	void displayCars();
};
