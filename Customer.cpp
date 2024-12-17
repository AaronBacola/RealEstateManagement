#include "Customer.h"
#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

// reserve prop
void Customer::reserveProperty() {
    ofstream file("reservations.txt", ios::app);
    if (!file) {
        cerr << "Error: Unable to open reservations file.\n";
        return;
    }

    string propertyID, customerID;
    cout << "\n===== Reserve Property =====\n";
    cout << "Enter Property ID: ";
    cin >> propertyID;
    cout << "Enter Customer ID: ";
    cin >> customerID;

    file << "Customer ID: " << customerID << ", Property ID: " << propertyID << endl;
    cout << "Property reserved successfully!\n";

    file.close();
}

// display reserved propereties
void Customer::printReservedProperties() {
	ifstream file("reservations.txt");
	if (!file) {
		cerr << "Error: Unable to open reservations file.\n";
		return;
	}

	cout << "\n===== Reservations =====\n";
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	file.close();
}



