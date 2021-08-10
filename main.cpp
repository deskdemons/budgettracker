#include <iostream>
#include <string>

#include "cclasses/budget/budget.h"
#include "cclasses/budget/budgetmanager/budgetmanager.h"

int main()
{
    try{
        int user_id_current = 1;
        BudgetManager bdb(user_id_current);

        std::vector<Budget> all_budgets = bdb.all();
        for ( int i =0 ; i < all_budgets.size() ; i++) {
            std::cout << all_budgets[i].serialize(user_id_current) << std::endl;
            std::cout << all_budgets[i].get_money().get_nrs_eq_amt() << std::endl << std::endl ;
        }
        try{
            std::cout << "The total for current user is" << bdb.get_total_for_current_user().getMoney() << std::endl;
            std::cout << "The total income for current user is" << bdb.get_total_income_for_current_user().getMoney() << std::endl;
            std::cout << "The total expense for current user is" << bdb.get_total_expense_for_current_user().getMoney() << std::endl;
        } catch (std::string e){
            std::cout << "Error occurred" << std::endl << e << std::endl;
        }

        std::cout << std::endl << "-- -- -- -- --" << std::endl;

        std::vector < BarGraph> bg_vec = bdb.get_graph_yearly_values();
        for(int i=0; i<bg_vec.size();i++){
            std::cout << "The total expense for month " << bg_vec[i].get_month() << " is " << bg_vec[i].get_total() << std::endl;
        }

    }catch (std::string e){
        std::cout << "ERROR " << e << std::endl;
    }


    return 0;
}