#include "FullCoverageInsurance.h"

FullCoverageInsurance::FullCoverageInsurance(CustomerAccount owner, int duration, std::string description) : CollisionInsurance(owner, duration, description),
TheftInsurance(owner, duration, description), InjuryInsurance(owner, duration, description), Insurance(owner, duration, description)
{
	setPayableAmount(duration);
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