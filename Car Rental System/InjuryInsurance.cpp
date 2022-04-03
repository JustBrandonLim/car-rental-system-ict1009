#include <iostream>
#include <fstream>
#include "InjuryInsurance.h"

InjuryInsurance::InjuryInsurance(CustomerAccount owner, int duration, std::string description) : Insurance(owner, duration, description)
{
	setPayableAmount(duration);
}

double InjuryInsurance::getPayableAmount() {
	return this->payableAmount;
}

void InjuryInsurance::setPayableAmount(int duration) {
	this->payableAmount = duration * 20.00;
}

void InjuryInsurance::submitInjuries()
{
	std::string injuries, user;

	user = this->Insurance::getInsuranceOwner().Account::getUsername();

	std::cin >> injuries;

	std::ofstream injuriesFile;
	
	injuriesFile.open("injuries.txt", ios::out | ios::app);
	
	injuriesFile << user << endl << injuries << endl;

	injuriesFile.close();
}

void InjuryInsurance::showInjuries()
{
	std::string injuries, user, fileUser;

	user = this->Insurance::getInsuranceOwner().Account::getUsername();

	std::ifstream injuriesFile;

	injuriesFile.open("injuries.txt");

	if (injuriesFile) {
		while (getline(injuriesFile, fileUser)) {
			if (fileUser == user) {
				getline(injuriesFile, injuries);
				cout << injuries << endl;
			}
		}
	}

	injuriesFile.close();
}