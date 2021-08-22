#include "sidebar.h"

Sidebar::Sidebar(){
    amt = "10000";
    cur = "USD";
    balanceTxt = "Current Balance";
    chosenTab = "Dashboard";

    dashboardBgColor = sf::Color(76,76,76); //on default, dashboard is choosen , so color different
    dashboardFontColor= sf::Color::White;   //on default dashboard is chosen. so color different
    addExpenseBgColor= sf::Color::White;
    addExpenseFontColor= sf::Color::Black;
    addIncomeBgColor= sf::Color::White;
    addIncomeFontColor= sf::Color::Black;
    seeReportBgColor= sf::Color::White;
    seeReportFontColor= sf::Color::Black;
    forexBgColor= sf::Color::White;
    forexFontColor= sf::Color::Black;
    logoutBgColor= sf::Color::White;
    logoutFontColor= sf::Color::Black;

    font.loadFromFile("Roboto-Regular.ttf");
    drawer();
}
void Sidebar::drawer() {
    background.setPosition(sf::Vector2f(0,0));
    background.setDimension(sf::Vector2f(200, 720 ));
    background.setBgColor(sf::Color(157,140,241));
    background.setRadius(0);
    background.setOutLineThickness(0);

    balanceBackground.setPosition(sf::Vector2f(20,20));
    balanceBackground.setDimension(sf::Vector2f(160,160));
    balanceBackground.setBgColor(sf::Color::White);
    balanceBackground.setRadius(10);
    balanceBackground.setOutLineThickness(0);

    amount.setString(amt);
    amount.setPosition(sf::Vector2f(55,40));
    amount.setCharacterSize(30);
    amount.setFont(font);
    amount.setFillColor(sf::Color::Black);

    currency.setString(cur);
    currency.setPosition(sf::Vector2f(70,90));
    currency.setCharacterSize(30);
    currency.setFont(font);
    currency.setFillColor(sf::Color::Black);

    currentBalance.setString(balanceTxt);
    currentBalance.setPosition(sf::Vector2f(38,140));
    currentBalance.setCharacterSize(17);
    currentBalance.setFont(font);
    currentBalance.setFillColor(sf::Color::Black);

    dashboard.setButtonText("Dashboard");
    dashboard.setPosition(sf::Vector2f(20,200));
    dashboard.setDimension(sf::Vector2f(160,40));
    dashboard.setFont(font);
    dashboard.setFontSize(20);
    dashboard.setPadding(30,0);
    dashboard.setRadius(10);
    dashboard.setOutLineThickness(0);
    dashboard.setFontColor(dashboardFontColor);
    dashboard.setBgColor(dashboardBgColor);

    addExpense.setButtonText("Add Expense");
    addExpense.setPosition(sf::Vector2f(20,260));
    addExpense.setDimension(sf::Vector2f(160,40));
    addExpense.setFont(font);
    addExpense.setFontSize(20);
    addExpense.setPadding(20,0);
    addExpense.setRadius(10);
    addExpense.setOutLineThickness(0);
    addExpense.setFontColor(addExpenseFontColor);
    addExpense.setBgColor(addExpenseBgColor);

    addIncome.setButtonText("Add Income");
    addIncome.setPosition(sf::Vector2f(20,320));
    addIncome.setDimension(sf::Vector2f(160,40));
    addIncome.setFont(font);
    addIncome.setFontSize(20);
    addIncome.setPadding(25,0);
    addIncome.setRadius(10);
    addIncome.setOutLineThickness(0);
    addIncome.setFontColor(addIncomeFontColor);
    addIncome.setBgColor(addIncomeBgColor);

    seeReport.setButtonText("See Report");
    seeReport.setPosition(sf::Vector2f(20,380));
    seeReport.setDimension(sf::Vector2f(160,40));
    seeReport.setFont(font);
    seeReport.setFontSize(20);
    seeReport.setPadding(30,0);
    seeReport.setRadius(10);
    seeReport.setOutLineThickness(0);
    seeReport.setFontColor(seeReportFontColor);
    seeReport.setBgColor(seeReportBgColor);

    forex.setButtonText("Forex");
    forex.setPosition(sf::Vector2f(20,440));
    forex.setDimension(sf::Vector2f(160,40));
    forex.setFont(font);
    forex.setFontSize(20);
    forex.setPadding(52,0);
    forex.setRadius(10);
    forex.setOutLineThickness(0);
    forex.setFontColor(forexFontColor);
    forex.setBgColor(forexBgColor);

    logout.setButtonText("Log Out");
    logout.setPosition(sf::Vector2f(20,660));
    logout.setDimension(sf::Vector2f(160,40));
    logout.setFont(font);
    logout.setFontSize(20);
    logout.setPadding(35,0);
    logout.setRadius(10);
    logout.setOutLineThickness(0);
    logout.setFontColor(logoutFontColor);
    logout.setBgColor(logoutBgColor);

}

