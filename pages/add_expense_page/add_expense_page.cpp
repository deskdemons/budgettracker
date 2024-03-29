#include "add_expense_page.h"
#include "../../cclasses/currency/vectorCurrency.h"
#include "../../cclasses/budget/budgetmanager/budgetmanager.h"
#include "../../utility/utility.h"

AddExpensePage::AddExpensePage() {
    categoryVector.push_back("Food");
    categoryVector.push_back("Clothing");
    categoryVector.push_back("Travel");
    categoryVector.push_back("Electronics");
    categoryVector.push_back("Entertainment");
    categoryVector.push_back("Health");
    categoryVector.push_back("Miscellaneous");

    font.loadFromFile("Roboto-Regular.ttf");
    titleText.setPosition(sf::Vector2f(300, 115));
    titleText.setString("Title");
    titleText.setCharacterSize(35);
    titleText.setFillColor(sf::Color::Black);
    titleText.setFont(font);

    titleBox.setPosition(sf::Vector2f(300, 160));
    titleBox.setDimension(sf::Vector2f(840, 70));
    titleBox.setPadding(10, 0);
    titleBox.setFontSize(30);
    titleBox.setHintText("");
    titleBox.setBgColor(sf::Color::White);

    currencyText.setPosition(sf::Vector2f(300, 280));
    currencyText.setString("Currency");
    currencyText.setCharacterSize(25);
    currencyText.setFillColor(sf::Color::Black);
    currencyText.setFont(font);

    currencyMenu.setPosition(sf::Vector2f(300, 320));
    currencyMenu.setDimension(sf::Vector2f(250, 50));
    currencyMenu.setDropItemDimension(sf::Vector2f(250, 30));
    currencyMenu.setToggleDropDimension(sf::Vector2f(50, 50));
    currencyMenu.setToggleDropBgColor(sf::Color::White);
    currencyMenu.setToggleDropFontSize(20);
    currencyMenu.setHintText("Currency");
    currencyMenu.setToggleDropFontColor(sf::Color::White);
    currencyMenu.setRadius(5);
    currencyMenu.setToggleDropRadius(5);


    VectorCurrency vc;
    std::vector<Currency> v_cur = vc.getAll();
    std::vector<std::string> v_cur_str;
    for (int z = 0; z < v_cur.size(); z++) {
        v_cur_str.push_back(v_cur[z].getCurType());
    }

    currencyMenu.setDropMenuList(v_cur_str);
    categoryMenu.setDropMenuList(categoryVector);
    currencyMenu.drawer();

    dropdownButtonTexture.loadFromFile("img/dropdownarrowicon1.png");
    dropdownButtonShape.setFillColor(sf::Color::White);
    dropdownButtonShape.setSize(sf::Vector2f(50, 50));
    dropdownButtonShape.setPosition(sf::Vector2f(550, 320));
    dropdownButtonShape.setTexture(&dropdownButtonTexture);


    categoryText.setPosition(sf::Vector2f(800, 280));
    categoryText.setString("Category");
    categoryText.setCharacterSize(25);
    categoryText.setFillColor(sf::Color::Black);
    categoryText.setFont(font);

    categoryMenu.setPosition(sf::Vector2f(800, 320));
    categoryMenu.setDimension(sf::Vector2f(250, 50));
    categoryMenu.setDropItemDimension(sf::Vector2f(250, 30));
    categoryMenu.setToggleDropDimension(sf::Vector2f(50, 50));
    categoryMenu.setToggleDropBgColor(sf::Color::White);
    categoryMenu.setToggleDropFontSize(20);
    categoryMenu.setToggleDropFontColor(sf::Color::White);
    categoryMenu.setHintText("Category");
    categoryMenu.setRadius(5);
    categoryMenu.setToggleDropRadius(5);
    categoryMenu.drawer();

    dropdownButtonShape2.setFillColor(sf::Color::White);
    dropdownButtonShape2.setSize(sf::Vector2f(50, 50));
    dropdownButtonShape2.setPosition(sf::Vector2f(1050, 320));
    dropdownButtonShape2.setTexture(&dropdownButtonTexture);

    amountText.setPosition(sf::Vector2f(300, 410));
    amountText.setString("Amount");
    amountText.setCharacterSize(25);
    amountText.setFillColor(sf::Color::Black);
    amountText.setFont(font);

    amountWarning.setPosition(400, 415);
    amountWarning.setCharacterSize(20);
    amountWarning.setFont(font);
    amountWarning.setFillColor(sf::Color::Red);

    amountBox.setPosition(sf::Vector2f(300, 450));
    amountBox.setDimension(sf::Vector2f(840, 70));
    amountBox.setPadding(10, 0);
    amountBox.setFontSize(30);
    amountBox.setHintText("");
    amountBox.setBgColor(sf::Color::White);

    zeroWarning.setPosition(555, 540);
    zeroWarning.setCharacterSize(20);
    zeroWarning.setFont(font);
    zeroWarning.setFillColor(sf::Color::Red);

    addPic.loadFromFile("img/addicon.png");
    addPic.setSmooth(true);
    addCircle.setRadius(20);
    addCircle.setFillColor(sf::Color::White);
    addCircle.setPosition(545 + 120, 585);
    addCircle.setTexture(&addPic);

    addButton.setPosition(sf::Vector2f(545, 580));
    addButton.setBgColor(sf::Color(76, 76, 76));
    addButton.setButtonText("ADD");
    addButton.setFontColor(sf::Color::White);
    addButton.setPadding(175, 0);
    addButton.setRadius(10);
    addButton.setDimension(sf::Vector2f(350, 50));

    drawer();
}

