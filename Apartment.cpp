#include "Apartment.h"
#include <iostream>
using namespace std;

// construtor  
Apartment::Apartment(string id, string c, string s, int p, int floor, int rooms, int rent)
    : Property("Apartment", id, c, s, p), floorLevel(floor), roomNum(rooms), rentingPrice(rent) {}


// apt details
void Apartment::displayDetails() const {
    Property::displayDetails();
    cout << "Floor Level: " << floorLevel << "\n";
    cout << "Room Number: " << roomNum << "\n";
	cout << "Rent: " << rentingPrice << "\n";
}

int Apartment::getFloorLevel() const { return floorLevel; }
void Apartment::setFloorLevel(int floor) { floorLevel = floor; }

int Apartment::getRoomNum() const { return roomNum; }
void Apartment::setRoomNum(int rooms) { roomNum = rooms; }

int Apartment::getRent() const { return rentingPrice; }
void Apartment::setRent(int rent) { rentingPrice = rent; }




