#include "forex_page.h"
#include "../../cclasses/currency/vectorCurrency.h"

ForexPage::ForexPage() {
    font.loadFromFile("Roboto-Regular.ttf");

    text_amount.setString("Amount");
    text_amount.setPosition(220,90);
    text_amount.setCharacterSize(20);
    text_amount.setFont(font);
    text_amount.setFillColor(sf::Color::Black);

    t_amount_text_box_warning.setPosition(300, 90);
    t_amount_text_box_warning.setCharacterSize(20);
    t_amount_text_box_warning.setFont(font);
    t_amount_text_box_warning.setFillColor(sf::Color::Red);

    t_amount_text_box.setFont(font);
    t_amount_text_box.setPosition(sf::Vector2f(220, 120));
    t_amount_text_box.setDimension(sf::Vector2f(300, 50));
    t_amount_text_box.setBgColor(sf::Color::White);
    t_amount_text_box.setHintText("Amount");

    text_from.setString("From");
    text_from.setPosition(540,90);
    text_from.setCharacterSize(20);
    text_from.setFont(font);
    text_from.setFillColor(sf::Color::Black);

    text_to.setString("To");
    text_to.setPosition(920,90);
    text_to.setCharacterSize(20);
    text_to.setFont(font);
    text_to.setFillColor(sf::Color::Black);

    dropdown_currency_list.setPosition(sf::Vector2f(540, 120));
    dropdown_currency_list.setDimension(sf::Vector2f(250,50));
    dropdown_currency_list.setDropItemDimension(sf::Vector2f(250,30));
    dropdown_currency_list.setToggleDropDimension(sf::Vector2f(50,50));
    dropdown_currency_list.setToggleDropBgColor(sf::Color::White);
    dropdown_currency_list.setToggleDropFontSize(40);
    dropdown_currency_list.setRadius(5);
    dropdown_currency_list.setToggleDropRadius(5);

    dropdown_currency_list_2.setPosition(sf::Vector2f(920, 120));
    dropdown_currency_list_2.setDimension(sf::Vector2f(250,50));
    dropdown_currency_list_2.setDropItemDimension(sf::Vector2f(250,30));
    dropdown_currency_list_2.setToggleDropDimension(sf::Vector2f(50,50));
    dropdown_currency_list_2.setToggleDropBgColor(sf::Color::White);
    dropdown_currency_list_2.setToggleDropFontSize(40);
    dropdown_currency_list_2.setRadius(5);
    dropdown_currency_list_2.setToggleDropRadius(5);

    dropdown_currency_list.setHintText("From Currency");
    dropdown_currency_list_2.setHintText("To Currency");

    currency_change_icon_pic.loadFromFile("img/currexc.png");
    currency_change_icon_pic.setSmooth(true);
    currency_change_icon_shape.setRadius(25);
    currency_change_icon_shape.setFillColor(sf::Color::White);
    currency_change_icon_shape.setTexture(&currency_change_icon_pic);
    currency_change_icon_shape.setPosition(855,120);

    VectorCurrency vc;
    std::vector<Currency> v_cur = vc.getAll();
    std::vector<std::string> v_cur_str;
    for (int z; z<v_cur.size(); z++){
        v_cur_str.push_back(v_cur[z].getCurType());
    }

    dropdown_currency_list.setDropMenuList(v_cur_str);
    dropdown_currency_list_2.setDropMenuList(v_cur_str);

    drawer();
}

void ForexPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch(event.type){
        case sf::Event::TextEntered:
            if(t_amount_text_box.isFocus()){
                if(     event.text.unicode == '1' ||
                        event.text.unicode == '2' ||
                        event.text.unicode == '3' ||
                        event.text.unicode == '4' ||
                        event.text.unicode == '5' ||
                        event.text.unicode == '6' ||
                        event.text.unicode == '7' ||
                        event.text.unicode == '8' ||
                        event.text.unicode == '9' ||
                        event.text.unicode == '0' ||
                        event.text.unicode == BACKSPACE_KEY) {
                    t_amount_text_box_warning.setString("");
                    t_amount_text_box.typedOn(event);
                } else {
                    t_amount_text_box_warning.setString("Only Numbers Allowed");
                }
            }
            break;
        case sf::Event::MouseButtonPressed:
            if(t_amount_text_box.isMouseOver(window)){
                t_amount_text_box.setSelected(true);
            } else if(dropdown_currency_list.isMouseOverToggle(window)){
                dropdown_currency_list.toggleDropDown();
            } else if(dropdown_currency_list.isMouseOverItem(window)){
                text_from.setString("From: " + dropdown_currency_list.getChosenItemTxt());
            }else if(dropdown_currency_list_2.isMouseOverToggle(window)){
                dropdown_currency_list_2.toggleDropDown();
            } else if(dropdown_currency_list_2.isMouseOverItem(window)){
                text_to.setString("To: " + dropdown_currency_list_2.getChosenItemTxt());
            }
            else{
                t_amount_text_box.setSelected(false);
            }
            break;
    }
}

void ForexPage::drawer() {
    topbarForex.setViewText("Currency Converter");
}

void ForexPage::drawTo(sf::RenderWindow &window) {
    topbarForex.drawTo(window);
    t_amount_text_box.drawTo(window);
    dropdown_currency_list.drawTo(window);
    dropdown_currency_list_2.drawTo(window);

    window.draw(t_amount_text_box_warning);
    window.draw(text_from);
    window.draw(text_to);
    window.draw(currency_change_icon_shape);
    window.draw(text_amount);
}