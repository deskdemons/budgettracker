#include<iostream>
#include "money.h"
#include <sstream>
Money::Money(){
    value=0.0;
    type="e";
    nrsEqAmt=1.0;
    Currency c0;
    currency= c0;
}

void Money::setMoney(double val, Currency cur, std::string typ){
    value=val;
    currency=cur;
    type=typ;
    nrsEqAmt=value*cur.nrsEqRate;
}
std::string doubleToString(double num){
    std::stringstream ss;
    std::string str;
    ss<<num;
    ss>>str;
    return str;
}
std::string Money::getMoney(){
    return currency.curType+"["+doubleToString(value)+"]"+type;
}
void Money::deserialize(std::string moneyStr){
    int strLen = moneyStr.length();
    int lenStrMon = strLen-6;
    double monVal= std::stod(moneyStr.substr(4,lenStrMon));
    std::string typ = moneyStr.substr(strLen - 1,1);
    std::string curTyp = moneyStr.substr(0,3);
    Currency c(curTyp);

    value=monVal;
    type = typ;
    currency = c;
    nrsEqAmt = value*c.nrsEqRate;
}

bool Money::operator < (Money obj){
    if(nrsEqAmt < obj.nrsEqAmt)
        return true;
    else
        return false;
}
bool Money::operator > (Money obj){
    if(nrsEqAmt > obj.nrsEqAmt)
        return true;
    else
        return false;
}
bool Money::operator == (Money obj){
    if(nrsEqAmt == obj.nrsEqAmt)
        return true;
    else
        return false;
}
bool Money::operator <= (Money obj){
    if(nrsEqAmt <= obj.nrsEqAmt)
        return true;
    else
        return false;
}
bool Money::operator >= (Money obj){
    if(nrsEqAmt >= obj.nrsEqAmt)
        return true;
    else
        return false;
}
bool Money::operator != (Money obj){
    if(nrsEqAmt != obj.nrsEqAmt)
        return true;
    else
        return false;
}