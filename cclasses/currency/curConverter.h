#ifndef CURCONVERTER_H
#define CURCONVERTER_H
#include<iostream>

class CurConverter{
    protected:
        std::string from, to;
        double initialValue;
        double converted;
    public:
        void currencyConverter(double val, std::string fromCur, std::string toCur);
        std::string getConverted();
};

#endif