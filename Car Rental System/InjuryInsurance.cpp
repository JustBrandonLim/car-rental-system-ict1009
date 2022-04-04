#include <iostream>
#include <fstream>
#include "InjuryInsurance.h"

InjuryInsurance::InjuryInsurance() : Insurance() {
	setPayableAmount(0);
}

InjuryInsurance::InjuryInsurance(int duration, std::string description) : Insurance(duration, description)
{
	setPayableAmount(duration);
}

InjuryInsurance::~InjuryInsurance() {
	cout << "Injury Insurance deleted" << endl;
}

double InjuryInsurance::getPayableAmount() {
	return this->payableAmount;
}

void InjuryInsurance::setPayableAmount(int duration) {
	this->payableAmount = duration * 20.00;
}

void InjuryInsurance::submitInjuries(std::string username)
{
	std::string injuries;

	std::cin >> injuries;

	std::ofstream injuriesFile;
	
	injuriesFile.open("injuries.txt", ios::out | ios::app);
	
	injuriesFile << username << endl << injuries << endl;

	injuriesFile.close();
}

void InjuryInsurance::showInjuries(std::string username)
{
	std::string injuries, fileUser;

	std::ifstream injuriesFile;

	injuriesFile.open("injuries.txt");

	if (injuriesFile) {
		while (getline(injuriesFile, fileUser)) {
			if (fileUser == username) {
				getline(injuriesFile, injuries);
				cout << injuries << endl;
			}
		}
	}

	injuriesFile.close();
}