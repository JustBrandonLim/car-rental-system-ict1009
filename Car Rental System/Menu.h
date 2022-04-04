#pragma once

#include <iostream>

using namespace std;

class Menu
{
private:
	bool exitProgram = false;
public:
	void printMenu();
	void adminMenu();
	void customerRentalMenu();
};

