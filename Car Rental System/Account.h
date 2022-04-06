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
	Account(string username, string password, string name, string dateOfBirth, string address);
	string getUsername();
	string getPassword();
	string getName();
	string getDateOfBirth();
	string getAddress();
};
