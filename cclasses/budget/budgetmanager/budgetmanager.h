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

    // If file doesnot exist, it creates the file
    bool file_exsistance_assert();

public:
    // Automatically initialize itself to budget.csv file
    // Should create the file if it doesnot exist
    BudgetManager();

    // Group of Methods that returns Budget Objects
    std::vector<Budget> all();

    std::vector<Budget> filter_for_user(int user_id_value);
    std::vector<Budget> top_seven();

    // Returns all budget sorted by the money values
    std::vector<Budget> sorted_by_amount();

    // Should add it to file as well as update the manager itself
    void append(Budget);

    // Return total amount (Money Value)
    // TODO: Convert it to money class not int
    int total();

    std::vector<Budget> filter_by_category(std::string category_string);
};

#endif