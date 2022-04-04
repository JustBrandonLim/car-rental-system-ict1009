#include "AdminAccount.h"


AdminAccount::AdminAccount(std::string username, std::string password, std::string name, std::string dateOfBirth, std::string address, CarManager* carManager)
: Account(username, password, name, dateOfBirth, address)
{
	this->carManager = carManager;
}

void AdminAccount::addCar(Car myCar) {
	carManager->addCar(myCar);
}

void AdminAccount::removeCar(Car myCar) {
	carManager->removeCar(myCar);
}

void AdminAccount::setServicing(Car myCar) {
	carManager->setServicing(myCar);
}

void AdminAccount::displayCars() {
	carManager>displayCars();
}





