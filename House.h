#ifndef HOUSE_H
#define HOUSE_H

#include "Property.h"

class House : public Property {
public:
    House(string id, string c, string s, int p, int numBedrooms, int numBathrooms);

    void displayDetails() const override;

    int getNumBedrooms() const { return numBedrooms; }
    int getNumBathrooms() const { return numBathrooms; }

private:
    int numBedrooms;
    int numBathrooms;
};

#endif // HOUSE_H





