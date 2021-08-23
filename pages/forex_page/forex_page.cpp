#include "forex_page.h"

ForexPage::ForexPage() {

    drawer();
}

void ForexPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch(event.type){
        case sf::Event::TextEntered:
            //code
            break;
        case sf::Event::MouseButtonPressed:
            //code
            break;
    }
}

void ForexPage::drawer() {
    topbarForex.setViewText("Currency Converter");
}

void ForexPage::drawTo(sf::RenderWindow &window) {
    topbarForex.drawTo(window);
}