#include <iostream>
#include <string>

#include "cclasses/budget/budget.h"
#include "cclasses/datetime/datetime.h"
#include "cclasses/budget/budgetmanager/budgetmanager.h"

int main()
{
    BudgetManager bdb;
    int user_id_input;
    std::cout << "Enter User_ID to filter" << std::endl;
    std::cin >> user_id_input;
    std::vector<Budget> my_bdb = bdb.filter_for_user(user_id_input);

    for (int i = 0; i < my_bdb.size(); i++)
    {
        Budget object = my_bdb[i];
        object.display_information();
    }
    return 0;
}