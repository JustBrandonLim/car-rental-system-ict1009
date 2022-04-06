#pragma once

#include <string>
#include <iostream>

using namespace std;

class Account
{
private:
	string username;
	string password;
	string name;
	string dateOfBirth;
	string address;
	bool admin;
public:
	Account(string username, string password, string name, string dateOfBirth, string address, bool admin);
	string getUsername();
	string getPassword();
	string getName();
	string getDateOfBirth();
	string getAddress();
	bool getAdmin();
};
