#include <iostream>

using namespace std;

#include "AccountManager.h"
#include "CarManager.h"
#include "RentalManager.h"
#include "MenuManager.h"

int main()
{
	//Initialize account manager
	AccountManager accountManager;

	//Load existing accounts
	accountManager.loadAccounts();

	//Initialize car manager
	CarManager carManager;

	//Load existing cars
	carManager.loadCars();

	//Initialize rental manager
	RentalManager rentalManager;
	
	//Load existing rentals
	//rentalManager.loadRentals();

	//Initialize menu
	MenuManager menuManager(&accountManager, &carManager, &rentalManager);

	//Handle menus
	menuManager.handleMenus();

	return 0;
}
