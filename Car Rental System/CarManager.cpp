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

Car* CarManager::getCarByIndex(int index)
{
	return &this->cars[index];
}

void CarManager::addCar(Car car) 
{
	this->cars.push_back(car);
}

void CarManager::removeCar(int index) 
{
	this->cars.erase(this->cars.begin() + index);
}

void CarManager::displayCars() {

	std::cout << "ID\tModel\t\tPlate Number\tTransmission\tDaily Rate\tAvailable" << std::endl;
	for (int index = 0; index < this->cars.size(); index++)
	{
		Car currentCar = this->cars[index];
		std::cout << index << "\t" << currentCar.getModel() << "\t" << currentCar.getPlateNumber() << "\t" << currentCar.getTransmissionType()  << "\t\t" << currentCar.getDailyRate() << "\t\t" << (currentCar.getAvailable() == true ? "Yes" : "No") << std::endl;
	}
}