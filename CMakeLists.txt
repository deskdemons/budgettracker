# cmake_minimum_required(VERSION <specify CMake version here>)
project(BudgetTracker)

set(CMAKE_CXX_STANDARD 98)

set(SFML_INCLUDE_DIR "D:/clionSfml/SFML-2.5.1 64bit/include")
set(SFML_LIBRARY_DIR "D:/clionSfml/SFML-2.5.1 64bit/lib")
set(SFML_DIR "D:/clionSfml/SFML-2.5.1 64bit/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio network)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

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
        cclasses/sfmlGraphics/banner.h
        cclasses/sfmlGraphics/textbox.h
        cclasses/sfmlGraphics/roundedRectangle.h
        cclasses/sfmlGraphics/button.h
        cclasses/sfmlGraphics/banner.cpp
        cclasses/sfmlGraphics/textbox.cpp
        cclasses/sfmlGraphics/roundedRectangle.cpp
        cclasses/sfmlGraphics/button.cpp
        cclasses/sfmlGraphics/guiPieChart.h
        cclasses/sfmlGraphics/guiPiechart.cpp
        cclasses/sfmlGraphics/guiBarGraph.h
        cclasses/sfmlGraphics/guiBarGraph.cpp
        cclasses/sfmlGraphics/table.cpp
        cclasses/sfmlGraphics/table.h
        cclasses/sfmlGraphics/dropdownMenu.cpp
        cclasses/sfmlGraphics/dropdownMenu.h
        cclasses/sfmlGraphics/sidebar.cpp
        cclasses/sfmlGraphics/sidebar.h
        )

target_link_libraries(BudgetTracker sfml-system sfml-window sfml-graphics sfml-audio sfml-network)