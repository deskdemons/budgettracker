#include "vectorCurrency.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>

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

VectorCurrency::VectorCurrency(){
    std::vector<std::string> curName;
    insertCsv(curName);
    std::vector<Currency> curVec;
    for(int i=0; i<curName.size();i++){
        Currency c(curName[i]);
        curVec.push_back(c);
    }
    allCurrency = curVec;
}

std::vector<Currency> VectorCurrency::getAll(){
    return allCurrency;
}
