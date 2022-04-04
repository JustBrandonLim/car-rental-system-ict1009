#pragma once
#include <iostream> 
#include "Menu.h"
class Login
{
private:
	int count;
	string username, password, user, pass, name, dob, address;
	Menu menu;
public:
	bool isCustLogIn();
	bool registerAccount();
	bool isAdminLogIn();
};

