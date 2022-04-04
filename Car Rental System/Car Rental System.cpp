#include <iostream>
#include <stdlib.h>

#include "CarManager.h"

#include "AdminAccount.h"
#include "CustomerAccount.h"
#include<fstream>


void doRegisterAccount()
{
    system("title Car Rental System - Register");
    system("cls");
    std::string user = "";
    std::string pass = "";
    std::string name = "";
    std::string dob = "";
    std::string address = "";
    std::string customer = "F";

    std::cout << "=== Car Rental System ===" << std::endl;
    std::cout << "Please enter your username: ";
    std::cin >> user;
    std::cout << "Please enter your password: ";
    std::cin >> pass;
    std::cout << "Please enter your name: ";
    std::cin >> name;
    std::cout << "Please enter your date of birth (dd/mm/yyyy): ";
    std::cin >> dob;
    std::cout << "Please enter your address: ";
    std::cin >> address;

    std::ifstream myfileinput;
    std::ofstream myfileoutput;

    myfileinput.open("Account.txt");
    myfileoutput.open("Account.txt", std::ios::app);

    if (myfileinput.is_open())
    {
        myfileoutput << user << " " << pass << " " << name << " " << dob << " " << address << " " << customer << " " << std::endl;
        myfileinput.close();
        myfileoutput.close();
        std::cout << "Account is registered!" << std::endl;
    }
    else
    {
        std::cout << "Unable to open file";
    }

    


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
    std::string user = "";
    std::string pass = "";
    std::string name = "";
    std::string dob = "";
    std::string address = "";
    std::string checkadmin = "";
    std::string message = "File doesn't exist";

    try {
        std::ifstream input("Account.txt");

        while (input >> user >> pass >> name >> dob >> address >> checkadmin)
        {

            if (username == user && password == pass && checkadmin == "T")
            {
                AdminAccount adminAccount(carManager, user, pass, name, dob, address);
                system("cls");
                adminAccount.doAdmin();
            }
            else if (username == user && password == pass && checkadmin == "F")
            {
                CustomerAccount customerAccount(carManager, user, pass, name, dob, address);
                system("cls");
                customerAccount.doCustomer();
            }
            else
            {
                system("cls");
                std::cout << "\x1B[31m*** Wrong username or password! ***\033[0m" << std::endl;
            }
        }

    } catch (std::exception) 
      {
            std::cout << "File does not exist" << std::endl;
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