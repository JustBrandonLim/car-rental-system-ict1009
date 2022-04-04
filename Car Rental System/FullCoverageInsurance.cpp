#include "FullCoverageInsurance.h"
#include <iostream>

FullCoverageInsurance::FullCoverageInsurance() : CollisionInsurance(), TheftInsurance(), InjuryInsurance(), Insurance() 
{
	setPayableAmount(0);
}

FullCoverageInsurance::FullCoverageInsurance(CustomerAccount owner, int duration, std::string description) : CollisionInsurance(owner, duration, description),
TheftInsurance(owner, duration, description), InjuryInsurance(owner, duration, description), Insurance(owner, duration, description)
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