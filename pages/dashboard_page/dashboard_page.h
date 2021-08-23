#pragma once
#ifndef BUDGETTRACKER_DASHBOARD_PAGE_H
#define BUDGETTRACKER_DASHBOARD_PAGE_H
#include <SFML/Graphics.hpp>
#include<iostream>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"

class DashboardPage{
    Banner example;
public:
    DashboardPage();
    void eventHandler(sf::Event &event, sf::RenderWindow &window);
    void drawer();
    void drawTo(sf::RenderWindow &window);
};

#endif //BUDGETTRACKER_DASHBOARD_PAGE_H
