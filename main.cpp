#include <iostream>
#include <string>

#include "cclasses/budget/budget.h"
#include "cclasses/currency/money.h"
#include "cclasses/datetime/datetime.h"
#include "cclasses/budget/budgetmanager/budgetmanager.h"
#include "cclasses/users/login/login.h"
#include "cclasses/users/signup/signUp.h"
#include "cclasses/users/authentication/authentication.h"
void createUser(){
    std::string username, password, fullname;
    std::cout<<"Username : ";
    std::cin>>username;
    std::cout<<"Password : ";
    std::cin>>password;
    std::cout<<"Full Name : ";
    std::cin>>fullname;
    Signup s(username,password,fullname);
}
void LoginUser(){
    std::string username, password, fullname;
    std::cout<<"Username : ";
    std::cin>>username;
    std::cout<<"Password : ";
    std::cin>>password;
    Login l(username,password);
}

int main()
{
    std::cout<<"Login or Signup?"<<std::endl;
    char choice;
    std::cin>>choice;
    switch (choice) {
        case '1':
            LoginUser();
            break;
        case '2':
            createUser();
            break;

        default:
            LoginUser();
    }


//    int user_id_current = 1;
//    BudgetManager bdb(user_id_current);
//    Budget b("3,1,Rajeev ko Tshirt,Clothing,12th Jan 2021 - 12:17:23 PM,EUR[12.1]e");
//    bdb.append(b);
//    std::vector<Budget> all_budgets = bdb.all();
//
//    for ( int i =0 ; i < all_budgets.size() ; i++) {
//        std::cout << all_budgets[i].serialize(user_id_current) << std::endl;
//        std::cout << all_budgets[i].get_money().get_nrs_eq_amt() << std::endl << std::endl ;
//    }
//    try{
//        std::cout << "The total for current user is" << bdb.get_total_for_current_user().getMoney() << std::endl;
//        std::cout << "The total income for current user is" << bdb.get_total_income_for_current_user().getMoney() << std::endl;
//        std::cout << "The total expense for current user is" << bdb.get_total_expense_for_current_user().getMoney() << std::endl;
//    } catch (std::string e){
//        std::cout << "Error occurred" << std::endl << e << std::endl;
//    }
    return 0;
}