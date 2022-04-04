#include "AdminAccount.h"

AdminAccount::AdminAccount() {}

AdminAccount::AdminAccount(CarManager* carManager, std::string username, std::string password, std::string name, std::string dateOfBirth, std::string address)
{
    this->carManager = carManager;
	this->username = username;
	this->password = password;
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
}

void AdminAccount::doAdmin() 
{
	bool logOut = false;
	while (!logOut)
	{
        system("title Car Rental System - Admin");
        std::cout << "=== Car Rental System ===" << std::endl;
        std::cout << "1. Add Car" << std::endl;
        std::cout << "2. Remove Car" << std::endl;
        std::cout << "3. Log Out" << std::endl;
        std::cout << "Select an option: ";

        int adminMenuOption = 0;

        std::cin >> adminMenuOption;
        std::cout << adminMenuOption;
        switch (adminMenuOption)
        {
        default:
            exit(0);
            break;
        case 1:
            this->carManager->addCar(Car("merc", "SKT369", 2.5, true));
            std::cout << "car added" << std::endl;
            break;
        case 2:
            break;
        case 3:
            logOut = true;
            system("cls");
            break;
        }
	}
}