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
void CustomerAccount::doReserve()
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
                myfileoutput << currentCar->getPlateNumber() << " " << currentCar->getModel() << " " << this->username << std::endl;
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

void CustomerAccount::doUnreserved() 
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

        remove_line = currentCar->getPlateNumber() + " " + currentCar->getModel() + " " + this->username;
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

void CustomerAccount::doDisplayCars()
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
}

void CustomerAccount::doCompare()
{
    try {
        carManager->displayCars();
        int compareIndex1 = -1;
        std::cout << "Please select first car to compare: ";
        std::cin >> compareIndex1;
        Car* car1 = this->carManager->getCarByIndex(compareIndex1);
        int compareIndex2 = -1;
        std::cout << "Please select second car to compare: ";
        std::cin >> compareIndex2;
        Car* car2 = this->carManager->getCarByIndex(compareIndex2);
        if (car1 > car2)
            std::cout << car2->getModel() << " Cheaper than " << car1->getModel() << std::endl;
        else if (car1->getDailyRate() == car2->getDailyRate())
            std::cout << car2->getModel() << " is equal to " << car1->getModel() << std::endl;
        else
            std::cout << car1->getModel() << " Cheaper than " << car2->getModel() << std::endl;

    }
    catch (std::exception) {
        system("cls");
        cout << "\x1B[31m*** Error! ***\033[0m" << std::endl;
    }
}

