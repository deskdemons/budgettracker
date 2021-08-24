#include "user.h"

// sets data for user object
void User::setData(std::string u, std::string f, int i, float b){
    username = u;
    fullname = f;
    balance = b;
    userId = i;
}