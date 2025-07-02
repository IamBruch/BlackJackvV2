//
// Created by Ryzen on 2. 7. 2025.
//

#include "DataManager.h"

#include <fstream>
#include <sstream>
#include <vector>

const std::string DATA_FILE = "users.txt";

bool DataManager::registerUser(const std::string& name, const std::string& password) {
    std::ifstream infile(DATA_FILE);
    std::string line, uname, upass;
    int userScore;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (iss >> uname >> upass >> userScore) {
            if (uname == name) return false; // user exists
        }
    }
    infile.close();

    std::ofstream outfile(DATA_FILE, std::ios::app);
    outfile << name << " " << password << " 100\n";
    return true;
}

bool DataManager::loginUser(const std::string& name, const std::string& password, int& score) {
    std::ifstream infile(DATA_FILE);
    std::string line, userName, userPass;
    int userScore;
    while (std::getline(infile, line)) {

        std::istringstream iss(line);
        if (iss >> userName >> userPass >> userScore) {

            if (userName == name && userPass == password) {

                score = userScore;
                return true;

            }

        }

    }

    return false;
}

bool DataManager::updateScore(const std::string& name, int newScore) {
    std::ifstream infile(DATA_FILE);
    std::vector<std::string> lines;
    std::string line, userName, userPass;
    int userScore;
    bool updated = false;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (iss >> userName >> userPass >> userScore) {
            if (userName == name) {
                std::ostringstream oss;
                oss << uname << " " << userPass << " " << newScore;
                lines.push_back(oss.str());
                updated = true;
            } else {
                lines.push_back(line);
            }
        }
    }

    infile.close();

    if (updated) {
        std::ofstream outfile(DATA_FILE, std::ios::trunc);
        for (const auto& l : lines) {
            outfile << l << std::endl;
        }
    }
    return updated;
}