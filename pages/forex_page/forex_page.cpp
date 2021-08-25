#include "forex_page.h"
#include "../../cclasses/currency/vectorCurrency.h"
#include "../../cclasses/currency/currencyExchange.h"

ForexPage::ForexPage() {
    font.loadFromFile("Roboto-Regular.ttf");

    text_amount.setString("Amount");
    text_amount.setPosition(220, 90);
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
    text_from.setPosition(540, 90);
    text_from.setCharacterSize(20);
    text_from.setFont(font);
    text_from.setFillColor(sf::Color::Black);

    text_to.setString("To");
    text_to.setPosition(920, 90);
    text_to.setCharacterSize(20);
    text_to.setFont(font);
    text_to.setFillColor(sf::Color::Black);

    output_1.setString("");
    output_1.setPosition(500, 230);
    output_1.setCharacterSize(20);
    output_1.setFont(font);
    output_1.setFillColor(sf::Color::Black);

    output_2.setString("");
    output_2.setPosition(500, 270);
    output_2.setCharacterSize(40);
    output_2.setFont(font);
    output_2.setFillColor(sf::Color::Black);

    rounded_rectangle.setPosition(sf::Vector2f(470, 200));
    rounded_rectangle.setDimension(sf::Vector2f(500, 180));
    rounded_rectangle.setBgColor(sf::Color::White);
    rounded_rectangle.setOutLineColor(sf::Color::Black);

    dropdown_currency_list.setPosition(sf::Vector2f(540, 120));
    dropdown_currency_list.setDimension(sf::Vector2f(250, 50));
    dropdown_currency_list.setDropItemDimension(sf::Vector2f(250, 30));
    dropdown_currency_list.setToggleDropDimension(sf::Vector2f(50, 50));
    dropdown_currency_list.setToggleDropBgColor(sf::Color::White);
    dropdown_currency_list.setToggleDropFontColor(sf::Color::White);
    dropdown_currency_list.setToggleDropFontSize(40);
    dropdown_currency_list.setRadius(5);
    dropdown_currency_list.setToggleDropRadius(5);

    dropdownButtonTexture.loadFromFile("img/dropdownarrowicon1.png");
    dropdownButtonShape.setFillColor(sf::Color::White);
    dropdownButtonShape.setSize(sf::Vector2f(50, 50));
    dropdownButtonShape.setPosition(sf::Vector2f(790,120));
    dropdownButtonShape.setTexture(&dropdownButtonTexture);


    dropdown_currency_list_2.setPosition(sf::Vector2f(920, 120));
    dropdown_currency_list_2.setDimension(sf::Vector2f(250, 50));
    dropdown_currency_list_2.setDropItemDimension(sf::Vector2f(250, 30));
    dropdown_currency_list_2.setToggleDropDimension(sf::Vector2f(50, 50));
    dropdown_currency_list_2.setToggleDropBgColor(sf::Color::White);
    dropdown_currency_list_2.setToggleDropFontColor(sf::Color::White);
    dropdown_currency_list_2.setToggleDropFontSize(40);
    dropdown_currency_list_2.setRadius(5);
    dropdown_currency_list_2.setToggleDropRadius(5);

    dropdownButtonShape2.setFillColor(sf::Color::White);
    dropdownButtonShape2.setSize(sf::Vector2f(50, 50));
    dropdownButtonShape2.setPosition(sf::Vector2f(1170, 120));
    dropdownButtonShape2.setTexture(&dropdownButtonTexture);

    dropdown_currency_list.setHintText("From Currency");
    dropdown_currency_list_2.setHintText("To Currency");

    currency_change_icon_pic.loadFromFile("img/currexc.png");
    currency_change_icon_pic.setSmooth(true);
    currency_change_icon_shape.setRadius(25);
    currency_change_icon_shape.setFillColor(sf::Color::White);
    currency_change_icon_shape.setTexture(&currency_change_icon_pic);
    currency_change_icon_shape.setPosition(855, 120);

    VectorCurrency vc;
    std::vector<Currency> v_cur = vc.getAll();
    std::vector<std::string> v_cur_str;
    for (int z = 0; z < v_cur.size(); z++) {
        v_cur_str.push_back(v_cur[z].getCurType());
    }

    dropdown_currency_list.setDropMenuList(v_cur_str);
    dropdown_currency_list_2.setDropMenuList(v_cur_str);

    convert_button.setButtonText("Convert");
    convert_button.setOutLineColor(sf::Color(157, 140, 241));
    convert_button.setPosition(sf::Vector2f(740, 280));
    convert_button.setBgColor(sf::Color(157, 140, 241));

    std::vector<std::vector<std::string> > curr_exchange_list;
    std::vector<std::string> list_item;
    list_item.push_back("SN.");
    list_item.push_back("From");
    list_item.push_back("To");
    list_item.push_back("Rate");
    curr_exchange_list.push_back(list_item);

    int sn_no = 0;
    for (int loop_index = 0; loop_index < v_cur.size(); loop_index++) {
        for (int loop_index_2 = 0; loop_index_2 < v_cur.size(); loop_index_2++) {
            if (v_cur[loop_index].getCurType() != v_cur[loop_index_2].getCurType()){
                sn_no ++;
                std::vector<std::string> temp;
                temp.push_back(doubleToString(sn_no));
                temp.push_back(v_cur[loop_index].getCurType());
                temp.push_back(v_cur[loop_index_2].getCurType());

                currencyExchange exc;
                temp.push_back(
                        doubleToString(
                                exc.currencyConverter(
                                        1,
                                        v_cur[loop_index].getCurType(),
                                        v_cur[loop_index_2].getCurType()
                                        )));
                curr_exchange_list.push_back(temp);
            }
        }
    }

    std::cout << "Size of table is " << curr_exchange_list.size() << std::endl;

    table.setContents(curr_exchange_list);
    table.setTableBodyRowNum(4);
    table.setPosition(sf::Vector2f(220,400));

    std::vector<int> col_width_vect;
    col_width_vect.push_back(75);
    col_width_vect.push_back(315);
    col_width_vect.push_back(315);
    col_width_vect.push_back(315);
    table.setColumnWidth(col_width_vect);

    drawer();
}

