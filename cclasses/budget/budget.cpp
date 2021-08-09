#include <iostream>

#include "budget.h"

Budget::Budget() {};

Budget::Budget(int id_input, int user_id_input, const std::string& item_name_input, const std::string& category_input,
               const std::string& datetime_input, const std::string& amount_input) {
    id = id_input;
    user_id = user_id_input;
    item_name = item_name_input;
    category = category_input;

    datetime.deserialize(datetime_input);
    amount.deserialize(amount_input);

    // FOR DEBUG
    std::cout << "Budget Object # " << id << " has been constructed." << std::endl;
};
