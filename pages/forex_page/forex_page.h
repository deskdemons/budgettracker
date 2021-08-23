#pragma once
#ifndef BUDGETTRACKER_FOREX_PAGE_H
#define BUDGETTRACKER_FOREX_PAGE_H
#include <SFML/Graphics.hpp>
#include<iostream>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"
#include "../../gui/topbar/topbar.h"

class ForexPage{
    Topbar topbarForex;
public:
    ForexPage();
    void eventHandler(sf::Event &event, sf::RenderWindow &window);
    void drawer();
    void drawTo(sf::RenderWindow &window);
};

#endif

