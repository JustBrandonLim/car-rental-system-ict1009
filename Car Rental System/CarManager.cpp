#include "CarManager.h"

CarManager::CarManager() {}

CarManager* CarManager::instance = NULL;

CarManager* CarManager::getInstance() 
{
	if (!CarManager::instance) 
	{
		CarManager::instance = new CarManager();
	}

	return CarManager::instance;
}

void CarManager::addCar(Car car) 
{
	this->cars.push_back(car);
}

void CarManager::removeCar(Car car) 
{
	//cars.erase(std::remove(cars.begin(), cars.end(), car), cars.end());
}

void CarManager::displayCars() {
	for (Car car : this->cars) {
		std::cout << car.getPlateNumber() << std::endl;;
	}
}