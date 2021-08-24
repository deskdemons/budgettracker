
#ifndef BUDGETTRACKER_SIGNUP_PAGE_H
#define BUDGETTRACKER_SIGNUP_PAGE_H

#pragma  once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "../../gui/textbox/textbox.h"
#include "../../gui/button/button.h"
#include "../../gui/banner/banner.h"
#include "../../gui/rounded_rectangle/roundedRectangle.h"

//bool  Auth_SignupMode ;

class SignupPage{
    bool isWrongUsername,isUserMade;
    std::string uname,fname,pass;
    RoundedRectangle backgroundRect;
    Button SignupPageShowBox;
    Banner wrongUsername,userMade;
    Textbox username;
    Textbox fullname;
    Textbox password;
    Button loginButton;
    Button signupButton;
    Button backupButton;
    Button restoreButton;

public:
    SignupPage();

    void eventHandler(sf::Event &event, sf::RenderWindow &window);

    bool isLoggedIn();

    void drawer();  //should contain logic of drawing stuffs
    void drawTo(sf::RenderWindow &window);

};




#endif //BUDGETTRACKER_SIGNUP_PAGE_H
