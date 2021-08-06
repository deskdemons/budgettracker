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
    if(typ != "e" && typ != "i"){
        std::string err = "only e or i is allowed as type";
        throw err;
    }
    if(val <0){
        std::string err = "negative value not allowed";
        throw err;
    }
    value=val;
    currency=cur;
    type=typ;
    nrsEqAmt=value/cur.nrsEqRate;
}
std::string doubleToString(double num){
    std::stringstream ss;
    std::string str;
    ss<<num;
    ss>>str;
    return str;
}

bool is_a_number(std::string s)
{
    for (int i = 0; i < s.length(); i++)
        
        if (isdigit(s[i]) == false){
            if(s[0]=='-' || s[0]=='+' || s[i]=='.'){
                continue;
            }
            return false;
        }
    return true;
}
double stringToDouble(std::string s){
    std::stringstream st(s);
    double x = 0;
    st >> x;
    return x;
}
std::string Money::getMoney(){
    return currency.curType+"["+doubleToString(value)+"]"+type;
}
void Money::deserialize(const std::string& moneyStr){
    int strLen = moneyStr.length();
    int lenStrMon = strLen-6;
    std::string moneyVal = moneyStr.substr(4,lenStrMon);

    if(!is_a_number(moneyVal)){
        std::string err = "not a valid double number";
        throw err;
    }
    double monVal= stringToDouble(moneyVal);
    std::string typ = moneyStr.substr(strLen - 1,1);
    std::string curTyp = moneyStr.substr(0,3);
    if(monVal<0){
        std::string err = "negative value not allowed";
        throw err;
    }
    if(typ !="e" && typ != "i"){
        std::string err = "only e or i is allowed as type";
        throw err;
    }

    Currency c(curTyp); //if curType passed in deserializer is invalid, then the throwing mechanism inside Currency throw error here and again it automatically throws error in deserliazser call point. just like multiple levels of throwing
    value=monVal;
    type = typ;
    currency = c;
    nrsEqAmt = value/c.nrsEqRate;
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