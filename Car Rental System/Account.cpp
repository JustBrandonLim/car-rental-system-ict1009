#include "Account.h"

Account::Account(string username, string password, string name, string dateOfBirth, string address) 
{
	this->username = username;
	this->password = password;
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
}

string Account::getUsername()
{
	return this->username;
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