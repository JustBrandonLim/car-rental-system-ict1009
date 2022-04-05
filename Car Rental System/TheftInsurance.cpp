#include "TheftInsurance.h"

#include <iostream>
#include <fstream>

double TheftInsurance::getPayableAmount() {
	return this->payableAmount;
}

void TheftInsurance::setPayableAmount(int duration) {
	this->payableAmount = duration * 15.00;
}

void TheftInsurance::submitStolenItems(std::string username, std::string input)
{
	std::ofstream stolenItemsFile;

	stolenItemsFile.open("stolenItems.txt", ios::out | ios::app);

	stolenItemsFile << username << endl << input << endl;

	stolenItemsFile.close();
}

void TheftInsurance::showStolenItems(std::string username)
{
	std::string stolenItems, fileUser;

	std::ifstream stolenItemsFile;

	stolenItemsFile.open("stolenItems.txt");

	if (stolenItemsFile) {
		while (getline(stolenItemsFile, fileUser)) {
			if (fileUser == username) {
				getline(stolenItemsFile, stolenItems);
				cout << stolenItems << endl;
			}
		}
	}

	stolenItemsFile.close();
}