#pragma once
#ifndef BUDGETTRACKER_ADD_EXPENSE_PAGE_H
#define BUDGETTRACKER_ADD_EXPENSE_PAGE_H
#include <SFML/Graphics.hpp>
#include<iostream>
#include <vector>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"
#include "../../gui/topbar/topbar.h"
#include "../../gui/dropdown_menu/dropdownMenu.h"

class AddExpensePage{
    Topbar topbarAddExpense;
    sf::CircleShape addCircle;
    sf::RectangleShape dropdownButtonShape,dropdownButtonShape2;
    sf::Texture dropdownButtonTexture;
    sf::Texture addPic;
    DropdownMenu currencyMenu,categoryMenu;
    Textbox titleBox,amountBox;
    Button addButton;
    sf::Text titleText,currencyText,categoryText,amountText,amountWarning;
    sf::Font font;
    std::vector<std::string> categoryVector;

public:
    AddExpensePage();
    void eventHandler(sf::Event &event, sf::RenderWindow &window);
    void drawer();
    void drawTo(sf::RenderWindow &window);
};

#endif
