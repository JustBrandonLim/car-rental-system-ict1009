#pragma once
#include <iostream>
#include "Rental.h"

using namespace std;

class Rental;

class Car{
private:
    string model;
    string plateNum;
    double hourRate;
    double dayRate;
    float capacity;
    string transmission;
    bool booked = false;
    Rental rentList[3];
public:
    Car();
    Car(string, string, double, double, float, string);
    ~Car(){cout << model << " deleted" << endl;}
    void setBooked();
    void setRental(Rental);
    string getModel();
    string getPlateNum();
    double getHourRate();
    double getDayRate();
    float getCapacity();
    string getTransmission();
    bool getBooked();
    void displayInfo();
    double calculateRate();
};