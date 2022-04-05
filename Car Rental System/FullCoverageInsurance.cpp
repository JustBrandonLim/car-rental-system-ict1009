#include "FullCoverageInsurance.h"
#include <iostream>

double FullCoverageInsurance::getPayableAmount() {
	return this->payableAmount;
}

void FullCoverageInsurance::setPayableAmount(int duration) {
	this->CollisionInsurance::setPayableAmount(duration);
	this->TheftInsurance::setPayableAmount(duration);
	this->InjuryInsurance::setPayableAmount(duration);
	this->payableAmount = this->CollisionInsurance::getPayableAmount() + this->TheftInsurance::getPayableAmount() + this->InjuryInsurance::getPayableAmount();
}