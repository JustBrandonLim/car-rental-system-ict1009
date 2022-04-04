#include "Car.h"

Car::Car()
{

}

Car::Car(std::string model, std::string plateNumber, double hourlyRate, double insurance) {
    this->model = model;
    this->plateNumber = plateNumber;
    this->hourlyRate = hourlyRate;
    this->insurance = insurance;
}

void Car::setServicing() {
    if (servicing == true)
        servicing = false;
    else
        servicing = true;
}

std::string Car::getModel() {
    return this->model;
}

std::string Car::getPlateNumber() {
    return this->plateNumber;
}

double Car::getHourlyRate() {
    return this->hourlyRate;
}

bool Car::getServicing() {
    return servicing;
}

void Car::displayInfo() {
    std::cout << "Car Model: " << model << std::endl;
    std::cout << "Car Plate Number: " << plateNumber << std::endl;
    std::cout << "Hourly Rate: " << hourlyRate << "/hr" << std::endl;
    if (getServicing() == true)
        std::cout << "Car due for servicing." << std::endl;
    else
        std::cout << "Car serviced." << std::endl;

}

bool Car::operator>(Car x) {
    return hourlyRate > x.hourlyRate ? true : false;
}

bool Car::operator==(Car x) {
    return plateNumber == x.plateNumber ? true : false;
}
/*
vector <Rental> Car::getRentals() {
    return rentals;
}

void Car::displayRentals() {
    std::cout << "Car Name | Car Plate | Rental hours | Total Payable " << std::endl;
    for (int i = 0; i < rentals.size(); i++) {
        std::cout << model << "\t" << plateNumber << "\t" << rentals.at(i).getHours() << "\t" << rentals.at(i).getTotalPayable() << std::endl;
    }
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
