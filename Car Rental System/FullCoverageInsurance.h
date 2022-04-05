#pragma once

#include "TheftInsurance.h"
#include "CollisionInsurance.h"
#include "InjuryInsurance.h"

class FullCoverageInsurance : public CollisionInsurance, public TheftInsurance, public InjuryInsurance
{
private:
	double payableAmount;
public:
	virtual ~FullCoverageInsurance() = default;
	double getPayableAmount();
	void setPayableAmount(int);
};

