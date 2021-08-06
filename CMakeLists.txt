# cmake_minimum_required(VERSION <specify CMake version here>)
project(BudgetTracker)

set(CMAKE_CXX_STANDARD 98)

add_executable(BudgetTracker main.cpp)
add_executable(BudgetTracker cclasses/budget/budget.cpp)
add_executable(BudgetTracker cclasses/budget/budgetmanager/budgetmanager.cpp)
add_executable(BudgetTracker cclasses/currency/money.cpp)
add_executable(BudgetTracker cclasses/currency/currency.cpp)
add_executable(BudgetTracker cclasses/currency/vectorCurrency.cpp)
add_executable(BudgetTracker cclasses/datetime/datetime.cpp)
