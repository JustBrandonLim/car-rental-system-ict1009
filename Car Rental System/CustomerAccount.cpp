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
            readInsuranceDetails();
            doInsurance();
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

void CustomerAccount::doInsurance() {
    bool back = false;
    while (!back)
    {
        system("title Car Rental System - Customer");
        std::cout << "=== Car Rental System ===" << std::endl;
        std::cout << "1. Buy Collision Insurance" << std::endl;
        std::cout << "2. Buy Injury Insurance" << std::endl;
        std::cout << "3. Buy Theft Insurance" << std::endl;
        std::cout << "4. Buy Full Coverage Insurance" << std::endl;
        std::cout << "5. Display Insurance Details" << std::endl;
        std::cout << "6. Submit Claims" << std::endl;
        std::cout << "7. Save and Back" << std::endl;
        std::cout << "Select an option: ";

        int insuranceMenuOption = 0, duration = 0;

        std::cin >> insuranceMenuOption;

        switch (insuranceMenuOption)
        {
        case 1:
        {
            std::cout << endl << "Enter duration in hours: ";
            std::cin >> duration;
            CollisionInsurance newCollisionInsurance;
            newCollisionInsurance.setDescription("Collision insurance");
            newCollisionInsurance.setDuration(duration);
            newCollisionInsurance.setPayableAmount(duration);
            this->newInsurances.push_back(std::make_unique<CollisionInsurance>(newCollisionInsurance));
            std::cout << "Collision insurance purchased." << std::endl;
            break;
        }
        case 2:
        {
            std::cout << endl << "Enter duration in hours: ";
            std::cin >> duration;
            InjuryInsurance newInjuryInsurance;
            newInjuryInsurance.setDescription("Injury insurance");
            newInjuryInsurance.setDuration(duration);
            newInjuryInsurance.setPayableAmount(duration);
            this->newInsurances.push_back(std::make_unique<InjuryInsurance>(newInjuryInsurance));
            std::cout << "Injury insurance purchased." << std::endl;
            break;
        }
		case 3:
        {
            std::cout << endl << "Enter duration in hours: ";
            std::cin >> duration;
            TheftInsurance newTheftInsurance;
            newTheftInsurance.setDescription("Theft insurance");
            newTheftInsurance.setDuration(duration);
            newTheftInsurance.setPayableAmount(duration);
            this->newInsurances.push_back(std::make_unique<TheftInsurance>(newTheftInsurance));
            std::cout << "Theft insurance purchased." << std::endl;
            break;
        }
        case 4:
        {
            std::cout << endl << "Enter duration in hours: ";
            std::cin >> duration;
            FullCoverageInsurance newFullCoverageInsurance;
            newFullCoverageInsurance.setDescription("Full Coverage insurance");
            newFullCoverageInsurance.setDuration(duration);
            newFullCoverageInsurance.setPayableAmount(duration);
            this->newInsurances.push_back(std::make_unique<FullCoverageInsurance>(newFullCoverageInsurance));
            std::cout << "Full coverage insurance purchased." << std::endl;
            break;
        }
        case 5:
            displayInsurance();
            break;
        case 6:
            storeInsuranceDetails();
            this->insurances.clear();
            this->newInsurances.clear();
            submitClaims();
            break;
        case 7:
            storeInsuranceDetails();
            this->insurances.clear();
            this->newInsurances.clear();
            back = true;
            system("cls");
            break;
        }
    }
}

void CustomerAccount::displayInsurance() {
    for (auto& insurance : this->insurances)
    {
        std::cout << insurance->getDescription() << " " << insurance->getPayableAmount() << " " << insurance->getPaymentStatus() << std::endl;
    }
    for (auto& insurance : this->newInsurances)
    {
        std::cout << insurance->getDescription() << " " << insurance->getPayableAmount() << " " << insurance->getPaymentStatus() << std::endl;
    }
}

void CustomerAccount::storeInsuranceDetails() {
    std::ofstream insuranceFile;

    std::string userName = this->Account::getUsername();

    std::string insuranceCode = "";
	
    insuranceFile.open("insuranceDetails.txt", ios::out | ios::app);
	
    for (auto& insurance : this->newInsurances)
    {
        if (insurance->getDescription() == "Collision insurance")
        {
			insuranceCode = "CI";
            this->insuranceCheck[0] = { true };
		}
		else if (insurance->getDescription() == "Injury insurance")
		{
			insuranceCode = "II";
            this->insuranceCheck[1] = { true };
		}
		else if (insurance->getDescription() == "Theft insurance")
		{
			insuranceCode = "TI";
            this->insuranceCheck[2] = { true };
		}
		else if (insurance->getDescription() == "Full Coverage insurance")
		{
			insuranceCode = "FC";
            this->insuranceCheck[3] = { true };
        }
		
        insuranceFile << userName << " " << insuranceCode << " " << insurance->getDuration()
            << " " << insurance->getPayableAmount() << " " << insurance->getPaymentStatus() << std::endl;
    }
}

