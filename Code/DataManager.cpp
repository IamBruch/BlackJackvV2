//
// Created by Ryzen on 2. 7. 2025.
//

#include "DataManager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

const std::string DATA_FILE = "users.txt";

void DataManager::login() {
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;

    std::string storedPassword;
    int score = 0;

    if (!findUser(name, storedPassword, score)) {
        std::cout << "No user found with the name '" << name << "' Registration will proceed. " << std::endl;
        newUser = true;
    }

    if (newUser) {
        std::cout << "Enter a password for registration: ";
        std::string newPassword;
        std::cin >> newPassword;

        std::ofstream outfile("Code/PlayerData.txt", std::ios::app);
        outfile << name << " " << newPassword << " 100\n";
        std::cout << "Registration successful! You can now log in.\n";
        storedPassword = newPassword;
        score = 100;
        newUser = false;
        return;
    }

    bool isLoggedIn = false;
    while (!isLoggedIn) {
        std::cout << "Enter your password: ";
        std::string inputPassword;
        std::cin >> inputPassword;
        if (storedPassword != inputPassword) {
            std::cout << "Incorrect password. Please try again." << std::endl;
        } else {
            std::cout << "Login successful!" << std::endl;
            isLoggedIn = true;
        }
    }
}

bool DataManager::findUser(const std::string& name, std::string& password, int& score) {
    std::ifstream infile("Code/PlayerData.txt");
    std::string line, uname, upass;
    int uscore;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (iss >> uname >> upass >> uscore) {
            if (uname == name) {
                password = upass;
                score = uscore;
                return true;
            }
        }
    }

    return false;
}
