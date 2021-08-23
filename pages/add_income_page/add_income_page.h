#pragma once
#ifndef BUDGETTRACKER_ADD_INCOME_PAGE_H
#define BUDGETTRACKER_ADD_INCOME_PAGE_H

#include <SFML/Graphics.hpp>
#include<iostream>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"
#include "../../gui/topbar/topbar.h"

class AddIncomePage{
    Topbar topbarAddIncome;
public:
    AddIncomePage();
    void eventHandler(sf::Event &event, sf::RenderWindow &window);
    void drawer();
    void drawTo(sf::RenderWindow &window);
};

#endif


