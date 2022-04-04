#include "CarManager.h"

CarManager::CarManager()
{

}

std::vector<Car> CarManager::getCars() {
	return cars;
}

void CarManager :: addCar(Car myCar) {
	cars.push_back(myCar);
}

void CarManager::removeCar(Car myCar) {
	cars.erase(std::remove(cars.begin(), cars.end(), myCar), cars.end());
	std::cout << myCar.getPlateNumber() << " Removed" << std::endl;
}

Car CarManager::getCarByModel(std::string model) {
	for (int i = 0; i < cars.size(); i++) {
		if (cars[i].getModel() == model)
		{
			return cars[i];
			break;
			}
	}
}

void CarManager::displayCars() {
	for (int i = 0; i < cars.size(); i++) {
		getCars().at(i).displayInfo();
	}
}
