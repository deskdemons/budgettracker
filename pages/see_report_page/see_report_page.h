#pragma once
#ifndef BUDGETTRACKER_SEE_REPORT_PAGE_H
#define BUDGETTRACKER_SEE_REPORT_PAGE_H
#include <SFML/Graphics.hpp>
#include<iostream>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"
#include "../../gui/topbar/topbar.h"

class SeeReportPage{
    Topbar topbarSeeReport;
public:
    SeeReportPage();
    void eventHandler(sf::Event &event, sf::RenderWindow &window);
    void drawer();
    void drawTo(sf::RenderWindow &window);
};

#endif
