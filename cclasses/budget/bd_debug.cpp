#include "budget.h"

void Budget::display_information() {
    std::cout << "Budget Info # " << id << " for User ID: " << user_id << std::endl;
    std::cout << "Title: " << item_name << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Datetime: " << datetime.getDateTime() << std::endl;
    std::cout << "Amount: " << amount.getMoney() << std::endl;
};
