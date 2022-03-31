#include "Car.h"

Car::Car(string model, string plateNum, double dayRate, double hourRate, float capacity, string transmission){
    this->model = model;
    this->plateNum = plateNum;
    this->dayRate = dayRate;
    this->hourRate = hourRate;
    this->capacity = capacity;
    this->transmission = transmission;
}

void Car::setBooked(){
  if (this->booked == false)
    this->booked = true;
  else
    this->booked = false;
}

void Car::setRental(Rental rent){
  int i = 0;
  rentList[i] = rent;
}

string Car::getModel(){
  return model;
}

string Car::getPlateNum(){
  return plateNum;
}

double Car::getHourRate(){
  return hourRate;
}

double Car::getDayRate(){
  return dayRate;
}

float Car::getCapacity(){
  return capacity;
}

string Car::getTransmission(){
  return transmission;
}

bool Car::getBooked(){
  return booked;
}

void Car::displayInfo(){
    cout << "Car Model: " << model << endl;
    cout << "Car Plate Number: " << plateNum << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Transmission: " << transmission << endl;
    cout << "Hourly Rate: " << hourRate << "/hr" << endl;
    cout << "Daily Rate: " << dayRate << "/day" << endl;
}

//undone as need to find a way to access rentList to see if person rent before calculating
double Car::calculateRate(){
  
}
