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
        std::string getCurrency();  //returns string as serialized string like NPR[55.67]
        void deserialize(std::string curStr);
};

#endif