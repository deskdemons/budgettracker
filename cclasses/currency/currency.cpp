#include<iostream>
#include "currency.h"
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
Currency::Currency(){
    curType="NPR";
    nrsEqRate=1.0;
}

void insertCsv(std::vector<std::vector<std::string> > &csvRates){
    std::ifstream myFile;
    myFile.open("curRate.csv");
    std::vector<std::string> row;
    csvRates.clear();
    while(myFile.good()){
        row.clear();
        std::string line;
        std::string word;
        std::getline(myFile, line);
        std::stringstream s(line);
        while(std::getline(s,word,',')){
            row.push_back(word);
        }
        csvRates.push_back(row);
    }
}
double strToDou(std::string s){
    std::stringstream st(s);
    double x = 0;
    st >> x;
    return x;
}
void insertCsv(std::vector<std::string> &curName){
    std::ifstream myFile;
    myFile.open("curRate.csv");
    curName.clear();
    while(myFile.good()){
        std::string line;
        std::string word;
        std::getline(myFile, line);
        std::stringstream s(line);
        int k=0;
        while(std::getline(s,word,',')){
            if(k==0)
                curName.push_back(word);
                k++;
        }
    }
}

std::vector<std::string> Currency:: namesCurr(){
    std::vector<std::string> currName;
    insertCsv(currName);
    return currName;
}
bool Currency::isValidCurType(std::string curTyp){
    std::vector<std::string> currNames = namesCurr();
    int count=0;
    for(int k=0; k<currNames.size();k++){
        if(curTyp==currNames[k]){
            count++;
        }
    }
    if(count==0){
        return false;
    }else{
        return true;
    }
}

Currency::Currency(std::string typ){
    std::vector<std::vector<std::string> > csvRates;
    insertCsv(csvRates);
    
    if(!Currency::isValidCurType(typ)){
        std::string err="invalid currency name "+ typ;
        throw err;
    }

    curType=typ;
    std::vector< std::vector<std::string> >::iterator rows;
    std::vector<std::string>::iterator cols;
    int index=0;
    int position=0;
    for (rows = csvRates.begin(); rows != csvRates.end(); rows++) {
        for (cols = rows->begin(); cols != rows->end(); cols++) {
            if(typ==cols[0]){
                position = index;
                break;
            }
            
        }
        index++;
    }

    nrsEqRate= strToDou(csvRates[position][1]);

}

std::string Currency::getCurType(){
    return curType;
}