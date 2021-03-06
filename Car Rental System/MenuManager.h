#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#include "AccountManager.h"
#include "CarManager.h"
#include "RentalManager.h"

enum class MenuState 
{
	MainMenu,
	LoginMenu,
	RegisterMenu,
	CustomerMenu,
	AdminMenu
};

class MenuManager
{
private:
	MenuState menuState;
	AccountManager* accountManager;
	CarManager* carManager;
	RentalManager* rentalManager;
	Account* account;
public:
	MenuManager(AccountManager* accountManager, CarManager* carManager, RentalManager* rentalManager, MenuState menuState = MenuState::MainMenu);
	MenuState getMenuState();
	void setMenuState(MenuState menuState);
	void handleMenus();
	void mainMenu();
	void loginMenu();
	void registerMenu();
	void customerMenu();
	void adminMenu();
};

