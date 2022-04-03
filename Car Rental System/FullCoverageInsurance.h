#pragma once

#include "TheftInsurance.h"
#include "CollisionInsurance.h"
#include "InjuryInsurance.h"
#include "CustomerAccount.h"

class Account;

class FullCoverageInsurance : public CollisionInsurance, public TheftInsurance, public InjuryInsurance
{
private:
	double payableAmount;
public:
	FullCoverageInsurance(CustomerAccount, int, std::string);
	double getPayableAmount();
	void setPayableAmount(int);
};

