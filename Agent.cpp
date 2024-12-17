#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Apartment.h"
#include "Commercial.h"
#include "House.h"
#include "Property.h"
#include "Agent.h"
using namespace std;

void Agent::addProperty() {
    string propertyID, city, state, propertyType;
    int price;
    cout << "\n===== Add Property =====\n";
    cout << "Enter Property ID: ";
    cin >> propertyID;

    // open the file
    ofstream file("properties.txt", ios::app);
    if (!file) {
        cerr << "Error: Unable to open properties file.\n";
        return;
    }

    cout << "Enter City: ";
    cin.ignore();
    getline(cin, city);
    cout << "Enter State: ";
    getline(cin, state);
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Property Type (Commercial, House, Apartment): ";
    cin >> propertyType;

    Property* property = nullptr;

    //add info based on prop type
    if (propertyType == "Apartment") {
        int floorLevel, roomNum, rentingPrice;
        cout << "Enter Floor Level: ";
        cin >> floorLevel;
        cout << "Enter Room Number: ";
        cin >> roomNum;
        cout << "Enter Renting Price: ";
        cin >> rentingPrice;

        property = new Apartment(propertyID, city, state, price, floorLevel, roomNum, rentingPrice);
    }
    else if (propertyType == "Commercial") {
        int parkingSpots;
        cout << "Enter Parking Spots: ";
        cin >> parkingSpots;
        property = new Commercial(propertyID, city, state, price, parkingSpots);
    }
    else if (propertyType == "House") {
        int numBedrooms, numBathrooms;
        cout << "Enter Number of Bedrooms: ";
        cin >> numBedrooms;
        cout << "Enter Number of Bathrooms: ";
        cin >> numBathrooms;
        property = new House(propertyID, city, state, price, numBedrooms, numBathrooms);
    }
    else {
        cout << "Invalid property type. Please enter one of the following: Commercial, House, Apartment.\n";
        return;
    }

    //save to file
    savePropertyToFile(property, file);

    cout << "Property added successfully.\n";
    file.close();

    delete property; //clean memory
}

void Agent::modifyProperty() {
    string propertyID;
    cout << "\n===== Modify Property =====\n";
    cout << "Enter Property ID to modify: ";
    cin >> propertyID;

    ifstream file("properties.txt");
    if (!file) {
        cerr << "Error: Unable to open properties file.\n";
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error: Unable to open temp file.\n";
        return;
    }

    string line;
    bool found = false;

    // loop for matching the prop ID and collect new details
    while (getline(file, line)) {
        stringstream ss(line);
        string currentPropertyID, userID;
        getline(ss, currentPropertyID, ',');
        getline(ss, userID, ',');

        if (userID == propertyID) {
            found = true;
            cout << "Property found! Now, enter the new details:\n";

            string city, state;
            int price;
            cout << "Enter New City: ";
            cin.ignore();
            getline(cin, city);
            cout << "Enter New State: ";
            getline(cin, state);
            cout << "Enter New Price: ";
            cin >> price;

            string propertyType;
            cout << "Enter Property Type (Commercial, House, Apartment): ";
            cin >> propertyType;

            Property* property = nullptr;

            // info for apartment
            if (propertyType == "Apartment") {
                int floorLevel, roomNum, rentingPrice;
                cout << "Enter New Floor Level: ";
                cin >> floorLevel;
                cout << "Enter New Room Number: ";
                cin >> roomNum;
                cout << "Enter New Renting Price: ";
                cin >> rentingPrice;
                property = new Apartment(propertyID, city, state, price, floorLevel, roomNum, rentingPrice);
            }
            // info for commercial
            else if (propertyType == "Commercial") {
                int parkingSpots;
                cout << "Enter New Parking Spots: ";
                cin >> parkingSpots;
                property = new Commercial(propertyID, city, state, price, parkingSpots);
            }
            // info for house
            else if (propertyType == "House") {
                int numBedrooms, numBathrooms;
                cout << "Enter New Number of Bedrooms: ";
                cin >> numBedrooms;
                cout << "Enter New Number of Bathrooms: ";
                cin >> numBathrooms;
                property = new House(propertyID, city, state, price, numBedrooms, numBathrooms);
            }
            else {
                cout << "Invalid property type.\n";
                return;
            }

            savePropertyToFile(property, tempFile);
            delete property; // clean mem
        }
        else {
            tempFile << line << endl;
        }
    }

    if (found) {
        cout << "Property modified successfully!\n";
    }
    else {
        cout << "Property not found.\n";
    }

    file.close();
    tempFile.close();

    // replace original file with updated temp file
    remove("properties.txt");
    rename("temp.txt", "properties.txt");
}

void Agent::removeProperty() {
    string propertyID;
    cout << "\n===== Remove Property =====\n";
    cout << "Enter Property ID to remove: ";
    cin >> propertyID;

    ifstream file("properties.txt");
    if (!file) {
        cerr << "Error: Unable to open properties file.\n";
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error: Unable to open temp file.\n";
        return;
    }

    string line;
    bool found = false;

    // loop for prop ID   
    while (getline(file, line)) {
        stringstream ss(line);
        string propertyType, currentPropertyID;
        getline(ss, propertyType, ',');  // skip property type
        getline(ss, currentPropertyID, ',');  // read property ID

        if (currentPropertyID == propertyID) {
            found = true; // prop, dont write to the temp file
            cout << "Property removed successfully.\n";
        }
        else {
            // property doesn't match keep original
            tempFile << line << endl;
        }
    }

    if (!found) {
        cout << "Property not found.\n";
    }

    file.close();
    tempFile.close();

    // replace the original file with temp
    remove("properties.txt");
    rename("temp.txt", "properties.txt");
}


void Agent::savePropertyToFile(const Property* property, std::ofstream& file) {
    // Id property type
    string propertyType = "Unknown"; // Default
    if (auto apartment = dynamic_cast<const Apartment*>(property)) {
        propertyType = "Apartment";
    }
    else if (auto commercial = dynamic_cast<const Commercial*>(property)) {
        propertyType = "Commercial";
    }
    else if (auto house = dynamic_cast<const House*>(property)) {
        propertyType = "House";
    }

    // basic info
    file << propertyType << ","
        << property->getPropertyID() << ","
        << property->getCity() << ","
        << property->getState() << ","
        << property->getPrice();

    // add info based on prop type
    if (auto apartment = dynamic_cast<const Apartment*>(property)) {
        file << "," << apartment->getFloorLevel()
            << "," << apartment->getRoomNum()
            << "," << apartment->getRent() << "\n";
    }
    else if (auto commercial = dynamic_cast<const Commercial*>(property)) {
        file << "," << commercial->getParkingSpots() << "\n";
    }
    else if (auto house = dynamic_cast<const House*>(property)) {
        file << "," << house->getNumBedrooms()
            << "," << house->getNumBathrooms() << "\n";
    }
}

