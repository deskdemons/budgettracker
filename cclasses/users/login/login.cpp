#include "login.h"
#include<vector>
#include<sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include "../csvfile/CSVFile.h"
#include "../authentication/authentication.h"
#include "../user.h"

//Login::Login()
//{
//    fileExsistanceAssert();
//    std::string uname,pass;
//    std::cout<<"For Login";
//    std::cout<<"\nUsername: ";
//    std::cin>>uname;
//    std::cout<<"Password: ";
//    std::cin>> pass;
//    bool isGen;
//    Authentication a;
//    std::string encryptedPassword;
//    isGen = a.isGenuine(uname,pass);
//    if(isGen == true){
//        setupass(uname,pass);
//        getData(uname);
//        User u = returnUserObject();
//        std::cout<<"\nUser's username = "<<username;
//        std::cout<<"\nUser's Fullname = "<<fullname;
//        std::cout<<"\nUser's UserID = "<<userId;
//        std::cout<<"\nUser's Balance = "<<balance;
//    }
//    else{
//        std::cout<<"wrong credentials please try again";
//        Login l;
//    }
//}

// when username and password is passed it checks by calling functions
Login::Login(std::string u,std::string p)
{
    fileExsistanceAssert();
    std::string uname,pass;
    uname = u;
    pass = p;
    Authentication a;
    std::string encryptedPassword;
    isGen = a.isGenuine(uname,pass);
    if(isGen){
        std::cout<<"right";
        setupass(uname,pass);
        getData(uname);
        u1 = returnUserObject();
        std::cout<<"\nUser's username = "<<username;
        std::cout<<"\nUser's Fullname = "<<fullname;
        std::cout<<"\nUser's UserID = "<<userId;
        std::cout<<"\nUser's Balance = "<<balance;
    }
    else{
        std::cout<<"wrong credentials please try again";
        //Login l;
    }
}

// gets all the data from csv for authenticating
void Login::getData(std::string username){
    std::vector<std::vector < std::string > > vecData;
    std::string encry ;
    int x;
    CSVFile cs1("secretdata.csv");
    vecData = cs1.parse_csv("secretdata.csv");
    for (int i = 1; i < vecData.size(); i++)
    {
        if (vecData[i][1] == username ){
            x=1;
            username = vecData[i][1];
            fullname = vecData[i][3];
            std::string temp = vecData[i][0];
            userId = strToInt(temp);
            std::string money = vecData[i][4];
            balance = strToFloat(money);
            break;
        }
    }

}

//checks if file exists or not
bool Login::fileExsistanceAssert()
{
    const char *fname = "secretdata.csv";

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
            fout << "#id,username,password,fullname,balance";

            // Close the file handle after performing the operation
            fout.close();
        }
        return false;
    }
    else
    {
        return true;
    }
};

// changes string to int
int Login::strToInt(std::string s){
    std::stringstream st(s);
    int x = 0;
    st >> x;
    return x;
}

float Login::strToFloat(std::string r) {
    std::stringstream st(r);
    float x = 0.0;
    st >> x;
    return x;
}

// sets username and password to the object which are data members
void Login::setupass(std::string uname,std::string pass){
    username= uname;
    password=pass;
}

// returns user object by retrieving all the data
User Login::returnUserObject(){
    User x;
    x.setData(username,fullname,userId,balance);
    return x;
}

