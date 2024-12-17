#include <iostream>
#include <string>
#include <limits>
#include "login.h"
#include <fstream>
#include "Agent.h"
#include "Apartment.h"
#include "Commercial.h"
#include "House.h"
#include "Customer.h"
#include "Property.h"
#include "User.h"

using namespace std;

void showAgentMenu(Agent& currentAgent, user& currentUser, bool& exit) {
    int choice;
    bool continueMenu = true;

    while (continueMenu) {
        cout << "\n===== Real Estate Management System (Agent) =====\n";
        cout << "1. Add Property\n";
        cout << "2. Remove Property\n";
        cout << "3. Modify Property\n";
        cout << "4. View Properties\n";
        cout << "5. Search Properties\n";
        cout << "6. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            currentAgent.addProperty();
            break;
        case 2:
            currentAgent.removeProperty();
            break;
        case 3:
            currentAgent.modifyProperty();
            break;
        case 4:
            currentUser.viewPropertyDetails();
            break;
        case 5:
            currentUser.searchProperties();
            break;
        case 6:
            cout << "Logging out...\n";
            continueMenu = false;  // exit agent
            exit = true;           // exit main loop
            break;
        default:
            cout << "Invalid option\n";
            break;
        }
    }
}

void showCustomerMenu(Customer& currentCustomer, user& currentUser, bool& exit) {
    int choice;
    bool continueMenu = true;

    while (continueMenu) {
        cout << "\n===== Real Estate Management System (Customer) =====\n";
        cout << "1. View Properties\n";
        cout << "2. Search Properties\n";
        cout << "3. Reserve Property\n";
        cout << "4. View Reserved Properties\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            currentUser.viewPropertyDetails();
            break;
        case 2:
            currentUser.searchProperties();
            break;
        case 3:
            currentCustomer.reserveProperty();
            break;
        case 4:
            currentCustomer.printReservedProperties();
            break;
        case 5:
            cout << "Logging out...\n";
            continueMenu = false;  // exit customer
			exit = true;           // exit main loop
            break;
        default:
            cout << "Invalid option\n";
            break;
        }
    }
}

int main() {
    bool programRunning = true;

    while (programRunning) {
        int initialChoice;

        cout << "\n===== Welcome to the Real Estate Management System =====\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> initialChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        switch (initialChoice) {
        case 1: {
            string userRole;
            if (!login(userRole)) {
                cout << "Exiting program due to failed login.\n";
                continue;
            }

			// main menu for logged-in user
            bool exit = false;
            Agent currentAgent;     // create agent obj for user
			Customer currentCustomer;  // create customer obj for user
            user currentUser;

            // show corresponding menu  
            while (!exit) {
                if (userRole == "Agent") {
                    showAgentMenu(currentAgent, currentUser, exit);
                }
                else if (userRole == "Customer") {
                    showCustomerMenu(currentCustomer, currentUser, exit);
                }
            }
            break;
        }
        case 2:
            registerUser();
            break;
        case 3:
            cout << "Exiting the program. Thank you!\n";
            programRunning = false;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