double ForexPage::stringToDouble(std::string s) {
    std::stringstream st(s);
    double x = 0;
    st >> x;
    return x;
}

void ForexPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch (event.type) {
        case sf::Event::TextEntered:
            if (t_amount_text_box.isFocus()) {
                if (event.text.unicode == '1' ||
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
                    t_amount_text_box_warning.setString("");
                    t_amount_text_box.typedOn(event);
                    output_1.setString(t_amount_text_box.getText() + " " + dropdown_currency_list.getChosenItemTxt());
                    convert_value();
                    output_2.setString(converted_value_str + " " + dropdown_currency_list_2.getChosenItemTxt());
                } else {
                    t_amount_text_box_warning.setString("Only Numbers Allowed");
                }
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (t_amount_text_box.isMouseOver(window)) {
                t_amount_text_box.setSelected(true);
            } else if (dropdown_currency_list.isMouseOverToggle(window)) {
                dropdown_currency_list.toggleDropDown();
            } else if (dropdown_currency_list.isMouseOverItem(window)) {
                output_1.setString(t_amount_text_box.getText() + " " + dropdown_currency_list.getChosenItemTxt());
                text_from.setString("From: " + dropdown_currency_list.getChosenItemTxt());

                convert_value();
                output_2.setString(converted_value_str + " " + dropdown_currency_list_2.getChosenItemTxt());
            } else if (dropdown_currency_list_2.isMouseOverToggle(window)) {
                dropdown_currency_list_2.toggleDropDown();
            } else if (dropdown_currency_list_2.isMouseOverItem(window)) {
                convert_value();
                output_2.setString(converted_value_str + " " + dropdown_currency_list_2.getChosenItemTxt());
                text_to.setString("To: " + dropdown_currency_list_2.getChosenItemTxt());
            } else if (convert_button.isMouseOver(window)) {
                convert_value();
                output_2.setString(converted_value_str + " " + dropdown_currency_list_2.getChosenItemTxt());
            }
            else if(table.isMouseOverUp(window)){
                table.setTableLevelMinus();
                table.drawer();
            } else if(table.isMouseOverDown(window)){
                table.setTableLevelPlus();
                table.drawer();
            }
            else {
                t_amount_text_box.setSelected(false);
            }
            break;
    }
}

void ForexPage::drawer() {
    topbarForex.setViewText("Currency Converter");
}

std::string ForexPage::doubleToString(double num) {
    std::stringstream ss;
    std::string str;
    ss << num;
    ss >> str;
    return str;
}

void ForexPage::drawTo(sf::RenderWindow &window) {
    topbarForex.drawTo(window);
    t_amount_text_box.drawTo(window);
    rounded_rectangle.drawBg(window);

    window.draw(t_amount_text_box_warning);
    window.draw(text_from);
    window.draw(text_to);
    window.draw(currency_change_icon_shape);
    window.draw(text_amount);
    window.draw(output_1);
    window.draw(output_2);

    //convert_button.drawTo(window);

    dropdown_currency_list.drawTo(window);
    dropdown_currency_list_2.drawTo(window);
    window.draw(dropdownButtonShape);
    window.draw(dropdownButtonShape2);

    table.drawTo(window);
}

void ForexPage::convert_value() {
    float initial_value = stringToDouble(t_amount_text_box.getText());
    currencyExchange exchange;
    float converted_value = exchange.currencyConverter(initial_value, dropdown_currency_list.getChosenItemTxt(),
                                                       dropdown_currency_list_2.getChosenItemTxt());
    converted_value_str = doubleToString(converted_value);
}