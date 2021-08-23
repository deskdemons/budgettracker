#include "add_income_page.h"

AddIncomePage::AddIncomePage() {

    drawer();
}

void AddIncomePage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch(event.type){
        case sf::Event::TextEntered:
            //code
            break;
        case sf::Event::MouseButtonPressed:
            //code
            break;
    }
}

void AddIncomePage::drawer() {
    topbarAddIncome.setViewText("Add Income");
}

void AddIncomePage::drawTo(sf::RenderWindow &window) {
    topbarAddIncome.drawTo(window);
}