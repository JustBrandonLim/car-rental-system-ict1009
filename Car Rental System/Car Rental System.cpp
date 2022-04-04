#include <iostream>
#include <stdlib.h>

#include "CarManager.h"

#include "AdminAccount.h"
#include "CustomerAccount.h"

void doRegisterAccount()
{
    system("title Car Rental System - Register");
    system("cls");
    std::cout << "=== Car Rental System ===" << std::endl;
    std::cout << "Please enter your username: ";

    std::cout << "Please enter your password: ";

    std::cout << "Please enter your name: ";

    std::cout << "Please enter your date of birth (dd/mm/yyyy): ";

    std::cout << "Please enter your address: ";

    std::cout << "Account is registered!" << std::endl;
}

void doLoginAccount(CarManager* carManager)
{
    system("title Car Rental System - Login");

    system("cls");
    std::cout << "=== Car Rental System ===" << std::endl;
    std::cout << "Please enter your username: ";
    std::string username = "";
    std::cin >> username;
    std::cout << "Please enter your password: ";
    std::string password = "";
    std::cin >> password;

    if (username == "admin" && password == "test")
    {
        AdminAccount adminAccount(carManager, username, password, "", "", "");
        system("cls");
        adminAccount.doAdmin();
    }
    else if (username == "cust" && password == "test")
    {
        CustomerAccount customerAccount(carManager, username, password, "", "", "");
        system("cls");
        customerAccount.doCustomer();
    }
    else
    {
        system("cls");
        std::cout << "\x1B[31m*** Wrong username or password! ***\033[0m" << std::endl;
    }
}

/*
void doAdmin() 
{
    system("title Car Rental System - Admin");
    system("cls");
    std::cout << "=== Car Rental System ===" << std::endl;
    std::cout << "1. Add Car" << std::endl;
    std::cout << "2. Remove Car" << std::endl;
    std::cout << "3. Exit" << std::endl;
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
        std::cout << "ADD CAR" << std::endl;
        break;
    case 2:
        break;
    }
}

void doCustomer() 
{
    system("title Car Rental System - Customer");
}*/

int main()
{
    CarManager* carManager = CarManager::getInstance();
    //RentalManager rentalManager;

    while (true)
    {
        system("title Car Rental System");

        std::cout << "=== Car Rental System ===" << std::endl;
        std::cout << "1. Register" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Select an option: ";

        int mainMenuOption = 0;

        std::cin >> mainMenuOption;

        switch (mainMenuOption)
        {
        default:
            exit(0);
            break;
        case 1:
            doRegisterAccount();
            break;
        case 2:
            doLoginAccount(carManager);
            break;
        }
    }

    return 0;
}