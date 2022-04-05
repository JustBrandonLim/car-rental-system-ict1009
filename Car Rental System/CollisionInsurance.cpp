#include "CollisionInsurance.h"

#include <iostream>
#include <fstream>

double CollisionInsurance::getPayableAmount() {
	return this->payableAmount;
}

void CollisionInsurance::setPayableAmount(int duration) {
	this->payableAmount = duration * 10.00;
}


void CollisionInsurance::submitCarDamages(std::string username, std::string damages)
{
	std::ofstream carDamagesFile;

	carDamagesFile.open("carDamages.txt", ios::out | ios::app);

	
	carDamagesFile << username << endl << damages << endl;

	carDamagesFile.close();
}

void CollisionInsurance::showCarDamages(std::string username)
{
	std::string carDamages, fileUser;

	std::ifstream carDamagesFile;

	carDamagesFile.open("carDamages.txt");

	if (carDamagesFile) {
		while (getline(carDamagesFile, fileUser)) {
			if (fileUser == username) {
				getline(carDamagesFile, carDamages);
				cout << carDamages << endl;
			}
		}
	}

	carDamagesFile.close();
}