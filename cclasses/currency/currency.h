#ifndef CURRENCY_H
#define CURRENCY_H
#include<iostream>
#include "curConverter.h"
class Currency: protected CurConverter{
    double nrsEq;
    double value;
    std::string type;
    public:
        Currency(); //default constructor, when object is made, value =0, type = npr
        bool setCurrency(double val, std::string typ);  //sets currency example c1.setCurrency(55,"npr")
        std::string getCurrency();  //returns string as serialized string like npr[55.67]
        void deserialize(std::string curStr); //pass string like USD[150.55] and it will save value=150.55 and type="USD"
        //we have inherited currencyConverter. c1.currencyConverter(55.54, from, "npr") is used internally to store equivalent npr of any currency for comparision purposes
};

#endif