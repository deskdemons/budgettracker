#ifndef SIDEBAR_H
#define SIDEBAR_H
#include<iostream>
#include "../rounded_rectangle/roundedRectangle.h"
#include "../button/button.h"

class Sidebar{
    std::string amt;    //amount of money user has as balance
    std::string cur;    //currency of that money. maybe usd or npr
    std::string balanceTxt; // "current balance" text.
    std::string chosenTab;  //name of chosen tab as a string. it can be used to make particular page visible
    sf::Font font;  //font of all text of sidebar

    RoundedRectangle background;    //whole background of sidebar. purple background

    RoundedRectangle balanceBackground; //current balance background
    sf::Text amount;   //sfml text class for amount of balance
    sf::Text currency;  //sfml text class for amount of currency
    sf::Text currentBalance;    //sfml text class for "current balance"

    sf::Color dashboardBgColor; // names tell it all . obviously
    sf::Color dashboardFontColor;
    sf::Color addExpenseBgColor;
    sf::Color addExpenseFontColor;
    sf::Color addIncomeBgColor;
    sf::Color addIncomeFontColor;
    sf::Color seeReportBgColor;
    sf::Color seeReportFontColor;
    sf::Color forexBgColor;
    sf::Color forexFontColor;
    sf::Color backupBgColor;
    sf::Color backupFontColor;
    sf::Color logoutBgColor;
    sf::Color logoutFontColor;

    Button dashboard;   //button class for dashboard
    Button addExpense; //and similarly
    Button addIncome;
    Button seeReport;
    Button forex;
    Button backup;
    Button logout;
public:
    Sidebar();  //default constructor

    void setAmount(std::string amt);    // setter for user balance amount
    void setCurrency(std::string cur);  // setter for balance currency
    void unselectedTabMaker();  // used internally for making all tabs normal and making selected tab diff color
    bool isMouseOverTab(sf::RenderWindow &window);  // bool for is mouse over any of the tabs
    bool isMouseOverBackup(sf::RenderWindow &window);
    bool isMouseOverLogout(sf::RenderWindow &window);

    std::string getChosenTab(); // returns chosen tab as a string
    void drawer();  // logic to draw stuffs
    void drawTo(sf::RenderWindow &window);  //draws artifacts in buffer
};

#endif