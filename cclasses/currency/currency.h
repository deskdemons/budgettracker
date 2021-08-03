#ifndef CURRENCY_H
#define CURRENCY_H
#include<iostream>
#include<vector>

class Currency{
    
    public:
        std::string curType;    // USD, NPR, etc
        double nrsEqRate;   //equivalent rate wrt NPR. for ex: for USD, nrsEqRate = 0.0084
        Currency(); //default constructor with curType NPR and nrsEqRate = 1
        Currency(std::string typ);  //pass string like USD, and it will construct object and automatically assign the nrsEqValue
        std::string getCurType();   //returns curType as string like: "USD"
        std::vector<std::string> namesCurr();   //returns vector of string of available currency Type like: {"NPR",USD","INR","AUD","EUR"}
        bool isValidCurType(std::string curTyp);  //created for internal use only //returns true or false based on passed curType(like USD) exists inside csv file or not
};

#endif