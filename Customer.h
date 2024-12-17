#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "User.h"

class Customer : public user {

public:
    void reserveProperty();
	void printReservedProperties();

};

#endif // CUSTOMER_H


