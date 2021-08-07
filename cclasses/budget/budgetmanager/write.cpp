#include <fstream>
#include <sstream>

#include "./budgetmanager.h"
#include "./../budget.h"


void BudgetManager::append(Budget b){
// TODO: First open the file
    const char *fname = "budget.csv";
    std::ofstream fout(fname);

// TODO: Find total no of items in the manager, and the id of budget should be updated to that
    int total_items =  all_users().size();
//    b.set_id(total_items);
    std::cout << "Total items count is" << total_items << std::endl;

// TODO: Add to BudgetManager object
    all_users_budget.push_back(b);
    all_budget = filter_for_user(current_user_id);

// TODO: Format by datetime
    sort_by_datetime();

// TODO: Update the csv file with new info
    fout << "pk,user_id,title,category,datetime,currency" << std::endl;

    for ( int i =0; i<all_users_budget.size(); i++){
        fout << all_users_budget[i].serialize(all_users_budget[i].get_user_id())<<std::endl;
    }
    fout.close();
}