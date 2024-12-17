#ifndef APARTMENT_H
#define APARTMENT_H

#include "Property.h"

class Apartment : public Property {
public:
	Apartment(string id, string c, string s, int p, int floor, int rooms, int rent);
	void displayDetails() const override;

	int getFloorLevel() const;
	void setFloorLevel(int floor);

	int getRoomNum() const;
	void setRoomNum(int rooms);

	int getRent() const;
	void setRent(int rent);

private:
	int floorLevel;
	int roomNum;
	int rentingPrice;
};

#endif // APARTMENT_H



