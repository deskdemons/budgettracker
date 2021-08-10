//
// Created by paudelrajeev58 on 8/9/21.
//

#ifndef BUDGETTRACKER_CSVFILE_H
#define BUDGETTRACKER_CSVFILE_H
#include <vector>

class CSVFile {
private:
    friend class Authenticate;
    std::vector < std::vector < std::string > > data;
    std::string file_name;
    std::vector < std::string > title;

public:
    CSVFile(std::string given_file_name);

    int find_no_of_items(std::string csv_line);

    std::vector < std::string > divide_single_line_csv(std::string csv_line, int no_of_items);

    std::vector < std::vector < std::string > > parse_csv(std::string file_name);

    void display();
};


#endif //BUDGETTRACKER_CSVFILE_H
