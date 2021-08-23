cmake_minimum_required(VERSION 3.13)
project(BudgetTracker)

set(CMAKE_CXX_STANDARD 98)

set(SFML_INCLUDE_DIR "C:/SDK/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "C:/SDK/SFML-2.5.1/lib")
set(SFML_DIR "C:/SDK/SFML-2.5.1/lib/cmake/SFML")

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
        networking/client/ClientConnection.cpp
        networking/client/ClientConnection.h
        networking/server/ServerConnection.cpp
        networking/server/ServerConnection.h
        gui/banner/banner.h
        gui/textbox/textbox.h
        gui/rounded_rectangle/roundedRectangle.h
        gui/button/button.h
        gui/banner/banner.cpp
        gui/textbox/textbox.cpp
        gui/rounded_rectangle/roundedRectangle.cpp
        gui/button/button.cpp
        gui/gui_graphs/guiPieChart.h
        gui/gui_graphs/guiPiechart.cpp
        gui/topbar/topbar.cpp
        gui/topbar/topbar.h
        cclasses/currency/currencyExchange.cpp 
        cclasses/currency/currencyExchange.h
        gui/gui_graphs/guiBarGraph.h
        gui/gui_graphs/guiBarGraph.cpp
        gui/table/table.cpp
        gui/table/table.h
        gui/dropdown_menu/dropdownMenu.cpp
        gui/dropdown_menu/dropdownMenu.h
        gui/sidebar/sidebar.cpp
        gui/sidebar/sidebar.h

)

target_link_libraries (BudgetTracker sfml-graphics sfml-window sfml-system sfml-network)