void CustomerAccount::readInsuranceDetails() {
	std::ifstream insuranceFile;
    std::string userName = this->getUsername();
	std::string user;
	std::string insuranceType;
	int duration;
	int payableAmount;
	int paymentStatus;
	insuranceFile.open("insuranceDetails.txt", ios::in);
	if (insuranceFile.is_open())
	{
		while (insuranceFile >> user >> insuranceType >> duration >> payableAmount >> paymentStatus)
		{
			if (userName == user)
			{
				if (insuranceType == "CI")
				{
					CollisionInsurance newCollisionInsurance;
					newCollisionInsurance.setDescription("Collision insurance");
					newCollisionInsurance.setDuration(duration);
					newCollisionInsurance.setPayableAmount(duration);
					newCollisionInsurance.setPaymentStatus(paymentStatus);
					this->insurances.push_back(std::make_unique<CollisionInsurance>(newCollisionInsurance));
                    this->insuranceCheck[0] = { true };
				}
				else if (insuranceType == "II")
				{
					InjuryInsurance newInjuryInsurance;
					newInjuryInsurance.setDescription("Injury insurance");
					newInjuryInsurance.setDuration(duration);
					newInjuryInsurance.setPayableAmount(duration);
					newInjuryInsurance.setPaymentStatus(paymentStatus);
					this->insurances.push_back(std::make_unique<InjuryInsurance>(newInjuryInsurance));
                    this->insuranceCheck[1] = { true };
				}
				else if (insuranceType == "TI")
				{
					TheftInsurance newTheftInsurance;
					newTheftInsurance.setDescription("Theft insurance");
					newTheftInsurance.setDuration(duration);
					newTheftInsurance.setPayableAmount(duration);
					newTheftInsurance.setPaymentStatus(paymentStatus);
					this->insurances.push_back(std::make_unique<TheftInsurance>(newTheftInsurance));
                    this->insuranceCheck[2] = { true };
				}
				else if (insuranceType == "FC")
				{
                    FullCoverageInsurance newFullCoverageInsurance;
                    newFullCoverageInsurance.setDescription("Full Coverage insurance");
                    newFullCoverageInsurance.setDuration(duration);
                    newFullCoverageInsurance.setPayableAmount(duration);
                    newFullCoverageInsurance.setPaymentStatus(paymentStatus);
                    this->insurances.push_back(std::make_unique<FullCoverageInsurance>(newFullCoverageInsurance));
                    this->insuranceCheck[3] = { true };
                }
			}
		}
	}
	
    insuranceFile.close();
}

void CustomerAccount::submitClaims() {
    bool back = false;
    std::string user = this->getUsername(), input = "";
    while (!back)
    {
        system("title Car Rental System - Customer");
        std::cout << "=== Car Rental System ===" << std::endl;
        std::cout << "1. Submit Collision Claim" << std::endl;
        std::cout << "2. Submit Injury Claim" << std::endl;
        std::cout << "3. Submit Theft Claim" << std::endl;
        std::cout << "4. Display Claims" << std::endl;
        std::cout << "5. Back" << std::endl;
        std::cout << "Select an option: ";

        int claimsMenuOption = 0;

        std::cin >> claimsMenuOption;

        switch (claimsMenuOption)
        {
        case 1:
        {
            if (this->insuranceCheck[0] == true || this->insuranceCheck[3] == true) {
                std::cout << "Enter your damages: ";
                std::cin.ignore();
                std::getline(std::cin, input);
				CollisionInsurance newCollisionInsurance;
                newCollisionInsurance.submitCarDamages(user, input);
            }
            else {
                std::cout << "You have not bought collision insurance." << std::endl;
            }
            break;
        }
        case 2:
        {
            if (this->insuranceCheck[1] == true || this->insuranceCheck[3] == true) {
                std::cout << "Enter your damages: ";
                std::cin.ignore();
                std::getline(std::cin, input);
                InjuryInsurance newInjuryInsurance;
                newInjuryInsurance.submitInjuries(user, input);
            }
            else {
                std::cout << "You have not bought injury insurance." << std::endl;
            }
            break;
        }
        case 3:
        {
            if (this->insuranceCheck[2] == true || this->insuranceCheck[3] == true) {
                std::cout << "Enter your damages: ";
                std::cin.ignore();
                std::getline(std::cin, input);
                TheftInsurance newTheftInsurance;
                newTheftInsurance.submitStolenItems(user, input);
            }
            else {
                std::cout << "You have not bought theft insurance." << std::endl;
            }
            break;
        }
        case 4:
        {
            CollisionInsurance newCollisionInsurance;
            newCollisionInsurance.showCarDamages(user);
            InjuryInsurance newInjuryInsurance;
            newInjuryInsurance.showInjuries(user);
            TheftInsurance newTheftInsurance;
            newTheftInsurance.showStolenItems(user);
            break;
        }
        case 5:
            back = true;
            system("cls");
            break;
        }
    }
}