#include "sidebar.h"
#include "../../utility/utility.h"

Sidebar::Sidebar() {
    std::string temp = floatToString(globalUser.balance);
    sidebar_top_amount_string = temp;
    cur = "NPR";
    balanceTxt = "Current Balance";
    chosenTab = "Dashboard";

    dashboardBgColor = sf::Color(76, 76, 76); //on default, dashboard is choosen , so color different
    dashboardFontColor = sf::Color::White;   //on default dashboard is chosen. so color different
    addExpenseBgColor = sf::Color::White;
    addExpenseFontColor = sf::Color::Black;
    addIncomeBgColor = sf::Color::White;
    addIncomeFontColor = sf::Color::Black;
    seeReportBgColor = sf::Color::White;
    seeReportFontColor = sf::Color::Black;
    forexBgColor = sf::Color::White;
    forexFontColor = sf::Color::Black;
    backupBgColor = sf::Color(250, 102, 102);
    backupFontColor = sf::Color::White;
    logoutBgColor = sf::Color(250, 102, 102);
    logoutFontColor = sf::Color::White;

    font.loadFromFile("Roboto-Regular.ttf");
    drawer();
}

void Sidebar::drawer() {
    background.setPosition(sf::Vector2f(0, 0));
    background.setDimension(sf::Vector2f(200, 720));
    background.setBgColor(sf::Color(157, 140, 241));
    background.setRadius(0);
    background.setOutLineThickness(0);

    balanceBackground.setPosition(sf::Vector2f(20, 20));
    balanceBackground.setDimension(sf::Vector2f(160, 160));
    balanceBackground.setBgColor(sf::Color::White);
    balanceBackground.setRadius(10);
    balanceBackground.setOutLineThickness(0);

    amount.setString(sidebar_top_amount_string);
    amount.setPosition(sf::Vector2f(55, 40));
    amount.setCharacterSize(30);
    amount.setFont(font);
    amount.setFillColor(sf::Color::Black);

    currency.setString(cur);
    currency.setPosition(sf::Vector2f(70, 90));
    currency.setCharacterSize(30);
    currency.setFont(font);
    currency.setFillColor(sf::Color::Black);

    currentBalance.setString(balanceTxt);
    currentBalance.setPosition(sf::Vector2f(38, 140));
    currentBalance.setCharacterSize(17);
    currentBalance.setFont(font);
    currentBalance.setFillColor(sf::Color::Black);

    dashboard.setButtonText("Dashboard");
    dashboard.setPosition(sf::Vector2f(20, 200));
    dashboard.setDimension(sf::Vector2f(160, 40));
    dashboard.setFont(font);
    dashboard.setFontSize(20);
    dashboard.setPadding(30, 0);
    dashboard.setRadius(10);
    dashboard.setOutLineThickness(0);
    dashboard.setFontColor(dashboardFontColor);
    dashboard.setBgColor(dashboardBgColor);

    addExpense.setButtonText("Add Expense");
    addExpense.setPosition(sf::Vector2f(20, 260));
    addExpense.setDimension(sf::Vector2f(160, 40));
    addExpense.setFont(font);
    addExpense.setFontSize(20);
    addExpense.setPadding(20, 0);
    addExpense.setRadius(10);
    addExpense.setOutLineThickness(0);
    addExpense.setFontColor(addExpenseFontColor);
    addExpense.setBgColor(addExpenseBgColor);

    addIncome.setButtonText("Add Income");
    addIncome.setPosition(sf::Vector2f(20, 320));
    addIncome.setDimension(sf::Vector2f(160, 40));
    addIncome.setFont(font);
    addIncome.setFontSize(20);
    addIncome.setPadding(25, 0);
    addIncome.setRadius(10);
    addIncome.setOutLineThickness(0);
    addIncome.setFontColor(addIncomeFontColor);
    addIncome.setBgColor(addIncomeBgColor);

    seeReport.setButtonText("See Report");
    seeReport.setPosition(sf::Vector2f(20, 380));
    seeReport.setDimension(sf::Vector2f(160, 40));
    seeReport.setFont(font);
    seeReport.setFontSize(20);
    seeReport.setPadding(30, 0);
    seeReport.setRadius(10);
    seeReport.setOutLineThickness(0);
    seeReport.setFontColor(seeReportFontColor);
    seeReport.setBgColor(seeReportBgColor);

    forex.setButtonText("Forex");
    forex.setPosition(sf::Vector2f(20, 440));
    forex.setDimension(sf::Vector2f(160, 40));
    forex.setFont(font);
    forex.setFontSize(20);
    forex.setPadding(52, 0);
    forex.setRadius(10);
    forex.setOutLineThickness(0);
    forex.setFontColor(forexFontColor);
    forex.setBgColor(forexBgColor);

    backup.setButtonText("Backup");
    backup.setPosition(sf::Vector2f(20, 530));
    backup.setDimension(sf::Vector2f(160, 40));
    backup.setFont(font);
    backup.setFontSize(20);
    backup.setPadding(45, 0);
    backup.setRadius(10);
    backup.setOutLineThickness(0);
    backup.setFontColor(backupFontColor);
    backup.setBgColor(backupBgColor);

    logout.setButtonText("Log Out");
    logout.setPosition(sf::Vector2f(20, 660));
    logout.setDimension(sf::Vector2f(160, 40));
    logout.setFont(font);
    logout.setFontSize(20);
    logout.setPadding(35, 0);
    logout.setRadius(10);
    logout.setOutLineThickness(0);
    logout.setFontColor(logoutFontColor);
    logout.setBgColor(logoutBgColor);

}

