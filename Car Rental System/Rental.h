#pragma once

#include <string>

using namespace std;

#include "Account.h"

class Account;

class Rental
{
private:
	int hours;
	double totalPayable;

public:
	Rental();
	Rental(int, double);
	int getHours();
	void selectHours(int);
	double getTotalPayable();
};
