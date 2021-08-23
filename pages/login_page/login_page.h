#pragma once
#ifndef BUDGETTRACKER_LOGIN_PAGE_H
#define BUDGETTRACKER_LOGIN_PAGE_H
#include <SFML/Graphics.hpp>
#include<iostream>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"

class LoginPage{
    bool isAuth;

    Textbox username;
    Textbox password;
    Button loginButton;

public:
    LoginPage();

    void eventHandler(sf::Event &event, sf::RenderWindow &window);

    bool isLoggedIn();

    void drawer();  //should contain logic of drawing stuffs
    void drawTo(sf::RenderWindow &window);

};
#endif //BUDGETTRACKER_LOGIN_PAGE_H
