#ifndef VECTORCURRENCY_H
#define VECTORCURRENCY_H
#include<iostream>
#include "currency.h"
#include<vector>

class VectorCurrency{
    std::vector<Currency> allCurrency;
    std::vector<std::string> currencyNames;
    public:
        VectorCurrency();
        std::vector<Currency> getAll(); //returns vector of currency of available currency inside csv file
};

#endif