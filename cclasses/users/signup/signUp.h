//
// Created by paudelrajeev58 on 8/9/21.
//

#ifndef BUDGETTRACKER_SIGNUP_H
#define BUDGETTRACKER_SIGNUP_H
#include <string>

class Signup {
public:
    Signup(std::string,std::string,std::string);
    Signup();
private:
    std::string username, password, fullname;
    bool setdata();
    std::string encryptfunc(std::string text);
    bool addDataToCsv(std::string,std::string,std::string);
    bool fileExsistanceAssert();
    int numOfUsers();
    bool isUsernameValid(std::string);
};


#endif //BUDGETTRACKER_SIGNUP_H
