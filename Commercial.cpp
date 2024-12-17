#include "Commercial.h"
#include <iostream>
using namespace std;

Commercial::Commercial(const string& id, const string& city, const string& state, int price, int parkingSpots)
    : Property("Commercial", id, city, state, price), parkingSpots(parkingSpots) {}


void Commercial::displayDetails() const {
    Property::displayDetails();  // Call base class displayDetails
    cout << "Parking Spots: " << parkingSpots << "\n";
}

int Commercial::getParkingSpots() const { return parkingSpots; }
void Commercial::setParkingSpots(int spots) { parkingSpots = spots; }




