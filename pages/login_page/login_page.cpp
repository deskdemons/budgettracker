#include "login_page.h"
#include "../signup_page/signup_page.h"

LoginPage::LoginPage() {    //constructor
    isAuth = false;  //when program first starts, its not logged in, so false
    drawer();   //drawer is called after object is contructed. obviously, because after construction of object, we need to draw what the page has
}

void LoginPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch(event.type){
        case sf::Event::TextEntered:
            if(username.isFocus()){
                username.typedOn(event);
            }
            else if(password.isFocus()){
                password.typedOn(event);
            }
            break;
            case sf::Event::MouseButtonPressed:
                if (signupButton.isMouseOver(window)){

                }
                if(username.isMouseOver(window)){
                    username.setSelected(true);
                    password.setSelected(false);
                }
                else if(password.isMouseOver(window)){
                    username.setSelected(false);
                    password.setSelected(true);
                }
                else if(loginButton.isMouseOver(window)){
                    loginButton.setBgColor(sf::Color::Blue);
                    std::cout<<"username:" <<username.getText()<<std::endl;
                    std::cout<<"password:" <<password.getText()<<std::endl;
                }
                else{
                    username.setSelected(false);
                    password.setSelected(false);
                }
                break;
    }
}

bool LoginPage::isLoggedIn(){
    return isAuth;
}

void LoginPage::drawer() {
    loginPageShowBox.setBgColor(sf::Color::Black);
    loginPageShowBox.setFontColor(sf::Color::White);
    loginPageShowBox.setBannerText("LOGIN PAGE");
    loginPageShowBox.setDimension(sf::Vector2f(200,60));
    loginPageShowBox.setPadding(40,0);
    loginPageShowBox.setPosition(sf::Vector2f(540,50));

    backgroundRect.setDimension(sf::Vector2f (880,470));
    backgroundRect.setBgColor(sf::Color(234,234,234));
    backgroundRect.setOutLineColor(sf::Color(234, 234, 234));
    backgroundRect.setRadius(20);
    backgroundRect.setPosition(sf::Vector2f(200,150));

    username.setPosition(sf::Vector2f(450,290));
    username.setHintText("username");
    username.setBgColor(sf::Color::White);

    password.setPosition(sf::Vector2f(450,375));
    password.setHintText("password");
    password.setDataType("secure");
    password.setBgColor(sf::Color::White);

    loginButton.setPosition(sf::Vector2f(565, 450));
    loginButton.setDimension(sf::Vector2f(150,50));
    loginButton.setBgColor(sf::Color::White);
    loginButton.setPadding(50,0);
    loginButton.setButtonText("Login");

    signupButton.setPosition(sf::Vector2f(1100, 50));
    signupButton.setDimension(sf::Vector2f(150,40));
    signupButton.setOutLineColor(sf::Color::Red);
    signupButton.setBgColor(sf::Color::Red);
    signupButton.setPadding(45,0);
    signupButton.setFontColor(sf::Color::White);
    signupButton.setButtonText("Signup");

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

void LoginPage::drawTo(sf::RenderWindow &window){
    loginPageShowBox.drawTo(window);
    backgroundRect.drawBg(window);
    username.drawTo(window);
    password.drawTo(window);
    loginButton.drawTo(window);
    backupButton.drawTo(window);
    signupButton.drawTo(window);
    restoreButton.drawTo(window);
}