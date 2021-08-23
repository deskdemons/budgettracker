#include "currencyExchange.h"
#include <sstream>
#include <istream>
#include <fstream>
#include "../users/csvfile/CSVFile.h"

currencyExchange::currencyExchange() {
    CSVFile file("curRate.csv");// CSVFile object from CSVFile class so no custom file handler required
    info = file.parse_csv("curRate.csv");//gets all exchange rates from csv file
    fileExistanceAssert();
//  std::cout<<"constructor called\n";
//    for (int i = 0; i < info.size(); ++i) {
//        for (int j = 0; j < 2; ++j) {
//            std::cout<<"\n "<<info[i][j];
//        }
//    }
}

// it returns the exchanged value when all data are provided
float currencyExchange::currencyConverter(float val, std::string fromCur, std::string toCur) {
    float fromRate, toRate, nepVal;
    initialValue = val;
    fromRate = getRate(fromCur);
    toRate = getRate(toCur);
    nepVal = val/fromRate;   //temp NPR value to ease in exchanging
    converted = nepVal * toRate;
    //std::cout<<"fromRate "<<fromRate<<"\ntorate "<<toRate<<"\nnepVal "<<nepVal<<std::endl;
    return converted;
}

//It returns rate of the required 2 currencies compared to NPR
float currencyExchange::getRate(std::string name) {
    float fromRate,toRate;
    for (int i = 0; i < info.size(); ++i) {
        if (name == info[i][0]){
            std::string temp = info[i][1];
            std::stringstream st(temp);
            float x = 0.0;
            st >> x;
            return x;
        }
    }
    return 0;
}

// makes file and add data if needed
bool currencyExchange::fileExistanceAssert()  {
    {
        const char *fname = "curRate.csv";

        std::fstream fs;
        fs.open(fname, std::ios::in);

        if (!fs)
        {
            // File doesnot exist
            //Create a file
            std::ofstream fout(fname);
            if (fout)
            {
                // If the creation is successful
                fout << "NPR,1\n"
                        "USD,0.0084\n"
                        "INR,0.625\n"
                        "AUD,0.011\n"
                        "EUR,0.0071\n"
                        "SKW,9.89\n"
                        "JPY,0.92";

                // Close the file handle after performing the operation
                fout.close();
            }
            return false;
        }
        else
        {
            return true;
        }
    }
}