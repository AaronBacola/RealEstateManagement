#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include <iostream>
using namespace std;

class Property {
public:
    Property(const string& type, const string& id, const string& c, const string& s, int p)
        : propertyType(type), propertyID(id), city(c), state(s), price(p) {}

    virtual void displayDetails() const;

    string getPropertyID() const { return propertyID; }
    string getCity() const { return city; }
    string getState() const { return state; }
    int getPrice() const { return price; }

protected:
    string propertyType;
    string propertyID;
    string city;
    string state;
    int price;
};

#endif // PROPERTY_H




