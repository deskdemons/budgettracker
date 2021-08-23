#include "see_report_page.h"

SeeReportPage::SeeReportPage() {

    drawer();
}

void SeeReportPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch(event.type){
        case sf::Event::TextEntered:
            //code
            break;
        case sf::Event::MouseButtonPressed:
            //code
            break;
    }
}

void SeeReportPage::drawer() {
    topbarSeeReport.setViewText("See Report");
}

void SeeReportPage::drawTo(sf::RenderWindow &window) {
    topbarSeeReport.drawTo(window);
}