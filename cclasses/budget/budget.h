#ifndef BUDGET_H
#define BUDGET_H

#include <string>
#include "../datetime/datetime.h"
#include "../currency/money.h"

class Budget {
private:
    int id;
    int user_id;
    std::string item_name;
    std::string category;
    DateTime datetime;
    Money amount;

    static int string_to_integer(const std::string &string_value);

public:
    Budget();

    explicit Budget(const std::string &from_csv_line);

    Budget(int id_input, int user_id_input, const std::string& item_name_input, const std::string& category_input,
           const std::string& datetime_input, const std::string& amount_input);

    void display_information();

    void set_id(int id_no);

    int get_user_id() const;

    void from_csv(std::string from_csv_line);

    void set_user_id(int);

    DateTime get_datettime();

    std::string get_category();

    std::string serialize(int);

    Money get_money();
};

std::string integer_to_string_budget(int);

#endif