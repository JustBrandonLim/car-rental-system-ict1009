#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

#include "Account.h"

class AccountManager
{
private:
	vector<Account> accounts;
public:
	AccountManager();
	void loadAccounts();
	//vector<Account> getAccounts();
	Account getAccountByUsername(string username);
	bool loginAccount(string username, string password);
	bool registerAccount(string username, string password, string name, string dateOfBirth, string address);
	void displayAccounts();
};

