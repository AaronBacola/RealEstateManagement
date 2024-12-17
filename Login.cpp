#include <iostream>
#include <fstream>
#include <string>
#include "login.h"
using namespace std;

bool login(string& userRole) {
    ifstream file("credentials.txt");
    if (!file) {
        cerr << "Error: Unable to open credentials file.\n";
        return false;
    }

    string username, password, role, fileUsername, filePassword, fileRole;
    cout << "\n===== Login =====\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    string line;
    while (getline(file, line)) {
        size_t commaPos1 = line.find(',');
        size_t commaPos2 = line.find(',', commaPos1 + 1);
        if (commaPos1 != string::npos && commaPos2 != string::npos) {
            fileUsername = line.substr(0, commaPos1);
            filePassword = line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
            fileRole = line.substr(commaPos2 + 1);
            if (username == fileUsername && password == filePassword) {
                userRole = fileRole;  
                cout << "Login successful!\n";
                file.close();
                return true;
            }
        }
    }

    cout << "Invalid username or password.\n";
    file.close();
    return false;
}

void registerUser() {
    ofstream file("credentials.txt", ios::app); 
    if (!file) {
        cerr << "Error: Unable to open credentials file.\n";
        return;
    }

    string username, password, role;
    cout << "\n===== Register =====\n";
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;
    cout << "Enter role (Agent/Customer): ";
    cin >> role;

    if (role != "Agent" && role != "Customer") {
        cout << "Invalid role. Please choose 'Agent' or 'Customer'.\n";
        return;
    }

    file << username << "," << password << "," << role << "\n";
    file.close();
    cout << "User registered successfully as " << role << "!\n";
}
