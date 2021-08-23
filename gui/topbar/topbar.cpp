#include "topbar.h"
#include "../banner/banner.h"

Topbar::Topbar() {
    // TODO this is just temporary it is to be done while making whole system
    viewName = "Page-Name";
    username = "User-Name";

    drawer();

}
void Topbar::drawer(){
    b1.setBgColor(sf::Color(76,76,76));
    b1.setPosition(sf::Vector2f(220,20));
    b1.setRadius(0);
    b1.setFontColor(sf::Color::White);
    b1.setOutLineColor(sf::Color(76,76,76));
    b1.setDimension(sf::Vector2f(400,50));
    b1.setBannerText(viewName);
    b1.setPadding(50,0);


    b2.setBgColor(sf::Color(76,76,76));
    b2.setPosition(sf::Vector2f(620,20));
    b2.setRadius(0);
    b2.setFontColor(sf::Color::White);
    b2.setOutLineColor(sf::Color(76,76,76));
    b2.setDimension(sf::Vector2f(1280-640,50));
    b2.setPadding(350,0);
    b2.setBannerText(username);

    userPic.loadFromFile("img/icon.png");
    userPic.setSmooth(true);
    userShape.setRadius(20);
    userShape.setFillColor(sf::Color::White);
    userShape.setPosition(1280-100, 25);
    userShape.setTexture(&userPic);
}

void Topbar::drawTo(sf::RenderWindow& window) {
    b1.drawTo(window);
    b2.drawTo(window);
    window.draw(userShape);
}


void Topbar::setViewText(std::string viewText) {
    this->viewName = viewText;
    drawer();
}

void Topbar::setUsername(std::string userName) {
    this->username = userName;
    drawer();
}
