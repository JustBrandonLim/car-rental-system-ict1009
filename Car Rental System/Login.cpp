#include "Login.h"
#include "Account.h"
#include<iostream>
#include<string>
#include<fstream>


bool Login::isCustLogIn()
{
    count = 0;

    system("cls");
    std::cout << "please enter the following details" << endl;
    std::cout << "USERNAME :";
    std::cin >> username;
    std::cout << "PASSWORD :";
    std::cin >> password;

    ifstream input("database.txt");
    while (input >> user >> pass >> name >> dob >> address)
    {
        if (user == username && pass == password)

        {
            Account Newuser(user, pass, name, dob, address);
            count = 1;
            system("cls");
        }
    }

    input.close();

    if (count == 1)
    {
        return true;
    }
    else
    {

        return false;
    }
}

bool Login::registerAccount()
{
    system("cls");
    std::cout << "please enter the following details" << endl;
    std::cout << "Enter your Username : ";
    std::cin >> user;
    std::cout << "Enter your Password : ";
    std::cin >> pass;
    std::cout << "Enter your Name: ";
    std::cin >> name;
    std::cout << "Enter your dob (dd/mm/yyyy) : ";
    std::cin >> dob;
    std::cout << "Enter your address: ";
    std::cin >> address;

    ifstream myfileinput;
    ofstream myfileoutput;

    myfileinput.open("database.txt");
    myfileoutput.open("database.txt", std::ios::app);

    if (myfileinput.is_open())
    {
        myfileoutput << user << " " << pass << " " << name << " " << dob << " " << address << " " << endl;

        myfileinput.close();
        myfileoutput.close();
        return true;
    }
    else
    {
        cout << "Unable to open file";
        return false;
    }


}

bool Login::isAdminLogIn()
{
    count = 0;

    system("cls");
    std::cout << "please enter the following details" << endl;
    std::cout << "USERNAME :";
    std::cin >> username;
    std::cout << "PASSWORD :";
    std::cin >> password;

    ifstream input("AdminDatabase.txt");
    while (input >> user >> pass)
    {
        if (user == username && pass == password)

        {
            count = 1;
            system("cls");
        }
    }

    input.close();

    if (count == 1)
    {
        return true;
    }
    else
    {

        return false;
    }
}