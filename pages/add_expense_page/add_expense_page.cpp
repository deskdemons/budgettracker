#include "add_expense_page.h"

AddExpensePage::AddExpensePage() {

    drawer();
}

void AddExpensePage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch(event.type){
        case sf::Event::TextEntered:
            //code
            break;
        case sf::Event::MouseButtonPressed:
            //code
            break;
    }
}

void AddExpensePage::drawer() {
    topbarAddExpense.setViewText("Add Expense");
}

void AddExpensePage::drawTo(sf::RenderWindow &window) {
    topbarAddExpense.drawTo(window);
}