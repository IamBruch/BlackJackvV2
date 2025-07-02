//
// Created by Ryzen on 2. 7. 2025.
//

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>

class DataManager {
public:
    bool registerUser(const std::string& name, const std::string& password);
    bool loginUser(const std::string& name, const std::string& password, int& score);
    bool updateScore(const std::string& name, int newScore);
};



#endif //DATAMANAGER_H
