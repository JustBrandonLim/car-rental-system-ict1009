#pragma once

#include "TheftInsurance.h"
#include "CollisionInsurance.h"
#include "InjuryInsurance.h"
#include "Account.h"

class Account;

class FullCoverageInsurance : public CollisionInsurance, public TheftInsurance, public InjuryInsurance
{
public:
	FullCoverageInsurance(Account, double, std::string);
};

