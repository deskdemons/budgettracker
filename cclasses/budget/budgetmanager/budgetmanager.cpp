#include <string>
#include <vector>
#include <fstream>

#include "budgetmanager.h"

std::vector<Budget> BudgetManager::all_users()
{
    return all_users_budget;
};

std::vector<Budget> BudgetManager::all()
{
    return all_budget;
};

// checks if a file exists or not, if doesnot exisit, it creates a file
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

// A private method, that is for use in constructor to filter all_user_budget
// to give for a given user only
// Only to be used within a constructor, after all_users_budget has been added
std::vector<Budget> BudgetManager::filter_for_user(int user_id_value)
{
    std::vector<Budget> filtered_value;
    for (int i = 0; i < all_users_budget.size(); i++)
    {
        if (all_users_budget[i].get_user_id() == user_id_value)
            filtered_value.push_back(all_users_budget[i]);
    }
    return filtered_value;
}

// Constructor, where user id is passed and manager instance is created
BudgetManager::BudgetManager(int user_id_value)
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
        all_users_budget.push_back(b);
    }

    all_budget = filter_for_user(user_id_value);
};

// Filters budget objects by category (For current user)
std::vector<Budget> BudgetManager::filter_by_category(std::string category_string)
{
    std::vector<Budget> filtered_value;
    for (int i = 0; i < all_budget.size(); i++)
    {
        if (all_budget[i].get_category() == category_string)
            filtered_value.push_back(all_budget[i]);
    }
    return filtered_value;
}

std::string BudgetManager::get_file_name()
{
    return file_name;
};

std::vector<Budget> BudgetManager::top_seven()
{
    std::vector<Budget> temp;
    if (all_budget.size() <= 7)
    {
        return all_budget;
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            temp.push_back(all_budget[all_budget.size() - i]);
        }
    }

    return temp;
}

// TODO: Complete this
void BudgetManager::sort_by_datetime()
{
    Budget temp;
    for (int i = 0; i < all_budget.size() - 1; i++)
    {
        for (int j = 0; j < all_budget.size() - i - 1; j++)
        {
            if (all_budget[j].get_datettime() > all_budget[j + 1].get_datettime())
            {
                temp = all_budget[j];
                all_budget[j] = all_budget[j + 1];
                all_budget[j + 1] = temp;
            }
        }
    }
};