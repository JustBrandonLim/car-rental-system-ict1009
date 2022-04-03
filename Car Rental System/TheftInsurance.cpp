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

	stolenItemsFile << user << " " << stolenItems << endl;

	stolenItemsFile.close();
}
