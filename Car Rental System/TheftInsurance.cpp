#include "TheftInsurance.h"

#include <iostream>
#include <fstream>

TheftInsurance::TheftInsurance(Account owner, double payableAmount, std::string description) : Insurance(owner, payableAmount, description)
{

}

void TheftInsurance::submitStolenItems()
{
	std::string stolenItems, user;

	user = this->Insurance::getInsuranceOwner().getUsername();

	std::cin >> stolenItems;

	std::ofstream stolenItemsFile;

	stolenItemsFile.open("stolenItems.txt", ios::out | ios::app);

	stolenItemsFile << user << endl << stolenItems << endl;

	stolenItemsFile.close();
}

void TheftInsurance::showStolenItems()
{
	std::string stolenItems, user, fileUser;

	user = this->Insurance::getInsuranceOwner().getUsername();

	std::ifstream stolenItemsFile;

	stolenItemsFile.open("stolenItems.txt");

	if (stolenItemsFile) {
		while (getline(stolenItemsFile, fileUser)) {
			if (fileUser == user) {
				getline(stolenItemsFile, stolenItems);
				cout << stolenItems << endl;
			}
		}
	}

	stolenItemsFile.close();
}