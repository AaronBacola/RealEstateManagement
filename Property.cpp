#include "Property.h"
#include <iostream>
using namespace std;

// basic prop details
void Property::displayDetails() const {
    cout << "Property ID: " << propertyID << "\n";
    cout << "City: " << city << ", State: " << state << "\n";
    cout << "Price: $" << price << "\n";
}





