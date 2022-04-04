#include <iostream>
#include "Menu.h"
#include "Car.h"

using namespace std;

template<typename T>
T compare(T car1, T car2, int hours) {
	if (car1 > car2) {
		cout << "Difference: $" << (car1.getHourRate() - car2.getHourRate()) * hours << endl;
		return car2;
	}
	else {
		cout << "Difference: $" << (car2.getHourRate() - car1.getHourRate()) * hours << endl;
		return car1;
	}
}

int main()
{
	system("title Car Rental System");

	int menuDisplay = 0;

	bool exitProgram = false;

	int optionSelected = -1;
	Menu menu;

	menu.printMenu();
	/*
	do 
	{
		switch (menuDisplay) {
		// Main Menu
		case 0:
			cout << "========== Car Rental System ==========" << endl;
			cout << "1. Register" << endl;
			cout << "2. Login" << endl;
			cout << "3. Exit" << endl;
			cout << "Select an option: ";
			cin >> optionSelected;

			switch (optionSelected) 
			{
				
			case 1:
				system("cls");
				menuDisplay = 1;
				break;
			default:
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "* You have selected an invalid option! Please try again!" << endl << endl;
				break;
			}
			break;

		// Registration Menu
		case 1:
			cout << "========== Registration ==========" << endl;
			break;

		// Login Menu
		case 2:
			cout << "========== Login ==========" << endl;
			break;

		// Rental Menu
		case 3:
			cout << "========== Rental ==========" << endl;
			break;
		}
	} while (!exitProgram);

	bool exit = false;
	while (!exit)
	{
		bool validOption = false;
		cout << "========== Car Rental System ==========" << endl;
		cout << "1. Register" << endl;
		cout << "2. Login" << endl;
		cout << "3. Exit" << endl;
		cout << "Select an option: ";

		int optionSelected = -1;

		if (cin >> optionSelected)
			validOption = true;
		else
		{
			cin.clear();
			cin.ignore();
			system("cls");
			cout << "* You have selected an invalid option! Please try again!" << endl << endl;
		}

		if (validOption) {
			system("cls");

			switch (optionSelected) {
			default:
				cout << "* You have selected an invalid option! Please try again!" << endl << endl;
				validOption = false;
				break;
			case 1:
				cout << "========== Registration ==========" << endl;
				cout << "Please enter your username: ";
				string username, password;
				cin >> username;
				cout << "Please enter your password: ";
				cin >> password;
				cout << username << password << endl;

				system("cls");
				break;
			}

		}
	}*/

	return 0;
}
