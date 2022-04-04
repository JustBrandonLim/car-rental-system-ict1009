#pragma once

#include <string>

class Account
{
protected:
	std::string username;
	std::string password;
	std::string name;
	std::string dateOfBirth;
	std::string address;
public:
	Account();
	Account(std::string, std::string, std::string, std::string, std::string);
	std::string getUsername();
	std::string getName();
	std::string getDateOfBirth();
	std::string getAddress();
};

