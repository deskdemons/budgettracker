#include<iostream>
#include "currency.h"
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
Currency::Currency(){
    curType="NRS";
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

Currency::Currency(std::string typ){
    std::vector<std::vector<std::string> > csvRates;
    insertCsv(csvRates);

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