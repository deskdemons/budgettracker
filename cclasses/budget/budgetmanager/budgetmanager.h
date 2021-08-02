#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <string>
#include <vector>
#include "../budget.h"

class BudgetManager
{
private:
    std::string file_name;
    std::vector<Budget> all_budget;
    std::vector<Budget> all_users_budget;

    bool file_exsistance_assert();
    std::vector<Budget> filter_for_user(int user_id_value);

public:
    BudgetManager(int);

    std::string get_file_name();

    // Group of Methods that returns Budget Objects
    std::vector<Budget> all();
    std::vector<Budget> all_users();
    std::vector<Budget> filter_by_category(std::string category_string);
    std::vector<Budget> top_seven();

    // sorts itself by amount
    void sort_by_amount();

    // sort itself by datetime
    void sort_by_datetime();

    // Should add it to file as well as update the manager itself
    void append(Budget);
    void update(Budget);

    // Return total amount (Money Value)
    // TODO: Convert it to money class not int
    int total();
};

#endif