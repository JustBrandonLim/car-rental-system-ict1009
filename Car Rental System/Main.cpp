#include <iostream>

using namespace std;

#include "AccountManager.h"
#include "CarManager.h"
#include "MenuManager.h"

int main()
{
	//Initialize account manager
	AccountManager accountManager;

	//Load existing accounts
	accountManager.loadAccounts();

	//Initialize car manager
	CarManager carManager;

	carManager.loadCars();

	//Initialize menu
	MenuManager menuManager(&accountManager, &carManager);

	//Handle menus
	menuManager.handleMenus();

	return 0;
}
