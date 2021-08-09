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
        cclasses/budget/budget_calcs.cpp cclasses/budget/budgetmanager/bm_calculations.cpp cclasses/currency/money_getters.cpp cclasses/budget/budgetmanager/bm_sorts.cpp cclasses/budget/budgetmanager/bm_utility.cpp cclasses/budget/budgetmanager/bm_getters.cpp cclasses/budget/budgetmanager/bm_filters.cpp)
