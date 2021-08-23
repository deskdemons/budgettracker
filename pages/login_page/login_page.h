#pragma once
#ifndef BUDGETTRACKER_LOGIN_PAGE_H
#define BUDGETTRACKER_LOGIN_PAGE_H
#include <SFML/Graphics.hpp>
#include<iostream>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"
#include "../../gui/rounded_rectangle/roundedRectangle.h"

class LoginPage{
    bool isAuth;
    RoundedRectangle backgroundRect;
    Button loginPageShowBox;
    Textbox username;
    Textbox password;
    Button loginButton;
    Button signupButton;
    Button backupButton;
    Button restoreButton;

public:
    LoginPage();

    void eventHandler(sf::Event &event, sf::RenderWindow &window);

    bool isLoggedIn();

    void drawer();  //should contain logic of drawing stuffs
    void drawTo(sf::RenderWindow &window);

};
#endif //BUDGETTRACKER_LOGIN_PAGE_H
