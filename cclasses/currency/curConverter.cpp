#include<iostream>
#include "curConverter.h"


int currIndex(std::string curType){
    std::string curr[]={"npr","usd","inr","aud"};
    int index=0;
    for(int i=0; i<sizeof(curr)/sizeof(curr[0]); i++){
            if(curType==curr[i])
                index = i;
    }
    return index;
}

double convRate(std::string from, std::string to){   
    double rates[] = {1, 0.0084, 0.63, 0.011};//npr,usd,inr,aud
    double fromR = rates[currIndex(from)];
    double toR = rates[currIndex(to)];
    return toR/fromR;
}

void CurConverter::currencyConverter(double val, std::string fromCur, std::string toCur){
    initialValue = val;
    from = fromCur;
    to = toCur;
    double rate = convRate(fromCur, toCur);
    converted = val*rate;
}

