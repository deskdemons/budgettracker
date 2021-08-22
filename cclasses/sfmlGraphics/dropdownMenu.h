#pragma once
#ifndef DROPDOWNMENU_H
#define DROPDOWNMENU_H

#include<iostream>
#include "button.h"
#include "banner.h"

class DropdownMenu {
    std::vector<std::string> dropList;  //list of items of drop list in form of vector of string
    std::string chosenText; //used internally to store chosen item
    int chosenItemIndex;    //used internally to store chosen item index from index of vector droplist

    sf::Vector2f position;  //position of dropdown menu. Top left co ordinates
    sf::Vector2f dimension; //dimension of dropdown box
    int radius; //radius of drop down box

    sf::Vector2f dropItemDimension; // dimension of list item of drop down menu
    sf::Color dropItemBgColor;  // background color of list item

    std::string hintText;   // hint text that appears when nothing is entered
    int hintTextFontSize;   // font size of hint text
    sf::Color hintTextFontColor;    //font color of hint text
    sf::Vector2f hintTextPadding;   //padding of hint text w.r.t border of drop down menu

    sf::Font font;  //font of chosenText
    int fontSize;   // font size of chosen text as well as List items
    sf::Color fontColor;    //font color of chosen text as well as List items
    sf::Color bgColor;  //background color of chosen text as well as List items
    int outLineThickness;   // border thickness of drop down menu as well as List items
    sf::Color outLineColor; //border color of drop down menu as well as List items
    sf::Vector2f padding;   //padding of chosenText as well as List items

    sf::Vector2f toggleDropDimension;   // dimension of toggle Button. it toggles menu list open or closed
    int toggleDropRadius;   // radius of toggle Button
    sf::Font toggleDropFont;    //font of text( v )  of toggle Button
    int toggleDropFontSize; //font size of that text
    sf::Color toggleDropFontColor;  //font color of that text
    sf::Color toggleDropBgColor;    //background color of toggle button
    int toggleDropOutLineThickness; // border thickness of toggle button
    sf::Color toggleDropOutLineColor;   //border color of toggle button
    sf::Vector2f toggleDropPadding; //padding of toggle button text ( v )

    bool isOpen;    //is toggle state on or off

    Button* dropButton; //dynamic initialization of itemLists. Because item lists is a button in itself
    Button toggleDrop;  //toggle button
    Banner chosenItem;  //banner that shows chosen item
    sf::Text hint;  // hint text object that is shown when nothing is selected
public:
    DropdownMenu();

    void setDropMenuList(std::vector<std::string> dropList);    //setter for drop down list. ex: std::vector<std::string> list = ({"USD","NPR","EUR"});
    void setPosition(sf::Vector2f position);    //setter for position of dropdown menu. ex: sf::Vector2f(100, 100);
    void setDimension(sf::Vector2f dimension);  //dimension of dropdown menu.
    void setRadius(int radius); // radius of curvature of drop down menu banner
    void setFont(sf::Font font);    //font of dropdown chosen text
    void setFontSize(int fontSize); // font size of it
    void setFontColor(sf::Color fontColor); //font color of it
    void setBgColor(sf::Color bgColor); //background color off drop down banner
    void setOutLineThickness(int outLineThickness); //border thickness of dropdown banenr
    void setOutLineColor(sf::Color outLineColor);   //border color of it
    void setPadding(sf::Vector2f padding);  //padding of chosen text

    void setDropItemDimension(sf::Vector2f dropItemDimension); //each dropdown List items dimension
    void setDropItemBgColor(sf::Color dropItemBgColor); //background color of list items boxes
    //other properties is same as chosenText properties

    void setHintText(std::string hintText); // hint text that is shown when nothing is selected
    void setHintTextFontSize(int hintTextFontSize); // its font size
    void setHintTextFontColor(sf::Color hintTextFontColor); //its font color
    void setHintTextPadding(sf::Vector2f hintTextPadding);  // hint text padding. ex:  sf::Vector2f(10,0)

    //toggle box text is constant , which is "v", it looks like down arrow
    void setToggleDropDimension(sf::Vector2f toggleDropDimension);//toggle button dimension
    void setToggleDropRadius(int toggleDropRadius); //toggle button radius
    void setToggleDropFont(sf::Font toggleDropFont);    //toggle button font
    void setToggleDropFontSize(int toggleDropFontSize); // toggle button font size
    void setToggleDropFontColor(sf::Color toggleDropFontColor); // its font color. that means, font color of "v"
    void setToggleDropBgColor(sf::Color toggleDropBgColor); // toggle button background color
    void setToggleDropOutLineThickness(int toggleDropOutLineThickness); //toggle button border thickness
    void setToggleDropOutLineColor(sf::Color toggleDropOutLineColor);   //toggle button border color
    void setToggleDropPadding(sf::Vector2f toggleDropPadding);  //toggle button text("v") padding

    bool isMouseOverToggle(sf::RenderWindow& window);   // bool , true or false based on mouse pointer is above toggle button.
    void toggleDropDown();  // it toggles, i.e., it makes list open if its already closed and closes if its already opened
    bool isMouseOverItem(sf::RenderWindow &window); // is mouse over list item of dropdown menu.
    std::string getChosenItemTxt(); //returns selected item text

    void drawer(); //contains logic of drawing drop down menu
    void drawTo(sf::RenderWindow& window);  //draws menu in buffer
};

#endif // !DROPDOWNMENU_H
