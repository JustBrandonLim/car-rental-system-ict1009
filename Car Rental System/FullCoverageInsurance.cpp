#include "FullCoverageInsurance.h"

FullCoverageInsurance::FullCoverageInsurance(Account owner, double payableAmount, std::string description) : CollisionInsurance(owner, payableAmount, description),
TheftInsurance(owner, payableAmount, description), InjuryInsurance(owner, payableAmount, description), Insurance(owner, payableAmount, description)
{
	
}