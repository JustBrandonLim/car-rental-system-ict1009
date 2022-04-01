#pragma once

#include <string>

using namespace std;

#include "Account.h"

class Account;

class Rental
{
private:
	Account rentedBy;
	string startDate;
	string endDate;
public:
	Rental();
	Rental(Account, string, string);
	Account getRentedBy();
	string getStartDate();
	string getEndDate();
};

