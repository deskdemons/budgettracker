#ifndef BUDGETTRACKER_USER_H
#define BUDGETTRACKER_USER_H
#include <string>

class User {
private:

public:
    std::string username,fullname;
    int userId;
    float balance;
    void setData(std::string,std::string,int,float );
};


#endif //BUDGETTRACKER_USER_H
