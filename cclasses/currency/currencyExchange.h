#ifndef CURRENCYEXCHANGE_H
#define CURRENCYEXCHANGE_H

#include <iostream>
#include "../users/csvfile/CSVFile.h"

class currencyExchange {
protected:
    std::string from, to;
    float rate;
    float initialValue;
    float converted;//final value
    std::vector<std::vector<std::string> > info;// it stores all the rate from the csv file to process further
public:
    currencyExchange();

    float currencyConverter(float val, std::string fromCur, std::string toCur);

    float getRate(std::string);// returns the exchange rate compared to NPR
    bool fileExistanceAssert();// adds curRate.csv if not found in the file
};


#endif //   CURRENCYEXCHANGE_H
