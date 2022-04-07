#include "MenuManager.h"

MenuManager::MenuManager(AccountManager* accountManager, CarManager* carManager, RentalManager* rentalManager, MenuState menuState)
{
	this->menuState = menuState;
	this->accountManager = accountManager;
	this->carManager = carManager;
	this->rentalManager = rentalManager;
	this->account = NULL;
}

MenuState MenuManager::getMenuState()
{
	return this->menuState;
}

void MenuManager::setMenuState(MenuState menuState)
{
	this->menuState = menuState;
}

void MenuManager::handleMenus()
{
	while (true)
	{
		switch (this->getMenuState())
		{
		default:
			exit(0);
			break;
		case MenuState::MainMenu:
			this->mainMenu();
			break;
		case MenuState::LoginMenu:
			this->loginMenu();
			break;
		case MenuState::RegisterMenu:
			this->registerMenu();
			break;
		case MenuState::CustomerMenu:
			this->customerMenu();
			break;
		case MenuState::AdminMenu:
			this->adminMenu();
			break;
		}
	}
}

void MenuManager::mainMenu()
{
	system("title Car Rental System");

	cout << "===== Car Rental System =====" << endl;
	cout << "1. Login" << endl;
	cout << "2. Register" << endl;
	cout << "3. Exit" << endl;

	cout << "Please select an option: ";
	int mainMenuSelection = -1;
	cin >> mainMenuSelection;

	switch (mainMenuSelection)
	{
	default:
		exit(0);
		break;
	case 1:
		this->setMenuState(MenuState::LoginMenu);
		break;
	case 2:
		this->setMenuState(MenuState::RegisterMenu);
		break;
	}
}

void MenuManager::loginMenu()
{
	system("title Car Rental System - Login");

	cout << "===== Car Rental System =====" << endl;

	cout << "Please enter your username: ";
	string username = "";
	cin >> username;

	cout << "Please enter your password: ";
	string password = "";
	cin >> password;

	if (this->accountManager->loginAccount(username, password))
	{
		this->account = this->accountManager->getAccountByUsername(username);
		
		cout << "* Welcome, " << account->getUsername() << "." << endl;
		
		if (account->getAdmin())
			this->setMenuState(MenuState::AdminMenu);
		else
			this->setMenuState(MenuState::CustomerMenu);
	}
	else
		cout << "* Invalid username or password! Please try again!" << endl;
}

void MenuManager::registerMenu()
{
	system("title Car Rental System - Register");

	cout << "===== Car Rental System =====" << endl;

	cout << "Please enter your username: ";
	string username = "";
	cin >> username;

	cout << "Please enter your password: ";
	string password = "";
	cin >> password;

	cout << "Please enter your name: ";
	string name = "";
	getline(cin >> ws, name);

	cout << "Please enter your date of birth (dd/mm/yyyy): ";
	string dateOfBirth = "";
	cin >> dateOfBirth;

	cout << "Please enter your address: ";
	string address = "";
	getline(cin >> ws, address);

	if (this->accountManager->getAccountByUsername(username) == NULL)
	{
		this->accountManager->registerAccount(username, password, name, dateOfBirth, address);
		
		this->account = this->accountManager->getAccountByUsername(username);

		cout << "* You have been registered, " << account->getUsername() << "." << endl;
	}
	else
		cout << "* Account already exists!" << endl;

	this->setMenuState(MenuState::MainMenu);
}

