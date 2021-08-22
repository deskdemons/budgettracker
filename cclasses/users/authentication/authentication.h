#ifndef BUDGETTRACKER_AUTHENTICATION_H
#define BUDGETTRACKER_AUTHENTICATION_H
#include <string>

class Authentication {
public:
    bool isGenuine(std::string, std::string);
    std::string encryptFunc(std::string text);
};


#endif //BUDGETTRACKER_AUTHENTICATION_H
