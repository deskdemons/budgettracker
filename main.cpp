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
//
//    Budget b1("0,1,Prasiddha ko dhojha,Clothing,12th Jan 2022 - 12:18:23 PM,USD[56.44]e");
//    bdb.append(b1);

    std::vector<Budget> all_budgets = bdb.all();
    for ( int i =0 ; i < all_budgets.size() ; i++) {
        std::cout << all_budgets[i].serialize(user_id_current) << std::endl;
    }
    return 0;
}