#include "House.h"
#include <iostream>

using namespace std;


House::House(string id, string c, string s, int p, int numBedrooms, int numBathrooms)
    : Property("House", id, c, s, p), numBedrooms(numBedrooms), numBathrooms(numBathrooms) {}

// display house details
void House::displayDetails() const {
    Property::displayDetails();
    cout << "Number of Bedrooms: " << numBedrooms << "\n";
    cout << "Number of Bathrooms: " << numBathrooms << "\n";
}






