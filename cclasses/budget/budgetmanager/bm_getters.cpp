#include "budgetmanager.h"

std::vector<Budget> BudgetManager::all_users()
{
    return all_users_budget;
};

std::vector<Budget> BudgetManager::all()
{
    return all_budget;
};

std::string BudgetManager::get_file_name()
{
    return file_name;
};
