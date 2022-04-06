#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

#include "Car.h"

class CarManager
{
private:
	vector<Car> cars;
public:
	CarManager();
	void loadCars();
	vector<Car> getCars();
	Car* getCarByIndex(int id);
	Car* getCarByCarPlate(string carPlate);
	void addCar(string carPlate, string model, string transmission, double rentalRate, bool available);
	void removeCarByIndex(int id);
	void displayCars();
};

