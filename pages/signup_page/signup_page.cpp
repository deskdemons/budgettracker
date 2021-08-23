#include "signup_page.h"
#include "../../cclasses/users/signup/signUp.h"
#include "../../utility/utility.h"

SignupPage::SignupPage() {    //constructor
    isWrongUsername = false;  //when program first starts, its not logged in, so false
    isUserMade = false;
    drawer();   //drawer is called after object is contructed. obviously, because after construction of object, we need to draw what the page has
}

void SignupPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch(event.type){
        case sf::Event::TextEntered:
            if(fullname.isFocus()){
                fullname.typedOn(event);
            }
            else if(username.isFocus()){
                username.typedOn(event);
            }
            else if(password.isFocus()){
                password.typedOn(event);
            }
            break;
            case sf::Event::MouseButtonPressed:
                if(fullname.isMouseOver(window)){
                    fullname.setSelected(true);
                    username.setSelected(false);
                    password.setSelected(false);
                }
                else if(username.isMouseOver(window)){
                    fullname.setSelected(false);
                    username.setSelected(true);
                    password.setSelected(false);
                }
                else if(password.isMouseOver(window)){
                    fullname.setSelected(false);
                    username.setSelected(false);
                    password.setSelected(true);
                }
                else if (loginButton.isMouseOver(window)){
                    std::cout<<"Login Button Pressed"<<std::endl;
                    Util_SignupMode = false;
                }
                else if(signupButton.isMouseOver(window)){
                    signupButton.setOutLineThickness(3);
                    signupButton.setOutLineColor(sf::Color::Red);
                    std::string full = fullname.getText();
                    uname = username.getText();
                    pass = password.getText();
                    fname = fullname.getText();
                    Signup s(uname,pass,full);
                    isWrongUsername = s.wrongUsername;
                    isUserMade = s.isDone;
                    if (isUserMade == true){
                        signupButton.setOutLineColor(sf::Color::Blue);
                    }
                    std::cout<<"username:" <<full<<std::endl;
                    std::cout<<"username:" <<username.getText()<<std::endl;
                    std::cout<<"password:" <<password.getText()<<std::endl;
                }
                else{
                    fullname.setSelected(false);
                    username.setSelected(false);
                    password.setSelected(false);
                }
                break;
    }
}

bool SignupPage::isLoggedIn(){
    return false;
}

void SignupPage::drawer() {
    SignupPageShowBox.setBgColor(sf::Color::Black);
    SignupPageShowBox.setFontColor(sf::Color::White);
    SignupPageShowBox.setBannerText("SIGNUP PAGE");
    SignupPageShowBox.setDimension(sf::Vector2f(200,60));
    SignupPageShowBox.setPadding(38,0);
    SignupPageShowBox.setPosition(sf::Vector2f(540,50));

    backgroundRect.setDimension(sf::Vector2f (880,470));
    backgroundRect.setBgColor(sf::Color(234,234,234));
    backgroundRect.setOutLineColor(sf::Color(234, 234, 234));
    backgroundRect.setRadius(20);
    backgroundRect.setPosition(sf::Vector2f(200,150));

    fullname.setPosition(sf::Vector2f(450,230));
    fullname.setHintText("fullname");
    fullname.setBgColor(sf::Color::White);

    username.setPosition(sf::Vector2f(450,302));
    username.setHintText("username");
    username.setBgColor(sf::Color::White);

    password.setPosition(sf::Vector2f(450,375));
    password.setHintText("password");
    password.setDataType("secure");
    password.setBgColor(sf::Color::White);

    signupButton.setPosition(sf::Vector2f(565, 450));
    signupButton.setDimension(sf::Vector2f(150,50));
    signupButton.setBgColor(sf::Color::White);
    signupButton.setPadding(40,0);
    signupButton.setButtonText("Sign Up");

    wrongUsername.setBannerText("Username is already used! Please try another Username.");
    wrongUsername.setBgColor(sf::Color::Red);
    wrongUsername.setFontColor(sf::Color::White);
    wrongUsername.setDimension(sf::Vector2f(500,40));
    wrongUsername.setPadding(10,0);
    wrongUsername.setOutLineColor(sf::Color::Red);
    wrongUsername.setPosition(sf::Vector2f(400,550));

    userMade.setBannerText("User was Successfully Made !!");
    userMade.setBgColor(sf::Color::Blue);
    userMade.setFontColor(sf::Color::White);
    userMade.setRadius(10);
    userMade.setDimension(sf::Vector2f(500,40));
    userMade.setPadding(125,0);
    userMade.setOutLineColor(sf::Color::Blue);
    userMade.setPosition(sf::Vector2f(400,550));

    loginButton.setPosition(sf::Vector2f(1100, 50));
    loginButton.setDimension(sf::Vector2f(150,40));
    loginButton.setOutLineColor(sf::Color::Red);
    loginButton.setBgColor(sf::Color::Red);
    loginButton.setPadding(45,0);
    loginButton.setFontColor(sf::Color::White);
    loginButton.setButtonText("Login");

    backupButton.setPosition(sf::Vector2f(900, 650));
    backupButton.setDimension(sf::Vector2f(150,30));
    backupButton.setOutLineColor(sf::Color::Red);
    backupButton.setBgColor(sf::Color::Red);
    backupButton.setPadding(40,0);
    backupButton.setFontColor(sf::Color::White);
    backupButton.setButtonText("Backup");
    backupButton.setFontSize(20);

    restoreButton.setPosition(sf::Vector2f(1100, 650));
    restoreButton.setOutLineColor(sf::Color::Red);
    restoreButton.setDimension(sf::Vector2f(150,30));
    restoreButton.setBgColor(sf::Color::Red);
    restoreButton.setPadding(40,0);
    restoreButton.setFontColor(sf::Color::White);
    restoreButton.setButtonText("Restore");
}

void SignupPage::drawTo(sf::RenderWindow &window){
    SignupPageShowBox.drawTo(window);
    backgroundRect.drawBg(window);
    fullname.drawTo(window);
    username.drawTo(window);
    password.drawTo(window);
    loginButton.drawTo(window);
    backupButton.drawTo(window);
    signupButton.drawTo(window);
    restoreButton.drawTo(window);
    if (isUserMade == true){
        userMade.drawTo(window);
    }
    if (isWrongUsername == true){
        wrongUsername.drawTo(window);
    }
}