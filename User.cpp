#include "User.h"
#include "Apartment.h"
#include "Commercial.h"
#include "House.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void user::propDetails(const string& line, unique_ptr<Property>& property) {
    stringstream ss(line);
    string type, propertyID, city, state, price, value1, value2, value3;

    getline(ss, type, ',');
    getline(ss, propertyID, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    getline(ss, price, ',');
    getline(ss, value1, ',');
    getline(ss, value2, ',');
    ss >> value3;

    // conv price to int
    int priceInt = stoi(price); 

    if (type == "Apartment") {
        int floor, roomNum, rentingPrice;
        if (!(ss >> floor >> roomNum >> rentingPrice)) {
            cerr << "Error: Malformed apartment data in line: " << line << endl;
            return;
        }
        property = make_unique<Apartment>(propertyID, city, state, priceInt, floor, roomNum, rentingPrice);
    }
    else if (type == "Commercial") {
        int parkingSpots;
        if (!(ss >> parkingSpots)) {
            cerr << "Error: Malformed commercial data in line: " << line << endl;
            return;
        }
        property = make_unique<Commercial>(propertyID, city, state, priceInt, parkingSpots);
    }
    else if (type == "House") {
        int numBedrooms, numBathrooms;
        if (!(ss >> numBedrooms >> numBathrooms)) {
            cerr << "Error: Malformed house data in line: " << line << endl;
            return;
        }
        property = make_unique<House>(propertyID, city, state, priceInt, numBedrooms, numBathrooms);
    }
    else {
        cerr << "Error: Unknown property type in line: " << line << endl;
    }
}




void user::searchProperties() {
    ifstream file("properties.txt");
    if (!file) {
        cerr << "Error: Unable to open properties file.\n";
        return;
    }

    string searchCity, searchState;
    int maxPrice;

	// ask for criteria
    cout << "\n===== Search Properties =====\n";
    cout << "Enter City: ";
    cin >> searchCity;
    cout << "Enter State: ";
    cin >> searchState;
    cout << "Enter Max Price: ";
    cin >> maxPrice;

    string line;
    bool found = false;

    // read line by line
    while (getline(file, line)) {
        stringstream ss(line);
        string type, propertyID, city, state;
        int price;

        // parse data
        getline(ss, type, ',');
        getline(ss, propertyID, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        ss >> price;

		// check if prop matches criteria
        if (city == searchCity && state == searchState && price <= maxPrice) {
            found = true;
            cout << "\nProperty Found:\n";
            cout << "Property ID: " << propertyID << "\n";
            cout << "City: " << city << ", State: " << state << "\n";
            cout << "Price: $" << price << "\n";

			// additional details based on prop type
            if (type == "Apartment") {
                int floorLevel, roomNum, rent;
                if (ss >> floorLevel >> roomNum >> rent) {
                    cout << "Floor Level: " << floorLevel << "\n";
                    cout << "Room Number: " << roomNum << "\n";
                    cout << "Rent: $" << rent << "\n";
                }
            }
            else if (type == "Commercial") {
                int parkingSpots;
                if (ss >> parkingSpots) {
                    cout << "Parking Spots: " << parkingSpots << "\n";
                }
            }
            else if (type == "House") {
                int bedrooms, bathrooms;
                if (ss >> bedrooms >> bathrooms) {
                    cout << "Number of Bedrooms: " << bedrooms << "\n";
                    cout << "Number of Bathrooms: " << bathrooms << "\n";
                }
            }
            else {
                cerr << "Error: Unknown property type in file.\n";
            }
        }
    }

    if (!found) {
        cout << "No properties found based on your search criteria.\n";
    }

    file.close();
}


void user::viewPropertyDetails() {
    string inputPropertyID;
    cout << "Enter Property ID to search: ";
    cin >> inputPropertyID;

    ifstream file("properties.txt");
    if (!file) {
        cerr << "Error: Unable to open properties file.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string type, propertyID, city, state, price, value1, value2, value3;

        // parse line
        getline(ss, type, ',');
        getline(ss, propertyID, ','); 
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, price, ',');
        getline(ss, value1, ',');
        getline(ss, value2, ',');
        ss >> value3;

		// check if id matches
        if (propertyID == inputPropertyID) {
            found = true;
            cout << "Property Found:\n";

            // display data
            cout << "Property Type: " << type << "\n";
            cout << "Property ID: " << propertyID << "\n";
            cout << "City: " << city << "\n";
            cout << "State: " << state << "\n";
            cout << "Price: $" << price << "\n";

			// additional data based on prop type
            if (type == "Apartment") {
                cout << "Floor Level: " << value1 << "\n";
                cout << "Room Number: " << value2 << "\n";
                cout << "Renting Price: " << value3 << "\n";
            }
            else if (type == "Commercial") {
                cout << "Parking Spots: " << value1 << "\n";
            }
            else if (type == "House") {
                cout << "Number of Bedrooms: " << value1 << "\n";
                cout << "Number of Bathrooms: " << value2 << "\n";
            }
            else {
                cerr << "Error: Unknown property type in file.\n";
            }

            break;
        }
    }

    if (!found) {
        cout << "Property not found.\n";
    }

    file.close();
}











