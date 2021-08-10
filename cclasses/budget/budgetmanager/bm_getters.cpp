#include "budgetmanager.h"

std::vector<Budget> BudgetManager::all_users() {
    return all_users_budget;
}

std::vector<Budget> BudgetManager::all() {
    return all_budget;
}

std::string BudgetManager::get_file_name() {
    return file_name;
}

std::vector<std::string> BudgetManager::get_category_list(){
    std::vector<std::string> category_list;

    for (int i=0; i< all_budget.size();i++){
        Budget temp = all_budget[i];
        std::string category = temp.get_category();
        // Check if that category is already in the list
        bool is_present = false;
        for (int j =0; j< category_list.size(); j++){
            if (category_list[j] == category){
                is_present = true;
                break;
            }
        }

        if (!is_present){
            category_list.push_back(category);
        }

    }
    return category_list;
}
