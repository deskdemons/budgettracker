#ifndef VECTORCURRENCY_H
#define VECTORCURRENCY_H
#include<iostream>
#include "currency.h"
#include<vector>

class VectorCurrency{
    
    std::vector<Currency> allCurrency;
    public:
        VectorCurrency();   //default constructor. whenever object is made, then csv file is read and stored in a vector. and vector of currency is made
        std::vector<Currency> getAll(); //returns vector of currency
};

#endif