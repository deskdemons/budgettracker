#ifndef BUDGETTRACKER_LOGIN_H
#define BUDGETTRACKER_LOGIN_H

#include <iostream>
#include "../user.h"

class Login
{
public:
    std::string username, password,fullname;
    int userId,balance;
    int strToInt(std::string);
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
