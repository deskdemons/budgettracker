#include<iostream>
#include "currency.h"
#include<vector>

Currency::Currency(){
    curType="NRS";
    nrsEqRate=1.0;
}

Currency::Currency(std::string typ){
    /* std::vector<std::string> CurType;
    std::vector<double> CurNrsEq; */
    std::string CurType[] = {"NPR", "USD", "INR", "AUD"};
    double CurNrsEq[]={1, 0.0084, 0.63, 0.011};
    curType=typ;
    nrsEqRate=CurNrsEq[1];//temporary code
}