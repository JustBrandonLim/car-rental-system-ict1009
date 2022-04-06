#include "MenuManager.h"

MenuManager::MenuManager(AccountManager* accountManager, CarManager* carManager, MenuState menuState)
{
	this->menuState = menuState;
	this->accountManager = accountManager;
	this->carManager = carManager;
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
		Account account = this->accountManager->getAccountByUsername(username);
		
		cout << "* Welcome, " << account.getUsername() << "." << endl;

		this->setMenuState(MenuState::AdminMenu);
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

	if (this->accountManager->registerAccount(username, password, name, dateOfBirth, address))
	{
		Account account = this->accountManager->getAccountByUsername(username);

		cout << "* You have been registered, " << account.getUsername() << "." << endl;

		this->setMenuState(MenuState::MainMenu);
	}
	else
		cout << "* Something went wrong! Please try again!" << endl;
}

void MenuManager::customerMenu()
{
	system("title Car Rental System - Customer");
	cin.get();
}

void MenuManager::adminMenu()
{
	system("title Car Rental System - Admin");

	cout << "===== Car Rental System =====" << endl;
	cout << "1. Add a car" << endl;
	cout << "2. Remove a car" << endl;
	cout << "3. Log out" << endl;
	cout << "4. Exit" << endl;

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

		if (this->carManager->addCar(carPlate, model, transmission, rentalRate, true))
		{
			Car car = this->carManager->getCarByCarPlate(carPlate);

			car.displayCar();

			cout << "* " << car.getCarPlate() << " has been added." << endl;

			this->setMenuState(MenuState::AdminMenu);
		}
		else
			cout << "* Something went wrong! Please try again!" << endl;
	}
		break;
	case 2:
	{
		this->carManager->displayCars();

		cout << "Please enter the id to delete: ";
		int id = -1;
		cin >> id;

		if (this->carManager->removeCarByIndex(id))
		{
			cout << "* Car " << id << " has been deleted." << endl;

			this->setMenuState(MenuState::AdminMenu);
		}
		else
			cout << "* Something went wrong! Please try again!" << endl;
	}
		break;
	case 3:
		cout << "* You have logged out successfully." << endl;
		this->setMenuState(MenuState::MainMenu);
		break;
	}
}
