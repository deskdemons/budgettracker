#include "dashboard_page.h"
#include "../../utility/utility.h"

DashboardPage::DashboardPage() {
    drawer();
}

void DashboardPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    // std::cout<<"gloabal solti"<<globalUser.userId<<std::endl<<globalUser.username<<std::endl<<globalUser.fullname<<std::endl<<globalUser.balance<<std::endl;
    //drawer();
    switch (event.type) {
        case sf::Event::TextEntered:
            // drawer();
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
    std::cout << globalUser.username << std::endl;
    topbarDashboard.setUsername(globalUser.username);

}

void DashboardPage::drawTo(sf::RenderWindow &window) {
    topbarDashboard.drawTo(window);
}