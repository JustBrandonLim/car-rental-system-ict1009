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

        switch (adminMenuOption)
        {
        default:
            exit(0);
            break;
        case 1:
        {
            std::string model, plateNumber, transmissionType;
            double dailyRate;
            std::cout << "Please enter the model: ";
            std::cin >> model;
            std::cout << "Please enter the plate number: ";
            std::cin >> plateNumber;
            std::cout << "Please enter the transmission type (Auto/Manual): ";
            std::cin >> transmissionType;
            std::cout << "Please enter the daily rate: ";
            std::cin >> dailyRate;
            this->carManager->addCar(Car(model, plateNumber, transmissionType, dailyRate, false));
            std::cout << "Car has been added." << std::endl;
        }
            break;
        case 2:
        {
            this->carManager->displayCars();
            int index = -1;
            std::cout << "Please select a car to remove: " << std::endl;
            std::cin >> index;
            this->carManager->removeCar(index);
            std::cout << "Car has been removed." << std::endl;
        }
            break;
        case 3:
            logOut = true;
            system("cls");
            break;
        }
	}
}
