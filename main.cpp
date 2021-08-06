#include <iostream>
#include <string>

#include "cclasses/budget/budget.h"
#include "cclasses/datetime/datetime.h"
#include "cclasses/budget/budgetmanager/budgetmanager.h"

int main()
{
    Budget b1("1,1,Rajeev ko Tshirt,Clothing,12th Jan 2021 - 12:17:23 PM,USD[56]e");
    b1.display_information();
    return 0;
}