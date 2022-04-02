#include "Car.h"

void addRental(Car car, int hours) {
    int payable = car.hourRate * hours;
    Rental myRental(hours, payable);
    car.rentals.push_back(myRental);
}
Car::Car(string model, string plateNum, double hourRate, double insurance){
    this->model = model;
    this->plateNum = plateNum;
    this->hourRate = hourRate;
    this->insurance = insurance;
}

void Car::setServicing() {
    if (servicing == true)
        servicing = false;
    else
        servicing = true;
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

bool Car::getServicing() {
    return servicing;
}
vector <Rental> Car::getRentals() {
    return rentals;
}
void Car::displayInfo() {
    cout << "Car Model: " << model << endl;
    cout << "Car Plate Number: " << plateNum << endl;
    cout << "Hourly Rate: " << hourRate << "/hr" << endl;
    if (getServicing() == true)
        cout << "Car due for servicing." << endl;
    else
        cout << "Car serviced." << endl;

}

void Car::displayRentals() {
    cout << "Car Name | Car Plate | Rental hours | Total Payable " << endl;
    for (int i = 0; i < rentals.size(); i++) {
        cout << model << "\t" << plateNum << "\t" << rentals.at(i).getHours() << "\t" << rentals.at(i).getTotalPayable() << endl;
    }
}
/*
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

//undone as need to find a way to access rentList to see if person rent before calculating

double Car::calculateRate(){
    return 0;
}
*/
