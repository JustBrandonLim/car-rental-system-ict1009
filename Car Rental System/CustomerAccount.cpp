#include "CustomerAccount.h"
#include<fstream>

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
        std::cout << "4. Display Cars you have reserved" << std::endl;
        std::cout << "5. Log Out" << std::endl;
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
                try {

                    std::ifstream myfileinput;
                    std::ofstream myfileoutput;

                    myfileinput.open("Cars_reserved.txt");
                    myfileoutput.open("Cars_reserved.txt", std::ios::app);
                    if (myfileinput.is_open())
                    {
                        myfileoutput << currentCar->getPlateNumber()<< " "<< currentCar->getModel() << " " << this->username << std::endl;
                        myfileinput.close();
                        myfileoutput.close();
                        
                    }
                    else
                    {
                        system("cls");
                        std::cout << "\x1B[31m*** Unable to open file! ***\033[0m" << std::endl;
                    }
                }
                catch (std::exception) {
                    std::cout << "\x1B[31m*** Error! ***\033[0m" << std::endl;
                }
            }
            else
                std::cout << "Car is unavailable for reservation." << std::endl;
        }
            break;
        case 2:
        {
            this->carManager->displayCars();
            int index = -1;
            int found = 0;
            std::string remove_line;
            std::cout << "Please select a car to unreserve: ";
            std::cin >> index;
            Car* currentCar = this->carManager->getCarByIndex(index);
            if (!currentCar->getAvailable())
            {
                
                remove_line = currentCar->getPlateNumber()+" "+ currentCar->getModel() + " " + this->username;
                try
                {
                    std::string line;
                    std::ifstream in("Cars_reserved.txt");
                    if (!in.is_open())
                    {
                        cout << "No cars are reserved yet\n";
                    }
                    ofstream out;
                    out.open("temp.txt", ofstream::out);

                    while (getline(in, line))
                    {
                        if (line != remove_line)
                            out << line << "\n";
                        if (line == remove_line)
                        {
                            found = 1;
                        }
                    }
                    in.close();
                    out.close();
                    if (found == 1)
                    {
                        currentCar->unreserveCar();
                        std::cout << "Car has been unreserved." << std::endl;
                    }
                    else
                    {
                        std::cout << "This car is not reserved by you." << std::endl;
                    }
                    // delete the original file
                    std::remove("Cars_reserved.txt");
                    std::rename("temp.txt", "Cars_reserved.txt");

                }
                catch (std::exception) {
                    system("cls");
                    std::cout << "\x1B[31m*** Error! ***\033[0m" << std::endl;
                }
                
            }
            else
                std::cout << "Car has not been reserved yet." << std::endl;
        }
            break;
        case 3:
            //doInsurance();
            break;
        case 4:
        {
            try {
                std::ifstream input("Cars_reserved.txt");
                std::string carModel;
                std::string carPlate;
                std::string user;
                if (input.is_open())
                {
                    std::cout << "User\tCar Model\tPlate Number" << std::endl;
                    while (input >> carPlate >> carModel >> user)
                    {
                        if (user == this->username) 
                        {
                            std::cout << user << "\t" << carModel << "\t\t" << carPlate << std::endl;
                        }

                    }
                    input.close();
                }

            }
            catch (std::exception) {
                system("cls");
                std::cout << "\x1B[31m*** Error! ***\033[0m" << std::endl;
            }
            break;
        }
        case 5:
            logOut = true;
            system("cls");
            break;
        }
    }
}