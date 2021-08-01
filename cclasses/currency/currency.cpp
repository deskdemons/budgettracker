#include<iostream>
#include "currency.h"
#include <sstream>

bool currCheck(std::string type){
    std::string curr[]={"npr","usd","inr","aud"};
    for(int i=0; i<sizeof(curr)/sizeof(curr[0]); i++){
        if(type==curr[i])
            return true;
    }
    return false;
}
std::string doubleToString(double num){
    std::stringstream ss;
    std::string str;
    ss<<num;
    ss>>str;
    return str;
}
Currency::Currency(){
    value = 0.0;
    type = "npr";
}

bool Currency::setCurrency(double val, std::string typ){
    if(currCheck(typ) && val>=0){
        value = val;
        type = typ;
        currencyConverter(val, typ, "npr");
        nrsEq = converted;
        return true;
    }else 
        return false;
}

std::string Currency::getCurrency(){
    return type+ "[" + doubleToString(value) +"]";
}

void Currency::deserialize(std::string curStr){
    std::string typ = curStr.substr(0,3);
    int lenStr = curStr.length()-5;
    double curr = std::stod(curStr.substr(4,lenStr));
    value=curr;
    type=curStr;
}