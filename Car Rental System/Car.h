#pragma once
#include <iostream>
//#include <vector>
#include "Rental.h"

class Rental;

class Car{
    friend void addRental(Car, int);
private:
    std::string model;
    std::string plateNumber;
    double hourlyRate;
    //vector <Rental> rentals;
    bool servicing = false;
    double insurance;
public:
    Car();
    Car(std::string, std::string, double, double);
    ~Car(){}; //cout << model << " deleted" << endl;}
    void setServicing();
    std::string getModel();
    std::string getPlateNumber();
    vector <Rental> getRentals();
    double getHourlyRate();
    bool getServicing();
    void displayInfo();
    //void displayRentals();
    bool operator >(Car);
};
