//
// Created by paudelrajeev58 on 8/9/21.
//
#include "signUp.h"
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <sstream>
#include<vector>
#include "../login/login.h"
#include "../csvfile/CSVFile.h"

Signup::Signup(std::string u ,std::string p,std::string f):username(u),password(p),fullname(f)
{
    fileExsistanceAssert();
    bool valid = isUsernameValid(username);
    if (valid){
        addDataToCsv(username,password,fullname);
        Login l;
    }
    else{
        std::cout<<"\nPlease Try Different Username.\n\n";
        Signup s;
    }
}
Signup::Signup()
{
    std::cout<<"Username : ";
    std::cin>>username;
    std::cout<<"Password : ";
    std::cin>>password;
    std::cout<<"Full Name : ";
    std::cin>>fullname;
    fileExsistanceAssert();
    bool valid = isUsernameValid(username);
    if (valid){
        addDataToCsv(username,password,fullname);
        Login l;
    }
    else{
        std::cout<<"\nPlease Try Different Username.\n\n";
        Signup s;
    }
}
std::string Signup::encryptfunc(std::string text)
{
    char temp;
    int i;
    for(i = 0; text[i] != '\0'; ++i){
        temp = text[i];
        if(temp >= 'a' && temp <= 'z'){
            temp += 5;

            if(temp < 'a'){
                temp += 'z' + 'a' - 1;
            }

            text[i] = temp;
        }
        else if(temp >= 'A' && temp <= 'Z'){
            temp += 5;

            if(temp < 'A'){
                temp += 'Z' + 'A' - 1;
            }

            text[i] = temp;
        }
    }
    return text;

}

bool Signup::setdata(){
    bool valid = isUsernameValid(username);
    return valid;
}
bool Signup::isUsernameValid(std::string uname){
    std::vector<std::vector < std::string > > vecData;
    int x;
    CSVFile css("secretdata.csv");
    vecData = css.parse_csv("secretdata.csv");
    for (int i = 1; i < vecData.size(); i++)
    {
        if (vecData[i][1] == uname ){
            x=1;
            std::cout<<"Username already Used";
            break;
        }
        else
        {
            x=0;

        }
    }
    if (x==1){
        return false;
    }
    return true;
}
bool Signup::fileExsistanceAssert()
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

int Signup::numOfUsers(){
    int lines = 0;
    std::ifstream myfile("secretdata.csv");
    std::string line;
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,line);
            lines++;
        }
        myfile.close();
    }
    return lines-2;
}

bool Signup::addDataToCsv(std::string uname,std::string pass,std::string full){
    fileExsistanceAssert();
    int line;
    std::string userId;
    line = numOfUsers();
    int id = line+1;
    std::string encryt = encryptfunc(pass);
    std::stringstream ss;
    ss << id;
    userId = ss.str();

    std::ofstream file;
    file.open ("secretdata.csv", std::ios_base::app);
    file<<"\n"+userId+","+uname+","+encryt+","+fullname+","+"0";
    //std::cout<<"No of Users = "<<line;
    return true;
}

