#include <iostream>
#include <string>

#include "cclasses/budget/budget.h"
#include "cclasses/datetime/datetime.h"
#include "cclasses/budget/budgetmanager/budgetmanager.h"

int main()
{
    int user_id_input;
    std::cout << "Enter User_ID to filter" << std::endl;
    std::cin >> user_id_input;

    BudgetManager bdb(user_id_input);
    std::vector<Budget> my_f_bdb = bdb.filter_by_category("Food");

    for (int i = 0; i < my_f_bdb.size(); i++)
    {
        Budget object = my_f_bdb[i];
        object.display_information();
    }
    return 0;
}