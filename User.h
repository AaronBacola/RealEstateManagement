#ifndef USER_H
#define USER_H

#include <string>
#include <memory>
#include "Property.h" 
#include "Apartment.h" 
#include "Commercial.h" 
#include "House.h" 

class user {
public:
    void propDetails(const std::string& line, std::unique_ptr<Property>& property);
    void searchProperties();

    void viewProperty();
    void viewPropertyDetails();
};

#endif // USER_H





