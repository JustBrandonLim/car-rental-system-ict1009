#include "Account.h"

Account::Account() {}

Account::Account(std::string username, std::string password, std::string name, std::string dateOfBirth, std::string address)
{
	this->username = username;
	this->password = password;
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
}

std::string Account::getUsername()
{
	return this->username;
}

std::string Account::getName()
{
	return this->name;
}

std::string Account::getDateOfBirth()
{
	return this->dateOfBirth;
}

std::string Account::getAddress()
{
	return this->address;
}