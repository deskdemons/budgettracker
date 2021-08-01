#include <iostream>
#include <string>

#include "cclasses/budget/budget.h"
#include "cclasses/datetime/datetime.h"
#include "cclasses/budget/budgetmanager/budgetmanager.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Budget b1("1,Rajeev ko Tshirt,Clothing,12th Jan 2021-12:17:23 PM,NRP,-1300");
    b1.display_information();

    BudgetManager bdb;
    for (int i =0; i < bdb.all().size(); i++) {
        Budget object = bdb.all()[i];
        object.display_information();
    }

    return 0;
}
