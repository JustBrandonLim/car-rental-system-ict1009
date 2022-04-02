#pragma once
#include <iostream>
#include <vector>
#include "Rental.h"

using namespace std;

class Rental;

class Car{
    friend void addRental(Car, int);
private:
    string model;
    string plateNum;
    double hourRate;
    vector <Rental> rentals;
    bool servicing = false;
    double insurance;
public:
    Car();
    Car(string, string, double, double);
    ~Car(){cout << model << " deleted" << endl;}
    void setServicing();
    string getModel();
    string getPlateNum();
    vector <Rental> getRentals();
    double getHourRate();
    bool getServicing();
    void displayInfo();
    void displayRentals();
};
