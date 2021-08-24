#include<iostream>
#include <string>
#include <sstream>
#include <fstream>
#include<vector>

#include "CSVFile.h"


//constructor which does preliminary work required while parsing the csv file which is provided as an argument
CSVFile::CSVFile(std::string given_file_name) {
    file_name = given_file_name;
    data = CSVFile::parse_csv(file_name);

    std::string temp;

    std::ifstream given_file;

    given_file.open(given_file_name.c_str());
    getline(given_file, temp);

    title = divide_single_line_csv(temp, CSVFile::find_no_of_items(temp));
}

// find no of items in the CSV file
int CSVFile::find_no_of_items(std::string csv_line) {
    int n = 0;
    int position;

    while (csv_line.find(",") != std::string::npos) {
        n++;
        position = csv_line.find(",");
        csv_line = csv_line.substr(position + 1, csv_line.size() - 1);
    }

    return n + 1;
}

// divides all the file into single lines of vector so that data can be easily handled
std::vector<std::string> CSVFile::divide_single_line_csv(std::string csv_line, int no_of_items) {
    std::string temp;
    int position;
    std::vector<std::string> return_value;

    for (int i = 0; i < no_of_items - 1; i++) {
        position = csv_line.find(",");
        temp = csv_line.substr(0, position);
        return_value.push_back(temp);
        csv_line = csv_line.substr(position + 1, csv_line.size() - 1);
    }

    return_value.push_back(csv_line);
    return return_value;
}

// it parses the CSV file i.e. it returns vector of vector od string which contains all the data of the CSV file divided into required format
std::vector<std::vector<std::string> > CSVFile::parse_csv(std::string file_name) {
    std::ifstream file;

    file.open(file_name.c_str());
    std::string temp;
    std::vector<std::string> vs1;

    while (file.eof() == 0) {
        getline(file, temp);
        vs1.push_back(temp);
    }

    std::vector<std::vector<std::string> > return_value;

    int no_of_items = find_no_of_items(vs1[0]);


    for (int i = 0; i < vs1.size(); i++) {
        return_value.push_back(divide_single_line_csv(vs1[i], no_of_items));
    }

    return return_value;
}

// Function used to display all the data of CSV file
void CSVFile::display() {
    std::cout << "\t" << data[0][2];
    for (int i = 0; i < data.size() - 1; i++) {
        for (int j = 0; j < data[i].size(); j++) {
            std::cout << title[j] << ": " << data[i][j] << std::endl;
        }
        std::cout << std::endl << "--- --- " << std::endl << std::endl;
    }
}
