#include "vectorCurrency.h"
#include<vector>

VectorCurrency::VectorCurrency() {
    Currency c0;
    currencyNames = c0.namesCurr();
    std::vector<Currency> curVec;
    for (int i = 0; i < currencyNames.size(); i++) {
        Currency c(currencyNames[i]);
        curVec.push_back(c);
    }
    allCurrency = curVec;
}

std::vector<Currency> VectorCurrency::getAll() {
    return allCurrency;
}
