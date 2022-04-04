#pragma once

#include "TheftInsurance.h"
#include "CollisionInsurance.h"
#include "InjuryInsurance.h"

class FullCoverageInsurance : public CollisionInsurance, public TheftInsurance, public InjuryInsurance
{
private:
	double payableAmount;
public:
	FullCoverageInsurance();
	FullCoverageInsurance(int, std::string);
	~FullCoverageInsurance();
	double getPayableAmount();
	void setPayableAmount(int);
};

