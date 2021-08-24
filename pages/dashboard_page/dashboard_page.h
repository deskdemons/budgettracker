#pragma once
#ifndef BUDGETTRACKER_DASHBOARD_PAGE_H
#define BUDGETTRACKER_DASHBOARD_PAGE_H
#include <SFML/Graphics.hpp>
#include<iostream>

#include "../../gui/topbar/topbar.h"
#include "../../gui/gui_graphs/guiPieChart.h"
#include "../../gui/gui_graphs/guiBarGraph.h"
#include "../../gui/table/table.h"

class DashboardPage{
    //forpiechart
    std::vector<double> piePercents;
    std::vector<sf::Color> pieColors;
    std::vector<std::string> pieLabels;

    //forbargraph
    std::vector<double> barValues;
    std::vector<sf::Color> barColors;
    std::vector<std::string> BarBottomTitles;

    //for table

    GuiPieChart pie;
    GuiBarGraph bar;
    Table transactionTable;
    Topbar topbarDashboard;
public:
    DashboardPage();
    void eventHandler(sf::Event &event, sf::RenderWindow &window);
    void drawer();
    void drawTo(sf::RenderWindow &window);
};

#endif //BUDGETTRACKER_DASHBOARD_PAGE_H
