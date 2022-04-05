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
        std::cout << "1. Reserve Car" << std::endl;
        std::cout << "2. Unreserve Car" << std::endl;
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
        case 1: //Reserve Car
        {
            this->carManager->displayCars();
            int index = -1;
            std::cout << "Please select a car to reserve: ";
            std::cin >> index;
            Car* currentCar = this->carManager->getCarByIndex(index);
            if (currentCar->getAvailable())
            {
                currentCar->reserveCar();
                std::cout << "Car has been reserved." << std::endl;
            }
            else
                std::cout << "Car is unavailable for reservation." << std::endl;
        }
            break;
        case 2:
        {
            this->carManager->displayCars();
            int index = -1;
            std::cout << "Please select a car to unreserve: ";
            std::cin >> index;
            Car* currentCar = this->carManager->getCarByIndex(index);
            if (!currentCar->getAvailable())
            {
                currentCar->unreserveCar();
                std::cout << "Car has been unreserved." << std::endl;
            }
            else
                std::cout << "Car has not been reserved yet." << std::endl;
        }
            break;
        case 3:
            //doInsurance();
            break;
        case 4:
            logOut = true;
            system("cls");
            break;
        }
    }
}