void AddExpensePage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch (event.type) {
        case sf::Event::TextEntered:
            if (amountBox.isFocus()) {
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
                    amountWarning.setString("");
                    amountBox.typedOn(event);
//                    output_1.setString(t_amount_text_box.getText() + " " + dropdown_currency_list.getChosenItemTxt());
//                    convert_value();
//                    output_2.setString(converted_value_str + " " + dropdown_currency_list_2.getChosenItemTxt());
                } else {
                    amountWarning.setString("Only Numbers Allowed");
                }
            } else if (titleBox.isFocus()) {
                titleBox.typedOn(event);
            }
            break;
        case sf::Event::MouseButtonPressed:
            //code
            if (currencyMenu.isMouseOverToggle(window)) {
                currencyMenu.toggleDropDown();
            } else if (currencyMenu.isMouseOverItem(window)) {
                currencyMenu.getChosenItemTxt();
            } else if (categoryMenu.isMouseOverToggle(window)) {
                categoryMenu.toggleDropDown();
            } else if (categoryMenu.isMouseOverItem(window)) {
                categoryMenu.getChosenItemTxt();
            } else if (amountBox.isMouseOver(window)) {
                amountBox.setSelected(true);
                titleBox.setSelected(false);
            } else if (titleBox.isMouseOver(window)) {
                titleBox.setSelected(true);
                amountBox.setSelected(false);
            } else if (addButton.isMouseOver(window)) {
                BudgetManager bd(globalUser.userId);
                providedAmount = strToDou(amountBox.getText());
                providedCategory = categoryMenu.getChosenItemTxt();
                providedTitle = titleBox.getText();
                providedCurrency = currencyMenu.getChosenItemTxt();
                std::cout << globalUser.userId << std::endl << providedTitle << std::endl << providedCategory
                          << std::endl << providedCategory << std::endl << providedAmount << std::endl;
                if (providedCategory != "" && providedTitle != "" && providedCurrency != "" && providedAmount != 0) {
                    Currency c(providedCurrency);
                    Money m1;
                    m1.setMoney(providedAmount, providedCurrency, "e");
                    DateTime d;
                    Budget b1(0, globalUser.userId, providedTitle, providedCategory, d.getDateTime(), m1.getMoney());
                    bd.append(b1);

                    // Update global user balance negetively when income is added
                    globalUser.balance -= m1.get_nrs_eq_amt();

                    zeroWarning.setString("");
                } else {
                    zeroWarning.setString("Please Don't leave any inputs empty!");
                }
            } else {
                amountBox.setSelected(false);
                titleBox.setSelected(false);
            }
            break;
    }
}

void AddExpensePage::drawer() {
    topbarAddExpense.setViewText("Add Expense");
    topbarAddExpense.setUsername(globalUser.username);
    topbarAddExpense.drawer();
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
    window.draw(zeroWarning);
    addButton.drawTo(window);
    currencyMenu.drawTo(window);
    categoryMenu.drawTo(window);
    window.draw(dropdownButtonShape);
    window.draw(dropdownButtonShape2);
    window.draw(addCircle);
}

double AddExpensePage::strToDou(std::string s) {
    std::stringstream st(s);
    double x = 0;
    st >> x;
    return x;
}