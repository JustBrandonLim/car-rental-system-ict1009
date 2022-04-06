#include "CarManager.h"

CarManager::CarManager()
{

}

void CarManager::loadCars()
{
	ifstream cars("cars.txt");

	string carInformation;

	while (getline(cars, carInformation))
	{
		vector<string> carInformations;
		string tempInformation = "";
		for (int index = 0; index < carInformation.length(); index++)
		{

			if (carInformation[index] == ':')
			{
				carInformations.push_back(tempInformation);
				tempInformation = "";
			}
			else
				tempInformation.push_back(carInformation[index]);

		}
		
		this->cars.push_back(new Car(carInformations[0], carInformations[1], carInformations[2], stod(carInformations[3]), carInformations[4] == "T" ? true : false));
	}

	cars.close();
}

vector<Car*> CarManager::getCars()
{
	return this->cars;
}

Car* CarManager::getCarByIndex(int id)
{
	return id >= this->cars.size() ? NULL : this->cars[id];
}

Car* CarManager::getCarByCarPlate(string carPlate)
{
	for (Car* car : this->cars)
	{
		if (carPlate == car->getCarPlate())
			return car;
	}
	
	return NULL;
}

void CarManager::addCar(string carPlate, string model, string transmission, double rentalRate, bool available)
{
	ofstream cars("cars.txt", ofstream::app);

	cars << carPlate << ":" << model << ":" << transmission << ":" << rentalRate << ":" << (available == true ? "T" : "F") << ":" << endl;

	cars.close();

	//Car newCar(carPlate, model, transmission, rentalRate, available);

	this->cars.push_back(new Car(carPlate, model, transmission, rentalRate, available));
}

void CarManager::removeCarByIndex(int id)
{
	Car* car = this->getCarByIndex(id);

	delete car;

	this->cars.erase(this->cars.begin() + id);

	ofstream cars("cars.txt", ofstream::out | ofstream::trunc);

	for (Car* car : this->cars)
		cars << car->getCarPlate() << ":" << car->getModel() << ":" << car->getTransmission() << ":" << car->getRentalRate() << ":" << (car->getAvailable() == true ? "T" : "F") << ":" << endl;

	cars.close();
}

void CarManager::displayCars() 
{
	cout << "ID\tCar Plate\tModel\t\tTransmission\tRental Rate\tAvailable" << endl;
	for (int index = 0; index < this->cars.size(); index++)
		cout << index << *this->cars[index];
		//cout << index << "\t" << this->cars[index].getCarPlate() << "\t\t" << this->cars[index].getModel() << "\t" << this->cars[index].getTransmission() << "\t\t" << this->cars[index].getRentalRate() << "\t\t" << (this->cars[index].getAvailable() ? "Yes" : "No") << endl;
}
