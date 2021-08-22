#ifndef BUDGETTRACKER_USER_H
#define BUDGETTRACKER_USER_H
#include <string>

class User {
private:
    std::string username,fullname;
    int userId,balance;
public:
    void setData(std::string,std::string,int,int);
};


#endif //BUDGETTRACKER_USER_H
