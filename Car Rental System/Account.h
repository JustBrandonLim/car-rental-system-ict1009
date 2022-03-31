#pragma once

#include <string>

using namespace std;

class Account
{
private:
	string username;
	string password;
	string name;
	string dateOfBirth;
	string address;
public:
	Account();
	Account(string, string, string, string, string);
	string getUsername();
	string getName();
	string getDateOfBirth();
	string getAddress();
};

