#pragma once
#ifndef BUDGETTRACKER_FOREX_PAGE_H
#define BUDGETTRACKER_FOREX_PAGE_H
#include <SFML/Graphics.hpp>
#include<iostream>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"
#include "../../gui/topbar/topbar.h"
#include "../../gui/dropdown_menu/dropdownMenu.h"

class ForexPage{
    Topbar topbarForex;
    sf::Text output_1, output_2;
    sf::Text text_amount, text_from, text_to, text_table_title, t_amount_text_box_warning;
    sf::Font font;
    Textbox t_amount_text_box;
    DropdownMenu dropdown_currency_list, dropdown_currency_list_2;

    sf::CircleShape currency_change_icon_shape; //circle shape for user profile
    sf::Texture currency_change_icon_pic; //user profile default photo texture

public:
    ForexPage();
    void eventHandler(sf::Event &event, sf::RenderWindow &window);
    void drawer();
    void drawTo(sf::RenderWindow &window);
};

#endif

