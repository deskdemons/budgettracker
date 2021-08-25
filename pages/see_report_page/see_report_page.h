#pragma once
#ifndef BUDGETTRACKER_SEE_REPORT_PAGE_H
#define BUDGETTRACKER_SEE_REPORT_PAGE_H

#include <SFML/Graphics.hpp>
#include<iostream>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"
#include "../../gui/topbar/topbar.h"
#include "../../gui/gui_graphs/guiPieChart.h"
#include "../../gui/gui_graphs/guiBarGraph.h"
#include "../../cclasses/budget/budgetmanager/budgetmanager.h"

class SeeReportPage{
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

    bool isSeeReportOpened;
    bool shouldLoadGraphics;

    sf::Font font;
    bool isMonthlyOpened;

    sf::Color monthlyButtonCol;
    sf::Color yearlyButtonCol;

    sf::Text noPie;
    sf::Text noBar;
    sf::Text currentMonth;
    sf::Text currentYear;
    RoundedRectangle r1;
    RoundedRectangle r2;
    GuiPieChart pie;
    GuiBarGraph bar;
    Button monthly;
    Button yearly;


    Topbar topbarSeeReport;
public:
    SeeReportPage();

    void eventHandler(sf::Event &event, sf::RenderWindow &window);

    void valueAssigner();
    std::vector<Budget> filterByMonth(std::vector<Budget> budgetOfUser, int month);
    void setReportBool(bool state);
    bool seeReportBool();

    void drawer();

    void drawTo(sf::RenderWindow &window);
};

#endif