void CustomerAccount::doPayment()
{
    try {
        std::ifstream input("Cars_reserved.txt");
        std::string carModel;
        std::string carPlate;
        std::string user;
        int index = 0;
        if (input.is_open())
        {
            std::cout << "Index\tUser\tCar Model\tPlate Number" << std::endl;

            while (input >> carPlate >> carModel >> user)
            {
                if (user == this->username)
                {
                    std::cout << index << "\t" << user << "\t" << carModel << "\t\t" << carPlate << std::endl;
                    index++;
                }

            }
            input.close();
        }
        int payIndex = -1, daysRented;
        std::cout << "Select Index of Car to pay: ";
        std::cin >> payIndex;
        if (payIndex < index)
        {
            std::cout << "Enter days rented: ";
            std::cin >> daysRented;
            Car* payCar = this->carManager->getCarByIndex(payIndex);
            std::cout << "Payable for car: $" << payCar->getDailyRate() * daysRented << std::endl;
        }
        else
        {
            std::cout << "invalid option." << endl;

        }

    }
    catch (std::exception) {
        system("cls");
        std::cout << "\x1B[31m*** Error! ***\033[0m" << std::endl;
    }
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
        std::cout << "5. Compare Cars" << std::endl;
        std::cout << "6. Payment" << std::endl;
        std::cout << "7. Log Out" << std::endl;
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
            doReserve();
            break;
        }
        
        case 2:
        {
            doUnreserved();
        }
        break;
        case 3:
            readInsuranceDetails();
            doInsurance();
            break;
        case 4:
        {
            doDisplayCars();
            break;
        }
        case 5:
        {
            doCompare();
            break;
        }
        case 6:
          {
            doPayment();
            break;
        }
        case 7:
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
            if (this->insuranceCheck[0] == true) {
				std::cout << std::endl << "You already own collision insurance." << std::endl;
            }
            else {
                std::cout << std::endl << "Enter duration in hours: ";
                std::cin >> duration;
                CollisionInsurance newCollisionInsurance;
                newCollisionInsurance.setDescription("Collision insurance");
                newCollisionInsurance.setDuration(duration);
                newCollisionInsurance.setPayableAmount(duration);
                this->newInsurances.push_back(std::make_unique<CollisionInsurance>(newCollisionInsurance));
                std::cout << "Collision insurance purchased." << std::endl;
                this->insuranceCheck[0] = true;
            }
            break;
        }
        case 2:
        {
            if (this->insuranceCheck[1] == true) {
                std::cout << std::endl << "You already own injury insurance." << std::endl;
            }
            else {
                std::cout << std::endl << "Enter duration in hours: ";
                std::cin >> duration;
                InjuryInsurance newInjuryInsurance;
                newInjuryInsurance.setDescription("Injury insurance");
                newInjuryInsurance.setDuration(duration);
                newInjuryInsurance.setPayableAmount(duration);
                this->newInsurances.push_back(std::make_unique<InjuryInsurance>(newInjuryInsurance));
                std::cout << "Injury insurance purchased." << std::endl;
                this->insuranceCheck[1] = true;
            }
            break;
        }
		case 3:
        {
            if (this->insuranceCheck[2] == true) {
                std::cout << std::endl << "You already own theft insurance." << std::endl;
            }
            else {
                std::cout << endl << "Enter duration in hours: ";
                std::cin >> duration;
                TheftInsurance newTheftInsurance;
                newTheftInsurance.setDescription("Theft insurance");
                newTheftInsurance.setDuration(duration);
                newTheftInsurance.setPayableAmount(duration);
                this->newInsurances.push_back(std::make_unique<TheftInsurance>(newTheftInsurance));
                std::cout << "Theft insurance purchased." << std::endl;
                this->insuranceCheck[2] = true;
            }
            break;
        }
        case 4:
        {
            if (this->insuranceCheck[3] == true) {
                std::cout << std::endl << "You already own full coverage insurance." << std::endl;
            }
            else {
                std::cout << endl << "Enter duration in hours: ";
                std::cin >> duration;
                FullCoverageInsurance newFullCoverageInsurance;
                newFullCoverageInsurance.setDescription("Full Coverage insurance");
                newFullCoverageInsurance.setDuration(duration);
                newFullCoverageInsurance.setPayableAmount(duration);
                this->newInsurances.push_back(std::make_unique<FullCoverageInsurance>(newFullCoverageInsurance));
                std::cout << "Full coverage insurance purchased." << std::endl;
                this->insuranceCheck[3] = true;
            }
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

void CustomerAccount::deleteInsuranceDetails(std::string insuranceCode) {
    std::ifstream insuranceFile;
    std::ofstream newInsuranceFile("newInsuranceFile.txt");
	std::string userName = this->getUsername();
    std::string user;
    std::string insuranceType;
    int duration;
    int payableAmount;
    int paymentStatus;
    bool deleted = false;

    insuranceFile.open("insuranceDetails.txt", ios::app);

    if (insuranceFile.is_open()) {
        while (insuranceFile >> user >> insuranceType >> duration >> payableAmount >> paymentStatus) {
            if (user == userName && insuranceType == insuranceCode && deleted == false) {
                if (insuranceCode == "CI")
                    this->insuranceCheck[0] = false;
                else if (insuranceCode == "II")
                    this->insuranceCheck[1] = false;
                else if (insuranceCode == "TI")
                    this->insuranceCheck[2] = false;
				else if (insuranceCode == "FC")
					this->insuranceCheck[3] = false;
                deleted = true;
				continue;
			}
			else {
				newInsuranceFile << user << " " << insuranceType << " " << duration << " " << payableAmount << " " << paymentStatus << std::endl;
			}
				
         }
    }
	
    insuranceFile.close();
    newInsuranceFile.close();
	
    remove("insuranceDetails.txt");
    rename("newInsuranceFile.txt", "insuranceDetails.txt");
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
                if (this->insuranceCheck[0] == true) {
                    deleteInsuranceDetails("CI");
                }
                else if (this->insuranceCheck[3] == true) {
                    deleteInsuranceDetails("FC");
                }
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
                if (this->insuranceCheck[1] == true) {
                    deleteInsuranceDetails("II");
                }
                else if (this->insuranceCheck[3] == true) {
                    deleteInsuranceDetails("FC");
                }
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
                if (this->insuranceCheck[2] == true) {
                    deleteInsuranceDetails("TI");
                }
                else if (this->insuranceCheck[3] == true) {
                    deleteInsuranceDetails("FC");
                }
            }
            else {
                std::cout << "You have not bought theft insurance." << std::endl;
            }
            break;
        }
        case 4:
        {
			std::cout << std::endl << "Car Damages: " << std::endl;
            CollisionInsurance newCollisionInsurance;
            newCollisionInsurance.showCarDamages(user);

			std::cout << std::endl << "Injuries: " << std::endl;
            InjuryInsurance newInjuryInsurance;
            newInjuryInsurance.showInjuries(user);

			std::cout << std::endl << "Stolen Items: " << std::endl;
            TheftInsurance newTheftInsurance;
            newTheftInsurance.showStolenItems(user);
            break;
        }
        case 5:
            readInsuranceDetails();
            back = true;
            system("cls");
            break;
        }
    }
}