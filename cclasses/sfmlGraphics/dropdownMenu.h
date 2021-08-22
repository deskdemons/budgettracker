#pragma once
#ifndef DROPDOWNMENU_H
#define DROPDOWNMENU_H

#include<iostream>
#include "button.h"
#include "banner.h"

class DropdownMenu {
    std::vector<std::string> dropList;
    std::string chosenText;
    int chosenItemIndex;

    sf::Vector2f position;
    sf::Vector2f dimension;
    int radius;

    sf::Vector2f dropItemDimension;
    sf::Color dropItemBgColor;

    std::string hintText;
    int hintTextFontSize;
    sf::Color hintTextFontColor;
    sf::Vector2f hintTextPadding;

    sf::Font font;
    int fontSize;
    sf::Color fontColor;
    sf::Color bgColor;
    int outLineThickness;
    sf::Color outLineColor;
    sf::Vector2f padding;

    sf::Vector2f toggleDropDimension;
    int toggleDropRadius;
    sf::Font toggleDropFont;
    int toggleDropFontSize;
    sf::Color toggleDropFontColor;
    sf::Color toggleDropBgColor;
    int toggleDropOutLineThickness;
    sf::Color toggleDropOutLineColor;
    sf::Vector2f toggleDropPadding;

    bool isOpen;

    Button* dropButton;
    Button toggleDrop;
    Banner chosenItem;
    sf::Text hint;
public:
    DropdownMenu();

    void setDropMenuList(std::vector<std::string> dropList);
    void setPosition(sf::Vector2f position);
    void setDimension(sf::Vector2f dimension);
    void setRadius(int radius);
    void setFont(sf::Font font);
    void setFontSize(int fontSize);
    void setFontColor(sf::Color fontColor);
    void setBgColor(sf::Color bgColor);
    void setOutLineThickness(int outLineThickness);
    void setOutLineColor(sf::Color outLineColor);
    void setPadding(sf::Vector2f padding);

    void setDropItemDimension(sf::Vector2f dropItemDimension);
    void setDropItemBgColor(sf::Color dropItemBgColor);

    void setHintText(std::string hintText);
    void setHintTextFontSize(int hintTextFontSize);
    void setHintTextFontColor(sf::Color hintTextFontColor);
    void setHintTextPadding(sf::Vector2f hintTextPadding);

    void setToggleDropDimension(sf::Vector2f toggleDropDimension);
    void setToggleDropRadius(int toggleDropRadius);
    void setToggleDropFont(sf::Font toggleDropFont);
    void setToggleDropFontSize(int toggleDropFontSize);
    void setToggleDropFontColor(sf::Color toggleDropFontColor);
    void setToggleDropBgColor(sf::Color toggleDropBgColor);
    void setToggleDropOutLineThickness(int toggleDropOutLineThickness);
    void setToggleDropOutLineColor(sf::Color toggleDropOutLineColor);
    void setToggleDropPadding(sf::Vector2f toggleDropPadding);

    bool isMouseOverToggle(sf::RenderWindow& window);
    void toggleDropDown();
    bool isMouseOverItem(sf::RenderWindow &window);
    std::string getChosenItemTxt();

    void drawer();
    void drawTo(sf::RenderWindow& window);
};

#endif // !DROPDOWNMENU_H
