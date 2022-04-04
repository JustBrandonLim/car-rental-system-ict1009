#include "Menu.h"
#include <iostream>
#include<string>
#include "Login.h"
#include "Car.h"
Car car;
Login login;

void Menu::printMenu()
{
	int option;
	cout << "========== Car Rental System ==========" << endl;
	cout << "1. Register" << endl;
	cout << "2. Customer Login" << endl;
	cout << "3. Admin Login" << endl;
	cout << "4. Exit" << endl;
	cout << "Select an option: ";
	cin >> option;

	switch (option)
	{
	case 1:
		if (login.registerAccount())
		{
			cout << "Successfully registed an account" << endl;
			printMenu();
		}
		else
		{
			cout << "Invalid account creation" << endl;
		}
		break;

	case 2:

		if (login.isCustLogIn())
		{
			cout << "Welcome you have log on " << endl;
			do
			{
				customerRentalMenu();
			} while (!exitProgram);
			break;
		}
		else
		{
			cout << "Wrong username and pass" << endl;
			printMenu();
		}

		break;
	case 3:
		if (login.isAdminLogIn())
		{
			cout << "Welcome you have log on " << endl;
			do
			{
				adminMenu();
			} while (!exitProgram);
			break;
		}
		else
		{
			cout << "Wrong username and pass" << endl;
			printMenu();
		}
		break;
	case 4:
		exit(1);
		break;
	default:
		break;
	}
};
void Menu::adminMenu()
{
	int option;
	cout << "========== Admin Menu ==========" << endl;
	cout << "1. Add car" << endl;
	cout << "2. Delete car" << endl;
	cout << "3. " << endl;
	cout << "4. Exit" << endl;
	cout << "Select an option: ";
	cin >> option;

	switch (option)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		exit(1);
		break;
	default:
		break;
	}
}
void Menu::customerRentalMenu()
{
	int option;
	cout << "===================================================== " << endl;
	cout << "Rental" << endl;
	cout << "===================================================== " << endl;
	cout << " 1.Rent a car" << endl;
	cout << " 2.Cancel a rental" << endl;
	cout << " 3.Buy insurance" << endl;
	cout << " 4." << endl;
	cout << " 5.Exit" << endl;

	cin >> option;

	switch (option)
	{
	case 1:
		//rent car funtions
		cout << "rentcar here \n";

		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		exit(1);
		break;

	default:
		break;
	}
}