#include "AdminAccount.h"

AdminAccount::AdminAccount(CarManager* carManager, string username, string password, string name, string dateOfBirth, string address, bool admin) : Account(username, password, name, dateOfBirth, address, admin)
{
	this->carManager = carManager;
}

bool AdminAccount::addCar(string carPlate, string model, string transmission, double rentalRate, bool available)
{
	if (this->carManager->getCarByCarPlate(carPlate) != NULL)
	{
		this->carManager->addCar(carPlate, model, transmission, rentalRate, available);
		return true;
	}
		
	return false;
}

bool AdminAccount::removeCar(int id)
{
	if (this->carManager->getCarByIndex(id) != NULL)
	{
		this->carManager->removeCarByIndex(id);
		return true;
	}

	return false;
}


