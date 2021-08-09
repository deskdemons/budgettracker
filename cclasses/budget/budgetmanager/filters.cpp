#include "budgetmanager.h"

// A private method, that is for use in constructor to filter all_user_budget
// to give for a given user only.
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

// Filters budget objects by category (For current user)
std::vector<Budget> BudgetManager::filter_by_category(const std::string& category_string)
{
    std::vector<Budget> filtered_value;
    for (int i = 0; i < all_budget.size(); i++)
    {
        if (all_budget[i].get_category() == category_string)
            filtered_value.push_back(all_budget[i]);
    }
    return filtered_value;
}


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
