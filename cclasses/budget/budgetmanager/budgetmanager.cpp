#include <string>
#include <fstream>
#include "budgetmanager.h"

// Constructor, where user id is passed and manager instance is created
BudgetManager::BudgetManager(int user_id_value)
{
    current_user_id = user_id_value;
    file_name = "budget.csv";

    file_exsistance_assert();

    const char *fname = "budget.csv";
    std::fstream fs;
    fs.open(fname, std::ios::in);

    // Read the file line by line
    std::string temp;
    Budget temp_budget;

    // Initial variable name values
    getline(fs, temp);

    while (fs.eof() == 0)
    {
        getline(fs, temp);

        //TODO: Pass User ID here
        Budget b(temp);
        all_users_budget.push_back(b);
    }

    all_budget = filter_for_user(user_id_value);
}