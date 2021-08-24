#include "add_expense_page.h"
#include "../../cclasses/currency/vectorCurrency.h"
#include "../../cclasses/budget/budget.h"
#include "../../cclasses/budget/budgetmanager/budgetmanager.h"
#include "../../utility/utility.h"

AddExpensePage::AddExpensePage() {
    font.loadFromFile("Roboto-Regular.ttf");
    drawer();
}

void AddExpensePage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch(event.type){
        case sf::Event::TextEntered:
            if (amountBox.isFocus()){
                if(event.text.unicode == '1' ||
                event.text.unicode == '2' ||
                event.text.unicode == '3' ||
                event.text.unicode == '4' ||
                event.text.unicode == '5' ||
                event.text.unicode == '6' ||
                event.text.unicode == '7' ||
                event.text.unicode == '8' ||
                event.text.unicode == '9' ||
                event.text.unicode == '0' ||
                event.text.unicode == '.' ||
                event.text.unicode == BACKSPACE_KEY) {
                    amountWarning.setString("");
                    amountBox.typedOn(event);
//                    output_1.setString(t_amount_text_box.getText() + " " + dropdown_currency_list.getChosenItemTxt());
//                    convert_value();
//                    output_2.setString(converted_value_str + " " + dropdown_currency_list_2.getChosenItemTxt());
                }
                else {
                    amountWarning.setString("Only Numbers Allowed");
                }
            }
            else if(titleBox.isFocus()){
                titleBox.typedOn(event);
            }
            break;
        case sf::Event::MouseButtonPressed:
            //code
            if(amountBox.isMouseOver(window)){
                amountBox.setSelected(true);
                titleBox.setSelected(false);
            } else if(titleBox.isMouseOver(window)){
                titleBox.setSelected(true);
                amountBox.setSelected(false);
            }
            else if(categoryMenu.isMouseOverToggle(window)){
                categoryMenu.toggleDropDown();
            }
            else if(currencyMenu.isMouseOverToggle(window)){
                currencyMenu.toggleDropDown();
            }

            else if(addButton.isMouseOver(window)){
                std::cout<<"Add button Clicked"<<std::endl;
                BudgetManager bd(globalUser.userId);
                
            }

            else{
                amountBox.setSelected(false);
                titleBox.setSelected(false);
            }
            break;
    }
}

void AddExpensePage::drawer() {
    topbarAddExpense.setViewText("Add Expense");

    titleText.setPosition(sf::Vector2f(300,120));
    titleText.setString("Title");
    titleText.setCharacterSize(25);
    titleText.setFillColor(sf::Color::Black);
    titleText.setFont(font);

    titleBox.setPosition(sf::Vector2f(300,160));
    titleBox.setDimension(sf::Vector2f(840,70));
    titleBox.setHintText("");
    titleBox.setBgColor(sf::Color::White);

    currencyText.setPosition(sf::Vector2f(300,280));
    currencyText.setString("Currency");
    currencyText.setCharacterSize(25);
    currencyText.setFillColor(sf::Color::Black);
    currencyText.setFont(font);

    currencyMenu.setPosition(sf::Vector2f(300,320));
    currencyMenu.setDimension(sf::Vector2f(250,50));
    currencyMenu.setDropItemDimension(sf::Vector2f(250,30));
    currencyMenu.setToggleDropDimension(sf::Vector2f(50,50));
    currencyMenu.setToggleDropBgColor(sf::Color::White);
    currencyMenu.setToggleDropFontSize(20);
    currencyMenu.setHintText("Currency");
    currencyMenu.setToggleDropFontColor(sf::Color::White);
    currencyMenu.setRadius(5);
    currencyMenu.setToggleDropRadius(5);

    dropdownButtonTexture.loadFromFile("img/dropdownarrowicon1.png");
    dropdownButtonShape.setFillColor(sf::Color::White);
    dropdownButtonShape.setSize(sf::Vector2f(50,50));
    dropdownButtonShape.setPosition(sf::Vector2f(550,320));
    dropdownButtonShape.setTexture(&dropdownButtonTexture);


    categoryText.setPosition(sf::Vector2f(800,280));
    categoryText.setString("Category");
    categoryText.setCharacterSize(25);
    categoryText.setFillColor(sf::Color::Black);
    categoryText.setFont(font);

    categoryMenu.setPosition(sf::Vector2f(800,320));
    categoryMenu.setDimension(sf::Vector2f(250,50));
    categoryMenu.setDropItemDimension(sf::Vector2f(250,30));
    categoryMenu.setToggleDropDimension(sf::Vector2f(50,50));
    categoryMenu.setToggleDropBgColor(sf::Color::White);
    categoryMenu.setToggleDropFontSize(20);
    categoryMenu.setToggleDropFontColor(sf::Color::White);
    categoryMenu.setHintText("Category");
    categoryMenu.setRadius(5);
    categoryMenu.setToggleDropRadius(5);

    dropdownButtonShape2.setFillColor(sf::Color::White);
    dropdownButtonShape2.setSize(sf::Vector2f(50,50));
    dropdownButtonShape2.setPosition(sf::Vector2f(1050,320));
    dropdownButtonShape2.setTexture(&dropdownButtonTexture);

    amountText.setPosition(sf::Vector2f(300,410));
    amountText.setString("Amount");
    amountText.setCharacterSize(25);
    amountText.setFillColor(sf::Color::Black);
    amountText.setFont(font);

    amountWarning.setPosition(400, 415);
    amountWarning.setCharacterSize(20);
    amountWarning.setFont(font);
    amountWarning.setFillColor(sf::Color::Red);

    amountBox.setPosition(sf::Vector2f(300,450));
    amountBox.setDimension(sf::Vector2f(840,70));
    amountBox.setPadding(10,5);
    amountBox.setFontSize(30);
    amountBox.setHintText("");
    amountBox.setBgColor(sf::Color::White);

    addPic.loadFromFile("img/addicon.png");
    addPic.setSmooth(true);
    addCircle.setRadius(20);
    addCircle.setFillColor(sf::Color::White);
    addCircle.setPosition(545+120, 585);
    addCircle.setTexture(&addPic);

    addButton.setPosition(sf::Vector2f(545,580));
    addButton.setBgColor(sf::Color(76,76,76));
    addButton.setButtonText("ADD");
    addButton.setFontColor(sf::Color::White);
    addButton.setPadding(175,0);
    addButton.setRadius(10);
    addButton.setDimension(sf::Vector2f (350,50));

}

void AddExpensePage::drawTo(sf::RenderWindow &window) {
    topbarAddExpense.drawTo(window);
    window.draw(titleText);
    titleBox.drawTo(window);
    window.draw(currencyText);
    window.draw(categoryText);
    window.draw(amountText);
    window.draw(amountWarning);
    amountBox.drawTo(window);
    addButton.drawTo(window);
    currencyMenu.drawTo(window);
    categoryMenu.drawTo(window);
    window.draw(dropdownButtonShape);
    window.draw(dropdownButtonShape2);
    window.draw(addCircle);
}