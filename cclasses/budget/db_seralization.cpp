#include "budget.h"


Budget::Budget(const std::string &from_csv_line) {
    from_csv(from_csv_line);
};


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

std::string Budget::serialize() {
    std::string temp;
    temp = integer_to_string_budget(id) +
            "," +
            integer_to_string_budget(user_id) +
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

void Budget::from_csv(std::string from_csv_line) {
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
    amount.deserialize(return_value[5]);
}
