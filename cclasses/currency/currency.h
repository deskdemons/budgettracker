#ifndef CURRENCY_H
#define CURRENCY_H
#include<iostream>
class Currency{
    
    public:
        std::string curType;    // USD, NPR, etc
        double nrsEqRate;   //equivalent rate wrt NPR. for ex: for USD, nrsEqRate = 0.0084
        Currency(); //default constructor with curType NPR and nrsEqRate = 1
        Currency(std::string typ);  //pass string like USD, and it will construct object and automatically assign the nrsEqValue
        std::string getCurType(); //returns string example: USD
};

#endif