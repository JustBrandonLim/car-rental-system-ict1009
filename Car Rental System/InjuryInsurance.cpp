#include <iostream>
#include <fstream>
#include "InjuryInsurance.h"

InjuryInsurance::InjuryInsurance(Account owner, double payableAmount, std::string description) : Insurance(owner, payableAmount, description)
{
	
}

void InjuryInsurance::submitInjuries()
{
	std::string injuries, user;

	user = this->Insurance::getInsuranceOwner().getUsername();

	std::cin >> injuries;

	std::ofstream injuriesFile;
	
	injuriesFile.open("injuries.txt", ios::out | ios::app);
	
	injuriesFile << user << endl << injuries << endl;

	injuriesFile.close();
}

void InjuryInsurance::showInjuries()
{
	std::string injuries, user, fileUser;

	user = this->Insurance::getInsuranceOwner().getUsername();

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