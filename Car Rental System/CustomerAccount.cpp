#include "CustomerAccount.h"

CustomerAccount::CustomerAccount() {}

CustomerAccount::CustomerAccount(CarManager* carManager, std::string username, std::string password, std::string name, std::string dateOfBirth, std::string address)
{
    this->carManager = carManager;
	this->username = username;
	this->password = password;
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
}

void CustomerAccount::doCustomer()
{
    bool logOut = false;
    while (!logOut)
    {
        system("title Car Rental System - Customer");
        std::cout << "=== Car Rental System ===" << std::endl;
        std::cout << "1. Rent Car" << std::endl;
        std::cout << "2. Cancel Rental" << std::endl;
        std::cout << "3. Buy Insurance" << std::endl;
        std::cout << "4. Log Out" << std::endl;
        std::cout << "Select an option: ";

        int adminMenuOption = 0;

        std::cin >> adminMenuOption;

        switch (adminMenuOption)
        {
        default:
            exit(0);
            break;
        case 1:
            this->carManager->displayCars();
            break;
        case 2:

            break;
        case 3:
            
            break;
        case 4:
            logOut = true;
            system("cls");
            break;
        }
    }
}