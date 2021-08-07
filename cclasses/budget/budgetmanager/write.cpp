#include <fstream>
#include <sstream>

#include "./budgetmanager.h"
#include "./../budget.h"


void BudgetManager::append(Budget b){
    const char *fname = "budget.csv";
    std::ofstream fout(fname);

    // Gets the total no of items, indicating highest pk for all objects and
    // changes the budget object to +1 that value, such that the budget id will
    // be always unique and
    int total_items =  all_users_budget.size();
    b.set_id(total_items + 1);
    b.set_user_id(current_user_id);

    all_users_budget.push_back(b);
    all_budget = filter_for_user(current_user_id);

    sort_by_datetime();

    fout << "pk,user_id,title,category,datetime,currency" << std::endl;
    Budget empty_budget_object;
    int i;
    for ( i =0; i<all_users_budget.size()-1; i++){
        fout << all_users_budget[i].serialize(all_users_budget[i].get_user_id()) << std::endl;
    }
    // The "fout" below doesn't have "std::endl" at end so as not to have an empty line at end of csv file
    // If empty line is present, it will create a budget object with empty values,
    // Such that when we append a line, it writes one new empty budget object every time.
    fout << all_users_budget[i].serialize(all_users_budget[i].get_user_id());
    fout.close();
}