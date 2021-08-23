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
    topbarDashboard.setViewText("Dashboard Page");
}

void DashboardPage::drawTo(sf::RenderWindow &window) {
    topbarDashboard.drawTo(window);
}