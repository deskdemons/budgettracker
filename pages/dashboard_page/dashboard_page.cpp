#include "dashboard_page.h"
#include "../../utility/utility.h"
#include <sstream>
#include "../../cclasses/datetime/datetime.h"
#include<cmath>

DashboardPage::DashboardPage() {
    //no. of column and its width of column is gonna be predefined, we are certain of it
    columnWidth.push_back(70);
    columnWidth.push_back(380);
    columnWidth.push_back(230);
    columnWidth.push_back(130);
    columnWidth.push_back(130);



    shouldLoadGraphics =false;
    font.loadFromFile("Roboto-Regular.ttf");

    sf::Color colr[12] = {sf::Color(62, 97, 187),sf::Color(187, 84, 62), sf::Color(221, 255, 5),sf::Color(241, 35, 221),sf::Color(170, 187, 62),sf::Color(171, 143, 231),sf::Color(255, 13, 13),sf::Color(66, 245, 120),sf::Color(66, 242, 245),sf::Color(237, 143, 50),sf::Color(56, 28, 235),sf::Color(156, 235, 28)};
    //default colors;
    for(int i=0;i<12;i++){
        pieDefaultColors.push_back(colr[i]);
    }

    isDashOpened = false;
    //valueAssigner();
    std::cout<<"constructor of dashboard"<<std::endl;
    //drawer();
}

void DashboardPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    // std::cout<<"gloabal solti"<<globalUser.userId<<std::endl<<globalUser.username<<std::endl<<globalUser.fullname<<std::endl<<globalUser.balance<<std::endl;
    //drawer();
    switch (event.type) {
        case sf::Event::TextEntered:
            //code
            //drawer();
            break;
        case sf::Event::MouseButtonPressed:
            //code
            if(transactionTable.isMouseOverUp(window)){
                transactionTable.setTableLevelMinus();
                transactionTable.drawer();
            }else if(transactionTable.isMouseOverDown(window)){
                transactionTable.setTableLevelPlus();
                transactionTable.drawer();
            }
            //drawer();
            break;
    }
}

std::string i_to_s(int num) {
    std::stringstream ss;
    std::string str;
    ss << num;
    ss >> str;
    return str;
}

std::string dTS(double num) {
    std::stringstream ss;
    std::string str;
    ss << num;
    ss >> str;
    return str;
}

