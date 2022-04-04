#include "FullCoverageInsurance.h"
#include <iostream>

FullCoverageInsurance::FullCoverageInsurance() : CollisionInsurance(), TheftInsurance(), InjuryInsurance(), Insurance() 
{
	setPayableAmount(0);
}

FullCoverageInsurance::FullCoverageInsurance(int duration, std::string description) : CollisionInsurance(duration, description),
TheftInsurance(duration, description), InjuryInsurance(duration, description), Insurance(duration, description)
{
	setPayableAmount(duration);
}

FullCoverageInsurance::~FullCoverageInsurance() {
	cout << "Full Coverage Insurance deleted" << endl;
}

double FullCoverageInsurance::getPayableAmount() {
	return this->payableAmount;
}

void FullCoverageInsurance::setPayableAmount(int duration) {
	this->CollisionInsurance::setPayableAmount(duration);
	this->TheftInsurance::setPayableAmount(duration);
	this->InjuryInsurance::setPayableAmount(duration);
	this->payableAmount = this->CollisionInsurance::getPayableAmount() + this->TheftInsurance::getPayableAmount() + this->InjuryInsurance::getPayableAmount();
}