#include "CollisionInsurance.h"

#include <iostream>
#include <fstream>

CollisionInsurance::CollisionInsurance(Account owner, double payableAmount, std::string description) : Insurance(owner, payableAmount, description)
{

}

void CollisionInsurance::submitCarDamages()
{
	std::string carDamages, user;

	user = this->Insurance::getInsuranceOwner().getUsername();

	std::cin >> carDamages;

	std::ofstream carDamagesFile;

	carDamagesFile.open("carDamages.txt", ios::out | ios::app);

	carDamagesFile << user << endl << carDamages << endl;

	carDamagesFile.close();
}

void CollisionInsurance::showCarDamages()
{
	std::string carDamages, user, fileUser;

	user = this->Insurance::getInsuranceOwner().getUsername();

	std::ifstream carDamagesFile;

	carDamagesFile.open("carDamages.txt");

	if (carDamagesFile) {
		while (getline(carDamagesFile, fileUser)) {
			if (fileUser == user) {
				getline(carDamagesFile, carDamages);
				cout << carDamages << endl;
			}
		}
	}

	carDamagesFile.close();
}