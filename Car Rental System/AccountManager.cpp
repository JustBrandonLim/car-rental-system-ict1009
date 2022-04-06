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

		this->accounts.push_back(Account(accountInformations[0], accountInformations[1], accountInformations[2], accountInformations[3], accountInformations[4]));
	}

	accounts.close();
}

/*vector<Account> AccountManager::getAccounts()
{
	return this->accounts;
}*/

Account AccountManager::getAccountByUsername(string username)
{
	for (Account account : this->accounts)
	{
		if (username == account.getUsername())
			return account;
	}
}

bool AccountManager::registerAccount(string username, string password, string name, string dateOfBirth, string address)
{
	ofstream accounts("accounts.txt", ofstream::app);

	accounts << username << ":" << password << ":" << name << ":" << dateOfBirth << ":" << address << ":F" << endl;

	accounts.close();

	Account newAccount(username, password, name, dateOfBirth, address);

	this->accounts.push_back(newAccount);

	return true;
}

bool AccountManager::loginAccount(string username, string password)
{
	for (Account account : this->accounts)
	{
		if (username == account.getUsername() && password == account.getPassword())
			return true;
	}
	
	return false;
}

void AccountManager::displayAccounts()
{
	cout << "ID\tUsername\tName" << endl;
	for (int index = 0; index < this->accounts.size(); index++)
	{
		cout << index << "\t" << this->accounts[index].getUsername() << "\t" << this->accounts[index].getName() << endl;
	}
}