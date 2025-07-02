//
// Created by Ryzen on 2. 7. 2025.
//

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>

class DataManager {
    bool newUser = false;
public:
    void login();
    bool findUser(const std::string& name, std::string& password, int& score);
};



#endif //DATAMANAGER_H
