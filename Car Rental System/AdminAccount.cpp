#include "AdminAccount.h"


AdminAccount::AdminAccount(std::string username, std::string password, std::string name, std::string dateOfBirth, std::string address, std::string adminId, CarManager carManager)
: Account(username, password, name, dateOfBirth, address)
{
	this->adminId = adminId;
	this->carManager = carManager;
}

std::string AdminAccount::getAdminId() {
	return adminId;
}


void AdminAccount::addCar(Car myCar) {
	carManager.addCar(myCar);
}

void AdminAccount::removeCar(Car myCar) {
	carManager.removeCar(myCar);
}

/*
void AdminAccount::editCar(Car myCar) {

}
*/


void AdminAccount::displayCars() {
	carManager.displayCars();
}





