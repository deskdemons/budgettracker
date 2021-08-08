#include <iostream>
#include <string>

#include "cclasses/budget/budget.h"
#include "cclasses/currency/money.h"
#include "cclasses/datetime/datetime.h"
#include "cclasses/budget/budgetmanager/budgetmanager.h"

int main()
{
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
    return 0;
}