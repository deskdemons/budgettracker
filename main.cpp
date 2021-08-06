#include <iostream>
#include <string>

#include "cclasses/budget/budget.h"
#include "cclasses/currency/money.h"
#include "cclasses/datetime/datetime.h"
#include "cclasses/budget/budgetmanager/budgetmanager.h"

int main()
{
    BudgetManager bdb(1);
    std::vector<Budget> all_budgets = bdb.all();
    for ( int i =0 ; i < all_budgets.size() ; i++) {
        all_budgets[i].display_information();
    }
    return 0;
}