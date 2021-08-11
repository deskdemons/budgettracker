# cmake_minimum_required(VERSION <specify CMake version here>)
project(BudgetTracker)

set(CMAKE_CXX_STANDARD 98)

add_executable(
        BudgetTracker
        main.cpp
        cclasses/budget/budget.cpp
        cclasses/budget/budgetmanager/budgetmanager.cpp
        cclasses/currency/money.cpp
        cclasses/currency/currency.cpp
        cclasses/currency/vectorCurrency.cpp
        cclasses/datetime/datetime.cpp
        cclasses/budget/budgetmanager/bm_write.cpp
        cclasses/budget/bd_getters.cpp
        cclasses/budget/budgetmanager/bm_calculations.cpp
        cclasses/currency/money_getters.cpp
        cclasses/budget/budgetmanager/bm_sorts.cpp
        cclasses/budget/budgetmanager/bm_utility.cpp
        cclasses/budget/budgetmanager/bm_getters.cpp
        cclasses/budget/budgetmanager/bm_filters.cpp
        cclasses/budget/bd_debug.cpp
        cclasses/budget/bd_setters.cpp
        cclasses/budget/db_seralization.cpp
        cclasses/budget/utility.cpp
        cclasses/budget/budgetmanager/bm_graphs.cpp
        cclasses/bargraph/BarGraph.cpp
        cclasses/bargraph/BarGraph.h
        cclasses/piechart/PieChart.cpp
        cclasses/piechart/PieChart.h
        cclasses/users/user.cpp
        cclasses/users/user.h
        cclasses/users/authentication/authentication.cpp
        cclasses/users/authentication/authentication.h
        cclasses/users/signup/signUp.cpp
        cclasses/users/signup/signUp.h
        cclasses/users/login/login.cpp
        cclasses/users/login/login.h
        cclasses/users/csvfile/CSVFile.cpp
        cclasses/users/csvfile/CSVFile.h
)