void MenuManager::customerMenu()
{
	system("title Car Rental System - Customer");
	
	cout << "===== Car Rental System =====" << endl;
	cout << "1. Reserve a car" << endl;
	cout << "2. Cancel a reservation" << endl;
	cout << "3. Check your reservations" << endl;
	cout << "4. Log out" << endl;
	cout << "5. Exit" << endl;

	cout << "Please select an option: ";
	int customerMenuSelection = -1;
	cin >> customerMenuSelection;

	switch (customerMenuSelection)
	{
	default:
		exit(0);
		break;
	case 1: //RESERVE A CAR
	{
		if (this->carManager->getCars().size() != 0)
		{
			do{
				system("CLS");
				this->carManager->displayCars();

				cin.clear();
				cin.ignore();

				cout << "Please enter the ID to reserve: ";
				int id = -1;
				cin >> id;
				if (cin.fail())
				{
					cout << "* Invalid input!" << endl;
				}
				else if (this->carManager->getCarByIndex(id) != NULL)
				{
					Car* car = this->carManager->getCarByIndex(id);

					if (car->getAvailable())
					{
						cout << "1. Hourly Reservation" << endl;
						cout << "2. Daily Reservation" << endl;

						cout << "Please select an option: ";
						int reservationTypeSelection = -1;
						cin >> reservationTypeSelection;
						if (reservationTypeSelection == 1)
						{
							cout << "Please enter your hours: ";
							int hours = -1;
							cin >> hours;

							this->rentalManager->addHourlyRental(this->account, car, car->getRentalRate(), hours);
						}
						else if (reservationTypeSelection == 2)
						{
							cout << "Please enter your days: ";
							int days = -1;
							cin >> days;

							this->rentalManager->addDailyRental(this->account, car, car->getRentalRate() * 24, days);
						}
						else
						{
							cout << "* Invalid option!" << endl;
						}
					}
					else
						cout << "* This car has been reserved already!" << endl;
				}
				else
					cout << "* Car does not exist!" << endl;

			} while (cin.fail());
		}
		else
			cout << "* There are no cars left to reserve!" << endl;
	}
		break;
	case 2: //CANCEL A RESERVATION
	{

		do
		{
			system("CLS");
			this->rentalManager->displayRentalsByAccountUsername(this->account->getUsername());

			cin.clear();
			cin.ignore();

			cout << "Please enter the ID to cancel: ";
			int id = -1;
			cin >> id;
			if (cin.fail())
			{
				cout << "* Invalid input!" << endl;
			}
			else if (this->rentalManager->getRentalByIndex(id) != NULL)
			{
				Rental* rental = this->rentalManager->getRentalByIndex(id);
				if (rental->getAccount()->getUsername() == this->account->getUsername())
				{
					this->rentalManager->cancelRentalByIndex(id);
				}
				else
					cout << "* Reservation does not belong to you!" << endl;

			}
			else
				cout << "* Reservation does not exist!" << endl;
		} while (cin.fail());

	}
		break;
	case 3:
		this->rentalManager->displayRentalsByAccountUsername(this->account->getUsername());
		break;
	case 4:
		cout << "* You have logged out successfully." << endl;
		this->setMenuState(MenuState::MainMenu);
		break;
	}
}

void MenuManager::adminMenu()
{
	system("title Car Rental System - Admin");

	cout << "===== Car Rental System =====" << endl;
	cout << "1. Add a car" << endl;
	cout << "2. Remove a car" << endl;
	cout << "3. Display the list of cars" << endl;
	cout << "4. Log out" << endl;
	cout << "5. Exit" << endl;

	cout << "Please select an option: ";
	int adminMenuSelection = -1;
	cin >> adminMenuSelection;

	switch (adminMenuSelection)
	{
	default:
		exit(0);
		break;
	case 1:
	{
		cout << "Please enter the car plate: ";
		string carPlate = "";
		cin >> carPlate;

		cout << "Please enter the model: ";
		string model = "";
		getline(cin >> ws, model);

		cout << "Please enter the transmission: ";
		string transmission = "";
		cin >> transmission;

		cout << "Please enter the rental rate: ";
		double rentalRate = 0.0;
		cin >> rentalRate;

		if (this->carManager->getCarByCarPlate(carPlate) == NULL)
		{
			this->carManager->addCar(carPlate, model, transmission, rentalRate, true);

			Car* car = this->carManager->getCarByCarPlate(carPlate);

			cout << "* " << car->getCarPlate() << " has been added." << endl;
		}
		else
			cout << "* Car already exists!" << endl;

		this->setMenuState(MenuState::AdminMenu);
	}
		break;
	case 2:
	{
		if (this->carManager->getCars().size() != 0)
		{
			do
			{
				system("CLS");
				this->carManager->displayCars();

				cin.clear();
				cin.ignore();

				cout << "Please enter the ID to delete: ";
				int id = -1;
				cin >> id;
				if (cin.fail())
				{
					cout << "* Invalid input!" << endl;
				}
				else if (this->carManager->getCarByIndex(id) != NULL)
					this->carManager->removeCarByIndex(id);
				else
					cout << "* Car does not exist!" << endl;
			} while (cin.fail());

		}
		else
			cout << "* There are no cars left to delete." << endl;

		this->setMenuState(MenuState::AdminMenu);
	}
		break;
	case 3:
		if (this->carManager->getCars().size() != 0)
			this->carManager->displayCars();
		else
			cout << "* There are no cars left to display." << endl;
		break;
	case 4:
		cout << "* You have logged out successfully." << endl;
		this->setMenuState(MenuState::MainMenu);
		break;
	}
}
