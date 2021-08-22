#include "authentication.h"
#include <vector>
#include "../csvfile/CSVFile.h"
#include <iostream>

// function to check if the login info provided is authentic or not
bool Authentication::isGenuine(std::string uname, std::string pass){
    std::vector<std::vector < std::string > > vecData;
    std::string encry ;
    int x;
    encry = encryptFunc(pass);
    CSVFile cs1("secretdata.csv");
    vecData = cs1.parse_csv("secretdata.csv"); //gets all login info from the file
    for (int i = 1; i < vecData.size(); i++)
    {
        if (vecData[i][1] == uname && vecData[i][2] == encry){
            x=1;
            break;
        }
        else
        {
            x=0;

        }
    }
    if (x==1){
        return true;
    }
    return false;
}

//function to encrypt the password entered by user by passing as an argument
std::string Authentication::encryptFunc(std::string text){
    char temp;
    int i;
    for(i = 0; text[i] != '\0'; ++i){
        temp = text[i];
        if(temp >= 'a' && temp <= 'z'){
            temp += 5;

            if(temp < 'a'){
                temp = temp + 'z' + 'a' - 1;
            }

            text[i] = temp;
        }
        else if(temp >= 'A' && temp <= 'Z'){
            temp += 5;

            if(temp < 'A'){
                temp = temp + 'Z' + 'A' - 1;
            }

            text[i] = temp;
        }
    }
    return text;

}
