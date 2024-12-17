#ifndef AGENT_H
#define AGENT_H

#include <string>
#include <fstream>
#include <iostream>
#include "Property.h"

class Agent {
public:

    void addProperty();
    void removeProperty();
    void modifyProperty();

private:
    void savePropertyToFile(const Property* property, std::ofstream& file);

};

#endif // AGENT_H


