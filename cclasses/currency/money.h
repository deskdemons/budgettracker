#ifndef MONEY_H
#define MONEY_H
#include<iostream>
#include "currency.h"

class Money{
    std::string type; //expense or income
    Currency currency;
    double value;
    double nrsEqAmt;
    public:
        Money();    //deafult constructor with value =0.0, type="e", nrsEqAmt = 1, and deafult currency object(which is curType="NRS" and nrsEqRate =1)
        void setMoney(double val, Currency cur, std::string typ);// this method sets example: m1.setMoney(1500, c1, "e"), where e for expense, c1 may have curType = "USD", nrsEqRate = 0.0084 
        std::string getMoney(); //USD[56.44]e , where e is for expense, and i for income
        void deserialize(std::string moneyStr); //pass string like NPR[45.33]e and it will make deserialize
        bool operator < (Money obj);    // if m1<m2 is true, then it will return true as bool and so on
        bool operator > (Money obj);
        bool operator == (Money obj);
        bool operator <= (Money obj);
        bool operator >= (Money obj);
        bool operator != (Money obj);
};

#endif