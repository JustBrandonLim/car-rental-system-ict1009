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
	
	injuriesFile << user << " " << injuries << endl;

	injuriesFile.close();
}
