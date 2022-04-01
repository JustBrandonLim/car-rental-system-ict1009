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

	carDamagesFile << user << " " << carDamages << endl;

	carDamagesFile.close();
}
