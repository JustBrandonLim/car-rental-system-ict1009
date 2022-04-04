#include "TheftInsurance.h"

#include <iostream>
#include <fstream>

TheftInsurance::TheftInsurance() : Insurance()
{
	setPayableAmount(0);
}

TheftInsurance::TheftInsurance(CustomerAccount owner, int duration, std::string description) : Insurance(owner, duration, description)
{
	setPayableAmount(duration);
}

TheftInsurance::~TheftInsurance() {
	cout << "Theft Insurance deleted" << endl;
}

double TheftInsurance::getPayableAmount() {
	return this->payableAmount;
}

void TheftInsurance::setPayableAmount(int duration) {
	this->payableAmount = duration * 15.00;
}

void TheftInsurance::submitStolenItems()
{
	std::string stolenItems, user;

	user = this->Insurance::getInsuranceOwner().Account::getUsername();

	std::cin >> stolenItems;

	std::ofstream stolenItemsFile;

	stolenItemsFile.open("stolenItems.txt", ios::out | ios::app);

	stolenItemsFile << user << endl << stolenItems << endl;

	stolenItemsFile.close();
}

void TheftInsurance::showStolenItems()
{
	std::string stolenItems, user, fileUser;

	user = this->Insurance::getInsuranceOwner().Account::getUsername();

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