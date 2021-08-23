#include "dashboard_page.h"

DashboardPage::DashboardPage() {

    drawer();
}

void DashboardPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch(event.type){
        case sf::Event::TextEntered:
            //code
            break;
        case sf::Event::MouseButtonPressed:
            //code
            break;
    }
}

void DashboardPage::drawer() {
    example.setPosition(sf::Vector2f(100,100));
    example.setBannerText("dashboard page");
}

void DashboardPage::drawTo(sf::RenderWindow &window) {
    example.drawTo(window);
}