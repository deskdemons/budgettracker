#include "login_page.h"

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
            if(username.isMouseOver(window)){
                username.setSelected(true);
                password.setSelected(false);
            }
            else if(password.isMouseOver(window)){
                username.setSelected(false);
                password.setSelected(true);
            }
            else if(loginButton.isMouseOver(window)){
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
    username.setPosition(sf::Vector2f(100,100));
    password.setPosition(sf::Vector2f(100,400));
    loginButton.setPosition(sf::Vector2f(200, 600));
}

void LoginPage::drawTo(sf::RenderWindow &window){
    username.drawTo(window);
    password.drawTo(window);
    loginButton.drawTo(window);
}