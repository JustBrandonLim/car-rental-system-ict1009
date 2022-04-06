#include "Account.h"

Account::Account(string username, string password, string name, string dateOfBirth, string address, bool admin)
{
	this->username = username;
	this->password = password;
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
	this->admin = admin;
}

string Account::getUsername()
{
	return this->username;
}

string Account::getPassword()
{
	return this->password;
}

string Account::getName()
{
	return this->name;
}

string Account::getDateOfBirth()
{
	return this->dateOfBirth;
}

string Account::getAddress()
{
	return this->address;
}

bool Account::getAdmin()
{
	return this->admin;
}