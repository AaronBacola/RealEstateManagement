#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Property.h"

using namespace std;

class Commercial : public Property {
public:
    Commercial(const std::string& id, const std::string& city, const std::string& state, int price, int parkingSpots);
    void displayDetails() const override;
    int getParkingSpots() const;
    void setParkingSpots(int spots);

private:
    int parkingSpots;
};




#endif // COMMERCIAL_H