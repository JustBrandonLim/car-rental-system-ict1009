#include "AccountManager.h"

AccountManager::AccountManager()
{

}

void AccountManager::loadAccounts()
{
	ifstream accounts("accounts.txt");

	string accountInformation;

	while (getline(accounts, accountInformation))
	{
		vector<string> accountInformations;
		string tempInformation = "";
		for (int index = 0; index < accountInformation.length(); index++)
		{

			if (accountInformation[index] == ':')
			{
				accountInformations.push_back(tempInformation);
				tempInformation = "";
			}
			else
				tempInformation.push_back(accountInformation[index]);

		}

		this->accounts.push_back(new Account(accountInformations[0], accountInformations[1], accountInformations[2], accountInformations[3], accountInformations[4], accountInformations[5] == "T" ? true : false));
	}

	accounts.close();
}

Account* AccountManager::getAccountByUsername(string username)
{
	for (Account* account : this->accounts)
	{
		if (username == account->getUsername())
		{
			return account;
		}
	}

	return NULL;
}

void AccountManager::registerAccount(string username, string password, string name, string dateOfBirth, string address)
{
	ofstream accounts("accounts.txt", ofstream::app);

	accounts << username << ":" << password << ":" << name << ":" << dateOfBirth << ":" << address << ":F" << endl;

	accounts.close();

	this->accounts.push_back(new Account(username, password, name, dateOfBirth, address, false));
}

bool AccountManager::loginAccount(string username, string password)
{
	for (Account* account : this->accounts)
	{
		if (username == account->getUsername() && password == account->getPassword())
			return true;
	}
	
	return false;
}