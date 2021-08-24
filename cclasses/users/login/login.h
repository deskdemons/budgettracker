#ifndef BUDGETTRACKER_LOGIN_H
#define BUDGETTRACKER_LOGIN_H

#include <iostream>
#include "../user.h"

class Login
{
public:
    std::string username, password,fullname;
    User u1;
    bool isGen;
    int userId;
    float balance;
    int strToInt(std::string);
    float strToFloat(std::string);
    Login(std::string,std::string);
    Login();
    bool fileExsistanceAssert();
    User returnUserObject();

protected:

private:
    void setupass(std::string, std::string);
    void getData(std::string);
};


#endif //BUDGETTRACKER_LOGIN_H
