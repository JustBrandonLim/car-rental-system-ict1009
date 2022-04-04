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
            doInsurance();
            break;
        case 4:
            logOut = true;
            system("cls");
            break;
        }
    }
}

void CustomerAccount::doInsurance() {
    bool goBack = false;
    while (!goBack)
    {
        system("title Car Rental System - Customer");
        std::cout << "=== Car Rental System ===" << std::endl;
        std::cout << "1. Buy Collision Insurance" << std::endl;
        std::cout << "2. Buy Injury Insurance" << std::endl;
        std::cout << "3. Buy Theft Insurance" << std::endl;
        std::cout << "4. Buy Full Coverage Insurance" << std::endl;
        std::cout << "5. Display Insurance" << std::endl;
        std::cout << "6. Back" << std::endl;
        std::cout << "Select an option: ";

        int insuranceOption = 0, duration = 0;
        std::string description = "";

        std::cin >> insuranceOption;

        switch (insuranceOption)
        {
        default:
            exit(0);
            break;
        case 1: {
            std::cout << "Enter Duration: ";
            std::cin >> duration;
            std::cout << "Enter Details: ";
            std::cin >> description;
            CollisionInsurance newCollisionInsurance(duration, description);
            buyInsurance(newCollisionInsurance);
            //displayInsurance();
            break;
        }
        case 2:

            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            displayInsurance();
            break;
        case 6:
            goBack = true;
            system("cls");
            break;
        }
    }
}

void CustomerAccount::buyInsurance(Insurance insurance) {
    this->insurances.push_back(make_unique<Insurance>(insurance));
}

void CustomerAccount::displayInsurance() {
    std::cout << insurances[0].get()->getDescription() << std::endl;;
}