void DashboardPage::valueAssigner(){        //should be called when page changes to dashboard

    // clearing the vector,  or else bad alloc because of pushing stack on top of previous stack
    itemName.clear();
    itemCategory.clear();
    dateAndTime.clear();
    moneyAmt.clear();
    //std::vector<double> eqMoneyAmt;//for charts
    moneyCurrency.clear();

    //forpiechart
    piePercents.clear();
    pieColors.clear();
    pieLabels.clear();

    //forbargraph
    barValues.clear();
    barColors.clear();
    BarBottomTitles.clear();

    //for table
    tableContents.clear();
    //end of clearing vectors

    std::cout<<"value assigner of dashboard"<<std::endl;
    BudgetManager bdb(globalUser.userId);
    std::vector<Budget> vecBudget = bdb.all();
    std::cout<<"size of vecBudget"<<vecBudget.size()<<std::endl;
    for(int i=0; i<vecBudget.size();i++){
        itemName.push_back(vecBudget[i].get_ItemName());
        itemCategory.push_back(vecBudget[i].get_category());
        dateAndTime.push_back((vecBudget[i].get_datettime().getDateTime()));
        moneyAmt.push_back(vecBudget[i].get_money().getMoneyValue());
        //eqMoneyAmt.push_back(vecBudget[i].get_money().get_nrs_eq_amt());
        moneyCurrency.push_back(vecBudget[i].get_money().get_currency().getCurType());
        std::cout<<"for loop 1: "<<vecBudget[i].get_ItemName()<<vecBudget[i].get_category()<<vecBudget[i].get_datettime().getDateTime()<<vecBudget[i].get_money().getMoneyValue()<<vecBudget[i].get_money().get_currency().getCurType()<<std::endl;
    }
    tableContents.clear();
    if(vecBudget.size() !=0){
        //table
        std::vector<std::string> rowHeader;
        rowHeader.push_back("S.N");
        rowHeader.push_back("Title");
        rowHeader.push_back("Date and Time");
        rowHeader.push_back("Amount");
        rowHeader.push_back("Currency");

        tableContents.push_back(rowHeader); //pushing header

        std::vector<std::string> colBody;
        for(int i=0; i<vecBudget.size();i++){
            colBody.clear();
            colBody.push_back(i_to_s(i+1));
            colBody.push_back(itemName[i]);
            colBody.push_back(dateAndTime[i]);
            colBody.push_back(dTS(moneyAmt[i]));
            colBody.push_back(moneyCurrency[i]);
            tableContents.push_back(colBody);
            //for(int j=0; j<colBody.size(); j++){
            //  std::cout<<"for loop 2:"<<i<<": "<<tableContents[i][j]<<std::endl;
            //}

        }
    }

    // for piechart

    std::vector<std::string> validCategory;
    for(int i=0; i<itemCategory.size();i++){
        DateTime dtCurrent;
        DateTime dtBudget;
        dtBudget.deserialize(dateAndTime[i]);
        std::cout<<dtBudget.get_year()<<std::endl;
        std::cout<<dtCurrent.get_year()<<std::endl;
        std::cout<<dtBudget.get_month()<<std::endl;
        std::cout<<dtCurrent.get_month()<<std::endl;
        if(vecBudget[i].get_money().getType_eORi() == "e" &&  dtBudget.get_year()==dtCurrent.get_year() && dtBudget.get_month() == dtCurrent.get_month()){
            validCategory.push_back(itemCategory[i]);
        }
    }

    std::vector<std::string> unrepeatedCat; //problems in piechart yet to be solved //there might not be problem actually. but still experiment with piechart
    std::cout<<"valid category size: "<<validCategory.size()<<std::endl;
    if(validCategory.size() != 0){
        unrepeatedCat.push_back(validCategory[0]);
        int b;
        for (int i = 1; i < validCategory.size(); i++) {
            b = 0;
            for (int j = 0; j < unrepeatedCat.size(); j++) {
                if (unrepeatedCat[j] == validCategory[i])
                    b++;
            }
            if (b == 0){
                unrepeatedCat.push_back(validCategory[i]);
            }
        }
    }

    pieLabels = unrepeatedCat;

    std::vector<Budget> *vecBudgetPie;
    std::vector<Budget> *allDtVecBudgetPie;
    std::cout<<"unreapeated category"<<unrepeatedCat.size()<<std::endl;

    //std::vector<Budget>vecBudgetPie[unrepeatedCat.size()] ;
    //std::vector<Budget> allDtVecBudgetPie[unrepeatedCat.size()];
    if(unrepeatedCat.size() == 0){
        vecBudgetPie = new  std::vector<Budget>[1] ;
        allDtVecBudgetPie = new std::vector<Budget>[1];
    }else{
        vecBudgetPie = new  std::vector<Budget>[unrepeatedCat.size()] ;
        allDtVecBudgetPie = new std::vector<Budget>[unrepeatedCat.size()];
    }
    std::cout<<"passed through"<<std::endl;

    for(int i=0;i<unrepeatedCat.size();i++){
        allDtVecBudgetPie[i] = bdb.filter_by_category(unrepeatedCat[i]);
    }
    for(int i=0; i<unrepeatedCat.size(); i++){
        for(int j=0; j<allDtVecBudgetPie[i].size();j++){
            DateTime dtCurrent;
            DateTime dtBudget;
            dtBudget.deserialize(allDtVecBudgetPie[i][j].get_datettime().getDateTime());
            if(dtBudget.get_month() == dtCurrent.get_month() && dtBudget.get_year() == dtCurrent.get_year()){
                vecBudgetPie[i].push_back(allDtVecBudgetPie[i][j]);
            }
        }
    }

    std::vector<double> totalPieAmt;
    for(int i=0; i<unrepeatedCat.size();i++){
        double totalCategoryAmt = 0;
        for(int j=0; j<vecBudgetPie[i].size();j++){
            totalCategoryAmt += vecBudgetPie[i][j].get_money().get_nrs_eq_amt();    //get_nrs_eq_amt makes sure we have actual percentage w.r.t value of nrseq
            std::cout<<"pushing to totalPie Amount vector:"<<vecBudgetPie[i][j].get_money().get_nrs_eq_amt()<<std::endl;
            std::cout<<"pushing to totalPie Amount vector:"<<vecBudgetPie[i][j].get_money().getMoneyValue()<<std::endl;
        }
        totalPieAmt.push_back(totalCategoryAmt);
    }

    double totAmtPie = 0;
    for(int i=0;i<totalPieAmt.size();i++){
        std::cout<<"tolPieAmt"<<i<<":"<<totalPieAmt[i]<<std::endl;
        totAmtPie +=totalPieAmt[i];
    }

    for(int i=0; i<totalPieAmt.size();i++){
        piePercents.push_back((totalPieAmt[i] * 100.0)/totAmtPie);
    }

    for(int i=0;i<piePercents.size();i++){  //should be commented later
        std::cout<<piePercents[i]<<std::endl;
    }

    for(int i=0; i< piePercents.size(); i++){
        pieColors.push_back(pieDefaultColors[i]);
    }
    std::cout<<"end of piechart"<<std::endl;
    //end of piechart logic

    //bargraph logic
    std::vector<int> validBarMonth; // repeated months of this year only
    for(int i=0; i<dateAndTime.size();i++){
        DateTime dtCurrent;
        DateTime dtBudget;
        dtBudget.deserialize(dateAndTime[i]);
        std::cout<<dtBudget.get_year()<<std::endl;
        std::cout<<dtCurrent.get_year()<<std::endl;
        std::cout<<dtBudget.get_month()<<std::endl;
        std::cout<<dtCurrent.get_month()<<std::endl;
        if(vecBudget[i].get_money().getType_eORi() == "e" &&  dtBudget.get_year()==dtCurrent.get_year()){
            validBarMonth.push_back(dtBudget.get_month());
            std::cout<<"valid month:"<<dtBudget.get_month()<<std::endl;
        }
    }
    std::cout<<"out valid bar month: "<<validBarMonth.size()<<std::endl;
    std::vector<int> unrepeatedMonths; //problems in piechart yet to be solved //there might not be problem actually. but still experiment with piechart

    if(validBarMonth.size() != 0){
        unrepeatedMonths.push_back(validBarMonth[0]);
        std::cout<<"pushing first barMonth:"<<validBarMonth[0]<<std::endl;
        int b;
        for (int i = 1; i < validBarMonth.size(); i++) {
            b = 0;
            for (int j = 0; j < unrepeatedMonths.size(); j++) {
                if (unrepeatedMonths[j] == validBarMonth[i])
                    b++;
            }
            if (b == 0){
                unrepeatedMonths.push_back(validBarMonth[i]);
                std::cout<<"unrepeated months:"<<validBarMonth[i]<<std::endl;
            }
        }
    }
    std::cout<<"out of unrepeated months"<<std::endl;
    //barIntMonths = unrepeatedMonths;

    std::vector<Budget> *vecBudgetBarG;

    std::vector<Budget> *allDtVecBudgetBarG;
    if(unrepeatedMonths.size() == 0){
        vecBudgetBarG = new std::vector<Budget>[1] ;
        allDtVecBudgetBarG = new std::vector<Budget>[1];
    }else{
        vecBudgetBarG = new std::vector<Budget>[unrepeatedMonths.size()] ;
        allDtVecBudgetBarG = new std::vector<Budget>[unrepeatedMonths.size()];
    }
    std::cout<<"vecBudgetBarG made"<<std::endl;

    for(int i=0;i<unrepeatedMonths.size();i++){
        allDtVecBudgetBarG[i] = filterByMonth(vecBudget,unrepeatedMonths[i]);
    }
    for(int i=0; i<unrepeatedMonths.size(); i++){
        for(int j=0; j<allDtVecBudgetBarG[i].size();j++){
            DateTime dtCurrent;
            DateTime dtBudget;
            dtBudget.deserialize(allDtVecBudgetBarG[i][j].get_datettime().getDateTime());
            if(dtBudget.get_year() == dtCurrent.get_year() && allDtVecBudgetBarG[i][j].get_money().getType_eORi()=="e"){
                vecBudgetBarG[i].push_back(allDtVecBudgetBarG[i][j]);
            }
        }
    }
    std::cout<<"loops for assigning vecBudgetBarG finished"<<std::endl;
    std::vector<double> totalBarAmt;
    for(int i=0; i<unrepeatedMonths.size();i++){
        double totalBarGAmt = 0;
        for(int j=0; j<vecBudgetBarG[i].size();j++){
            totalBarGAmt += vecBudgetBarG[i][j].get_money().get_nrs_eq_amt();    //get_nrs_eq_amt makes sure we have actual percentage w.r.t value of nrseq
            std::cout<<"pushing to totalPie Amount vector:"<<vecBudgetBarG[i][j].get_money().get_nrs_eq_amt()<<std::endl;
            std::cout<<"pushing to totalPie Amount vector:"<<vecBudgetBarG[i][j].get_money().getMoneyValue()<<std::endl;
        }
        totalBarAmt.push_back(totalBarGAmt);
    }
    int c=0;
    if(unrepeatedMonths.size() != 0){
        for(int i=0; i<12;i++){
            if(unrepeatedMonths[c] == i+1){
                barValues.push_back(totalBarAmt[c]);
                c++;
            }else{
                barValues.push_back(0.0);
            }
            std::cout<<"bar values: "<<barValues[i]<<std::endl;
        }

        std::cout<<"barValue.size:"<<barValues.size()<<std::endl;
        //barValues = totalBarAmt;

        for(int i=0; i<barValues.size();i++){
            barColors.push_back(pieDefaultColors[i]);
        }
        std::string monthOfYear[] ={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for(int i=0; i<barValues.size();i++){
            BarBottomTitles.push_back(monthOfYear[i]);
        }
    }

    std::cout<<"end of value assigner"<<std::endl;
    shouldLoadGraphics = true;
}

std::vector<Budget> DashboardPage::filterByMonth(std::vector<Budget> budgetOfUser, int month){
    std::vector<Budget> returnBudget;
    for(int i=0; i< budgetOfUser.size();i++){
        DateTime dtCurrent;
        DateTime dtBudgetUser;
        dtBudgetUser.deserialize(dateAndTime[i]);
        if(dtBudgetUser.get_month() == month){
            returnBudget.push_back(budgetOfUser[i]);
        }
    }
    return returnBudget;
}

bool DashboardPage::dashState(){
    return isDashOpened;
}

void DashboardPage::dashBool(bool state){
    this->isDashOpened = state;
}

void DashboardPage::drawer() {
    std::cout<<"drawer of dashboard"<<std::endl;
    //top bar
    topbarDashboard.setViewText("Dashboard Page");


    std::cout<<globalUser.username<<std::endl;

    topbarDashboard.setUsername(globalUser.username);
    topbarDashboard.drawer();

    //rounded rectangles
    r1.setPosition(sf::Vector2f(220,90));
    r1.setDimension(sf::Vector2f(510, 250));
    r1.setBgColor(sf::Color(227, 226, 232));
    r1.setOutLineThickness(0);
    r1.setRadius(0);
    r1.drawer();

    r2.setPosition(sf::Vector2f(750,90));
    r2.setDimension(sf::Vector2f(510, 250));
    r2.setBgColor(sf::Color(227, 226, 232));
    r2.setOutLineThickness(0);
    r2.setRadius(0);
    r2.drawer();

    r3.setPosition(sf::Vector2f(220,360));
    r3.setDimension(sf::Vector2f(1040, 350));
    r3.setBgColor(sf::Color(227, 226, 232));
    r3.setOutLineThickness(0);
    r3.setRadius(0);
    r3.drawer();

    recentTransaction.setString("RECENT TRANSACTIONS");
    recentTransaction.setCharacterSize(30);
    recentTransaction.setFillColor(sf::Color(140, 140, 140));
    recentTransaction.setPosition(sf::Vector2f(240,370));
    recentTransaction.setFont(font);

    //piechart
    if(piePercents.size() != 0){
        pie.setPercentages(piePercents);
        pie.setPosition(sf::Vector2f(370, 215));
        pie.setColor(pieColors);
        pie.setLabelTexts(pieLabels);
        pie.setLabelFontSize(15);
        pie.drawer();
    }else{
        noPie.setPosition(sf::Vector2f(260, 200));
        noPie.setFont(font);
        noPie.setString("No Expense This Month");
        noPie.setCharacterSize(40);
        noPie.setFillColor(sf::Color(140, 140, 140));
    }


    //bargraph
    if(barValues.size() !=0){
        bar.setBarValues(barValues);
        bar.setEachBarBottomTitle(BarBottomTitles);
        bar.setBarColors(barColors);
        bar.setPosition(sf::Vector2f(770,110));
        bar.setBarMaxHeight(180);
        bar.setToggleLabel(false);
        bar.setBarWidth(25);
        bar.setBarSpacing(10);
        bar.setTitlePadding(sf::Vector2f(3,15));
        bar.drawer();
    }else{
        noBar.setPosition(sf::Vector2f(800, 200));
        noBar.setFont(font);
        noBar.setString("No Expense This Year");
        noBar.setCharacterSize(40);
        noBar.setFillColor(sf::Color(140, 140, 140));
    }


    //Table
    if(tableContents.size() !=0){
        transactionTable.setPosition(sf::Vector2f(240,420));
        transactionTable.setTableBodyRowNum(7);
        transactionTable.setHeadBgColor(sf::Color(246, 234, 189));
        transactionTable.setPaddingColumn(10);
        transactionTable.setHeadFontColor(sf::Color::Black);
        transactionTable.setPaddingRow(5);
        transactionTable.setHeaderHeight(40);
        transactionTable.setOutLineThickness(0);
        transactionTable.setBodyHeight(30);
        transactionTable.setHeadFontSize(20);
        transactionTable.setBodyFontSize(15);
        transactionTable.setColumnWidth(columnWidth);
        transactionTable.setContents(tableContents);
        transactionTable.drawer();
    }else{
        noTable.setString("No Transaction Yet");
        noTable.setFont(font);
        noTable.setPosition(sf::Vector2f(525,500));
        noTable.setCharacterSize(50);
        noTable.setFillColor(sf::Color(140,140,140));
    }



}

void DashboardPage::drawTo(sf::RenderWindow &window) {
    topbarDashboard.drawTo(window);
    if(shouldLoadGraphics){
        r1.drawBg(window);
        r2.drawBg(window);
        r3.drawBg(window);
        window.draw(recentTransaction);

        if(piePercents.size() != 0){
            pie.drawTo(window);
        }
        else{

                window.draw(noPie);
        }
        if(barValues.size()!=0){
            bar.drawTo(window);
        }else{
            window.draw(noBar);
        }
        if(tableContents.size() != 0){
            transactionTable.drawTo((window));
        }else{
            window.draw(noTable);
        }
    }
}