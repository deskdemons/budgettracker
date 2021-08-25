#pragma once
#ifndef BUDGETTRACKER_LOGIN_PAGE_H
#define BUDGETTRACKER_LOGIN_PAGE_H

#include <SFML/Graphics.hpp>
#include<iostream>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"
#include "../../gui/rounded_rectangle/roundedRectangle.h"
#include "../signup_page/signup_page.h"

class LoginPage {
    SignupPage s;
    bool isAuth, isWrong;
    std::string uname, pass;
    RoundedRectangle backgroundRect;
    Button loginPageShowBox;
    Banner wrongCredentials;
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

    //for logout logic
    void setIsAuth(bool isAuthVal);
    void setTextBoxEmpty();
    void drawer();  //should contain logic of drawing stuffs
    void drawTo(sf::RenderWindow &window);

};

#endif //BUDGETTRACKER_LOGIN_PAGE_H
