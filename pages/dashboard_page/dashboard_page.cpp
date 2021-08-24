#include "dashboard_page.h"

DashboardPage::DashboardPage() {

    drawer();
}

void DashboardPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch(event.type){
        case sf::Event::TextEntered:
            //code
            drawer();
            break;
        case sf::Event::MouseButtonPressed:
            //code
            drawer();
            break;
    }
}

void DashboardPage::drawer() {
    //top bar
    topbarDashboard.setViewText("Dashboard Page");

    //piechart
}

void DashboardPage::drawTo(sf::RenderWindow &window) {
    topbarDashboard.drawTo(window);
}