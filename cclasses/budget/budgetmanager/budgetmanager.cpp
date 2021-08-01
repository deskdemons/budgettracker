#include <string>
#include <vector>
#include <fstream>

#include "budgetmanager.h"

BudgetManager::BudgetManager()
{
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
        all_budget.push_back(b);
    }
};

std::vector<Budget> BudgetManager::all()
{
    return all_budget;
};

// checks if a file exists or not
bool BudgetManager::file_exsistance_assert()
{
    const char *fname = "budget.csv";

    std::fstream fs;
    fs.open(fname, std::ios::in);

    if (!fs)
    {
        // File doesnot exist
        //Create a file
        std::ofstream fout(fname);
        if (fout)
        {
            // If the creation is successful
            fout << "#id,user_id,name,category,date,amount,currency" << std::endl;

            // Close the file handle after performing the operation
            fout.close();
        }
        return false;
    }
    else
    {
        return true;
    }
};

std::vector<Budget> BudgetManager::filter_for_user(int user_id_value)
{
    std::vector<Budget> filtered_value;
    for (int i = 0; i < all_budget.size(); i++)
    {
        if (all_budget[i].get_user_id() == user_id_value)
            filtered_value.push_back(all_budget[i]);
    }
    return filtered_value;
}