void Sidebar::setAmount(std::string amt) {
    this->sidebar_top_amount_string = amt;
    drawer();
}

void Sidebar::setCurrency(std::string cur) {
    this->cur = cur;
    drawer();
}

void Sidebar::unselectedTabMaker() {
    dashboardBgColor = sf::Color::White;
    dashboardFontColor = sf::Color::Black;
    addExpenseBgColor = sf::Color::White;
    addExpenseFontColor = sf::Color::Black;
    addIncomeBgColor = sf::Color::White;
    addIncomeFontColor = sf::Color::Black;
    seeReportBgColor = sf::Color::White;
    seeReportFontColor = sf::Color::Black;
    forexBgColor = sf::Color::White;
    forexFontColor = sf::Color::Black;
}

bool Sidebar::isMouseOverTab(sf::RenderWindow &window) {
    if (dashboard.isMouseOver(window)) {
        unselectedTabMaker();
        dashboardFontColor = sf::Color::White;
        dashboardBgColor = sf::Color(76, 76, 76);
        chosenTab = "Dashboard";
        drawer();
        return true;
    } else if (addExpense.isMouseOver(window)) {
        unselectedTabMaker();
        addExpenseBgColor = sf::Color(76, 76, 76);
        addExpenseFontColor = sf::Color::White;
        chosenTab = "Add Expense";
        drawer();
        return true;
    } else if (addIncome.isMouseOver(window)) {
        unselectedTabMaker();
        addIncomeBgColor = sf::Color(76, 76, 76);
        addIncomeFontColor = sf::Color::White;
        chosenTab = "Add Income";
        drawer();
        return true;
    } else if (seeReport.isMouseOver(window)) {
        unselectedTabMaker();
        seeReportBgColor = sf::Color(76, 76, 76);
        seeReportFontColor = sf::Color::White;
        chosenTab = "See Report";
        drawer();
        return true;
    } else if (forex.isMouseOver(window)) {
        unselectedTabMaker();
        forexBgColor = sf::Color(76, 76, 76);
        forexFontColor = sf::Color::White;
        chosenTab = "Forex";
        drawer();
        return true;
    } else {
        return false;
    }
}

bool Sidebar::isMouseOverBackup(sf::RenderWindow &window) {
    if (backup.isMouseOver(window)) { //doing
        return true;
    } else
        return false;
}

bool Sidebar::isMouseOverLogout(sf::RenderWindow &window) {
    if (logout.isMouseOver(window)) { //doing
        return true;
    } else
        return false;
}

std::string Sidebar::getChosenTab() {
    return chosenTab;
}

std::string Sidebar::floatToString(float num) {
    std::stringstream ss;
    std::string str;
    ss << num;
    ss >> str;
    return str;
}

void Sidebar::drawTo(sf::RenderWindow &window) {
    background.drawBg(window);
    //setAmount(sidebar_top_amount_string);
    balanceBackground.drawBg(window);

    // While drawing sidebar, always use the latest global user balance
    amount.setString(floatToString(globalUser.balance));
    window.draw(amount);

    window.draw(currency);
    window.draw(currentBalance);
    dashboard.drawTo(window);
    addExpense.drawTo(window);
    addIncome.drawTo(window);
    seeReport.drawTo(window);
    forex.drawTo(window);

    if (is_backing_up) {
        backup.setButtonText("Backed Up");
        backup.setPadding(30, 0);
    }
    backup.drawTo(window);

    logout.drawTo(window);
}

