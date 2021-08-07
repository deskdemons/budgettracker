#include <iostream>
#include <vector>
#include <sstream>

#include "budget.h"

std::string integer_to_string_budget(int num) {
    std::stringstream ss;
    std::string str;
    ss << num;
    ss >> str;
    return str;
}

Budget::Budget() {};

Budget::Budget(int id_input, int user_id_input, std::string item_name_input, std::string category_input,
               std::string datetime_input, std::string amount_input) {
    id = id_input;
    user_id = user_id_input;
    item_name = item_name_input;
    category = category_input;

    datetime.deserialize(datetime_input);
    amount.deserialize(amount_input);

    // TODO: For debugging purposes only
    std::cout << "Budget Object # " << id << " has been constructed." << std::endl;
};

void Budget::display_information() {
    std::cout << "Budget Info # " << id << " for User ID: " << user_id << std::endl;
    std::cout << "Title: " << item_name << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Datetime: " << datetime.getDateTime() << std::endl;
    std::cout << "Amount: " << amount.getMoney() << std::endl;
};

Budget::Budget(std::string from_csv_line) {
    std::string temp;
    std::vector<std::string> return_value;
    int position;

    for (int i = 0; i < 6; i++) {
        position = from_csv_line.find(",");
        temp = from_csv_line.substr(0, position);

        return_value.push_back(temp);
        from_csv_line = from_csv_line.substr(position + 1, from_csv_line.size() - 1);
    }

    return_value.push_back(from_csv_line);

    id = string_to_integer(return_value[0]);
    user_id = string_to_integer(return_value[1]);
    item_name = return_value[2];
    category = return_value[3];
    DateTime temp_datetime;
    temp_datetime.deserialize(return_value[4]);
    datetime = temp_datetime;
//    amount.deserialize(return_value[5]);
};

int Budget::string_to_integer(std::string string_value) {
    int i;
    std::istringstream ss(string_value);
    ss >> i;
    return i;
};

int Budget::get_user_id() {
    return user_id;
}

std::string Budget::get_category() {
    return category;
}

DateTime Budget::get_datettime() {
    return datetime;
}

std::string Budget::serialize(int current_user_id) {
    std::string temp;
    temp = integer_to_string_budget(id) +
           "," +
           integer_to_string_budget(current_user_id) +
           "," +
           item_name +
           "," +
           category +
           "," +
           datetime.getDateTime() +
           "," +
           amount.getMoney();
    return temp;
}

void Budget::set_id(int id_no) {
    id = id_no;
}