void Sidebar::setAmount(std::string amt){
    this->amt = amt;
    drawer();
}
void Sidebar::setCurrency(std::string cur){
    this->cur = cur;
    drawer();
}

void Sidebar::unselectedTabMaker(){
    dashboardBgColor = sf::Color::White;
    dashboardFontColor= sf::Color::Black;
    addExpenseBgColor= sf::Color::White;
    addExpenseFontColor= sf::Color::Black;
    addIncomeBgColor= sf::Color::White;
    addIncomeFontColor= sf::Color::Black;
    seeReportBgColor= sf::Color::White;
    seeReportFontColor= sf::Color::Black;
    forexBgColor= sf::Color::White;
    forexFontColor= sf::Color::Black;
    logoutBgColor= sf::Color::White;
    logoutFontColor= sf::Color::Black;
}

bool Sidebar::isMouseOverTab(sf::RenderWindow &window){
    if(dashboard.isMouseOver(window)){
        unselectedTabMaker();
        dashboardFontColor = sf::Color::White;
        dashboardBgColor = sf::Color(76,76,76);
        chosenTab = "Dashboard";
        drawer();
        return true;
    }
    else if(addExpense.isMouseOver(window)){
        unselectedTabMaker();
        addExpenseBgColor = sf::Color(76,76,76);
        addExpenseFontColor = sf::Color::White;
        chosenTab = "Add Expense";
        drawer();
        return true;
    }
    else if(addIncome.isMouseOver(window)){
        unselectedTabMaker();
        addIncomeBgColor = sf::Color(76,76,76);
        addIncomeFontColor = sf::Color::White;
        chosenTab = "Add Income";
        drawer();
        return true;
    }
    else if(seeReport.isMouseOver(window)){
        unselectedTabMaker();
        seeReportBgColor = sf::Color(76,76,76);
        seeReportFontColor = sf::Color::White;
        chosenTab = "See Report";
        drawer();
        return true;
    }
    else if(forex.isMouseOver(window)){
        unselectedTabMaker();
        forexBgColor = sf::Color(76,76,76);
        forexFontColor = sf::Color::White;
        chosenTab = "Forex";
        drawer();
        return true;
    }
    else if(logout.isMouseOver(window)){
        unselectedTabMaker();
        logoutBgColor = sf::Color(76,76,76);
        logoutFontColor = sf::Color::White;
        chosenTab = "Log Out";
        drawer();
        return true;
    }
    else{
        return false;
    }
}

std::string Sidebar::getChosenTab(){
    return chosenTab;
}

void Sidebar::drawTo(sf::RenderWindow &window) {
    background.drawBg(window);
    balanceBackground.drawBg(window);
    window.draw(amount);
    window.draw(currency);
    window.draw(currentBalance);
    dashboard.drawTo(window);
    addExpense.drawTo(window);
    addIncome.drawTo(window);
    seeReport.drawTo(window);
    forex.drawTo(window);
    logout.drawTo(window);
}