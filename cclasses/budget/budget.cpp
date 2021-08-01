#include <iostream>
#include <vector>

#include "budget.h"

Budget::Budget(){};

Budget::Budget(int id_input, std::string item_name_input, std::string category_input, std::string datetime_input, std::string amount_input)
{
    id = id_input;
    item_name = item_name_input;
    category = category_input;

    datetime.deserialize(datetime_input);
    amount = amount_input;

    // For debugging purposes only
    std::cout << "Budget Object # " << id << " has been constructed." << std::endl;
};

void Budget::display_information()
{
    std::cout << "Budget Info # " << id << std::endl;
    std::cout << "Title: " << item_name << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Datetime: " << datetime.getDateTime() << std::endl;
    std::cout << "Amount: " << amount << std::endl;
};

Budget::Budget(std::string from_csv_line)
{
    std::string temp;
    std::vector<std::string> return_value;
    int position;

    for (int i = 0; i < 5; i++)
    {
        position = from_csv_line.find(",");
        temp = from_csv_line.substr(0, position);

        // return_value.push_back(temp);
        from_csv_line = from_csv_line.substr(position + 1, from_csv_line.size() - 1);
    }

    return_value.push_back(from_csv_line);

    // id = return_value[0];
    id = 1;
    item_name = return_value[1];
    category = return_value[2];
    datetime.deserialize(return_value[3]);

    // TODO: Convert it into a money class
    amount = return_value[4];
};