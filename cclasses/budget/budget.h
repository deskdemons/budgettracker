#ifndef BUDGET_H
#define BUDGET_H

#include <string>
#include "../datetime/datetime.h"

class Budget
{
private:
    int id;
    std::string item_name;
    std::string category;
    DateTime datetime;

    // TODO: Convert it into a money class
    std::string amount;

public:
    Budget();
    Budget(std::string from_csv_line);
    Budget(int id_input, std::string item_name_input, std::string category_input, std::string datetime_input, std::string amount_input);
    void display_information();
};

#endif