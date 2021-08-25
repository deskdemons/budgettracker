#pragma once
#ifndef BUDGETTRACKER_DASHBOARD_PAGE_H
#define BUDGETTRACKER_DASHBOARD_PAGE_H
#include <SFML/Graphics.hpp>
#include<iostream>

#include "../../gui/topbar/topbar.h"
#include "../../gui/gui_graphs/guiPieChart.h"
#include "../../gui/gui_graphs/guiBarGraph.h"
#include "../../gui/table/table.h"
#include "../../cclasses/budget/budgetmanager/budgetmanager.h"
#include "../../cclasses/budget/budget.h"
#include "../../cclasses/currency/money.h"

class DashboardPage{
    // values extracted from budget
    std::vector<std::string> itemName;
    std::vector<std::string> itemCategory;
    std::vector<std::string> dateAndTime;
    std::vector<double> moneyAmt;
    //std::vector<double> eqMoneyAmt;//for charts
    std::vector<std::string> moneyCurrency;

    //forpiechart
    std::vector<double> piePercents;
    std::vector<sf::Color> pieColors;
    std::vector<std::string> pieLabels;
    std::vector<sf::Color> pieDefaultColors;

    //forbargraph
    std::vector<double> barValues;
    std::vector<sf::Color> barColors;
    std::vector<std::string> BarBottomTitles;

    //for table
    std::vector<std::vector<std::string> > tableContents;
    std::vector<int> columnWidth;

    //budget objects
    //BudgetManager *bdb;

    bool isDashOpened;
    bool shouldLoadGraphics;

    sf::Font font;

    sf::Text noPie;
    sf::Text noBar;
    sf::Text noTable;
    sf::Text recentTransaction;
    RoundedRectangle r1;
    RoundedRectangle r2;
    RoundedRectangle r3;
    GuiPieChart pie;
    GuiBarGraph bar;
    Table transactionTable;
    Topbar topbarDashboard;
public:
    DashboardPage();
    void eventHandler(sf::Event &event, sf::RenderWindow &window);
    void valueAssigner();

    void dashBool(bool state);
    bool dashState();

    std::vector<Budget> filterByMonth(std::vector<Budget> budgetOfUser, int month);

    void drawer();
    void drawTo(sf::RenderWindow &window);
};

#endif //BUDGETTRACKER_DASHBOARD_PAGE_H
