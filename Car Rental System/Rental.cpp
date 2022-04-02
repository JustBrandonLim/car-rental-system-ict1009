#include "Rental.h"

Rental::Rental(int hours, double totalPayable)
{
	this->hours = hours;
	this->totalPayable = totalPayable;
}

int Rental::getHours() {
	return hours;
}

void Rental::selectHours(int hours) {
	this->hours = hours;
}

double Rental::getTotalPayable() {
	return totalPayable;
}
