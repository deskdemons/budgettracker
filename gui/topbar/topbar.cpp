#include "topbar.h"
#include "../banner/banner.h"

Topbar::Topbar() {
    // TODO this is just temporary it is to be done while making whole system
    viewName = "Dashboard";
    username = "Rajeev Paudel";
    b1.setBgColor(sf::Color(250,250,250));
    b1.setPosition(sf::Vector2f(200,20));
    b1.setRadius(0);
    b1.setOutLineColor(sf::Color(250,250,250));
    b1.setDimension(sf::Vector2f(400,50));
    b1.setBannerText(setViewText());
    b1.setPadding(50,0);

    userPic.loadFromFile("img/icon.png");
    b2.setBgColor(sf::Color(250,250,250));
    b2.setPosition(sf::Vector2f(600,20));
    b2.setRadius(0);
    b2.setOutLineColor(sf::Color(250,250,250));
    b2.setDimension(sf::Vector2f(1280-650,50));
    b2.setPadding(350,0);
    b2.setBannerText(setUsername());

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

//TODO returns view to be done while making pages
std::string Topbar::setViewText() {
    return viewName;
}
//TODO: returns global uer
std::string Topbar::setUsername() {
    return username;
}
