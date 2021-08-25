#include "see_report_page.h"
#include "../../utility/utility.h"
#include <sstream>

SeeReportPage::SeeReportPage() {
    shouldLoadGraphics =false;
    isMonthlyOpened = true;
    font.loadFromFile("Roboto-Regular.ttf");
    monthlyButtonCol = sf::Color(76,76,76);
    yearlyButtonCol = sf::Color(200,200,200);

    sf::Color colr[12] = {sf::Color(62, 97, 187),sf::Color(187, 84, 62), sf::Color(221, 255, 5),sf::Color(241, 35, 221),sf::Color(170, 187, 62),sf::Color(171, 143, 231),sf::Color(255, 13, 13),sf::Color(66, 245, 120),sf::Color(66, 242, 245),sf::Color(237, 143, 50),sf::Color(56, 28, 235),sf::Color(156, 235, 28)};
    //default colors;
    for(int i=0;i<12;i++){
        pieDefaultColors.push_back(colr[i]);
    }

    isSeeReportOpened = false;
}

void SeeReportPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch (event.type) {
        case sf::Event::TextEntered:
            //code
            break;
        case sf::Event::MouseButtonPressed:
            //code
            if(monthly.isMouseOver(window)){
                isMonthlyOpened= true;
                monthlyButtonCol = sf::Color(76,76,76);
                yearlyButtonCol = sf::Color(200,200,200);
                drawer();
            }else if(yearly.isMouseOver(window)){
                isMonthlyOpened = false;
                monthlyButtonCol = sf::Color(200,200,200);
                yearlyButtonCol = sf::Color(76,76,76);
                drawer();
            }
            break;
    }
}

void SeeReportPage::valueAssigner(){        //should be called when page changes to dashboard

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

    std::cout<<"unreapeated category"<<unrepeatedCat.size()<<std::endl;

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

    for(int i=0;i<unrepeatedMonths.size();i++){
        allDtVecBudgetBarG[i] = filterByMonth(vecBudget,unrepeatedMonths[i]);
    }
    for(int i=0; i<unrepeatedMonths.size(); i++){
        for(int j=0; j<allDtVecBudgetBarG[i].size();j++){
            DateTime dtCurrent;
            DateTime dtBudget;
            dtBudget.deserialize(allDtVecBudgetBarG[i][j].get_datettime().getDateTime());
            if(dtBudget.get_year() == dtCurrent.get_year() && allDtVecBudgetBarG[i][j].get_money().getType_eORi() == "e"){
                vecBudgetBarG[i].push_back(allDtVecBudgetBarG[i][j]);
            }
        }
    }

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
    if(unrepeatedMonths.size() != 0){
        int c=0;
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
    shouldLoadGraphics = true;

}

std::vector<Budget> SeeReportPage::filterByMonth(std::vector<Budget> budgetOfUser, int month){
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

void SeeReportPage::drawer() {

    std::cout<<"drawer of dashboard"<<std::endl;
    //top bar
    topbarSeeReport.setViewText("See Report");
    std::cout<<globalUser.username<<std::endl;
    topbarSeeReport.setUsername(globalUser.username);

    monthly.setPosition(sf::Vector2f(220,90));
    monthly.setDimension(sf::Vector2f(510, 50));
    monthly.setBgColor(sf::Color(monthlyButtonCol));
    monthly.setButtonText("Monthly");
    monthly.setOutLineThickness(0);
    monthly.setPadding(180,0);
    monthly.setFontColor(sf::Color::White);
    monthly.setFontSize(30);

    yearly.setPosition(sf::Vector2f(750,90));
    yearly.setDimension(sf::Vector2f(510, 50));
    yearly.setBgColor(sf::Color(yearlyButtonCol));
    yearly.setButtonText("Yearly");
    yearly.setOutLineThickness(0);
    yearly.setPadding(200,0);
    yearly.setFontColor(sf::Color::White);
    yearly.setFontSize(30);

    if(isMonthlyOpened){
        r1.setPosition(sf::Vector2f(220,160));
        r1.setDimension(sf::Vector2f(1040, 540));
        r1.setBgColor(sf::Color(227, 226, 232));
        r1.setOutLineThickness(0);
        r1.setRadius(0);
    //piechart
    if(piePercents.size() != 0){
        pie.setPercentages(piePercents);
        pie.setPosition(sf::Vector2f(740, 440));
        pie.setColor(pieColors);
        pie.setLabelTexts(pieLabels);
        pie.setRadius(250);
        pie.setLabelFontSize(15);
    }else{
        noPie.setPosition(sf::Vector2f(500, 400));
        noPie.setFont(font);
        noPie.setString("No Expense This Month");
        noPie.setCharacterSize(40);
        noPie.setFillColor(sf::Color(140, 140, 140));
    }

    }//end of monthly
    else{
        //bargraph
        if(barValues.size() !=0){
            bar.setBarValues(barValues);
            bar.setEachBarBottomTitle(BarBottomTitles);
            bar.setBarColors(barColors);
            bar.setPosition(sf::Vector2f(250,210));
            bar.setBarMaxHeight(400);
            bar.setToggleLabel(false);
            bar.setBarWidth(50);
            bar.setBarSpacing(25);
            bar.setTitlePadding(sf::Vector2f(20,15));
        }else{
            noBar.setPosition(sf::Vector2f(500, 400));
            noBar.setFont(font);
            noBar.setString("No Expense This Year");
            noBar.setCharacterSize(40);
            noBar.setFillColor(sf::Color(140, 140, 140));
        }

        r2.setPosition(sf::Vector2f(220,160));
        r2.setDimension(sf::Vector2f(1040, 540));
        r2.setBgColor(sf::Color(227, 226, 232));
        r2.setOutLineThickness(0);
        r2.setRadius(0);

    }
}

void SeeReportPage::setReportBool(bool state){
    isSeeReportOpened = state;
}
bool SeeReportPage::seeReportBool(){
    return isSeeReportOpened;
}

void SeeReportPage::drawTo(sf::RenderWindow &window) {
    topbarSeeReport.drawTo(window);
    if(shouldLoadGraphics){
        yearly.drawTo(window);
        monthly.drawTo(window);
        if(isMonthlyOpened){
            r1.drawBg(window);

            if(piePercents.size() != 0){
                pie.drawTo(window);
            }
            else{

                window.draw(noPie);
            }
        }
        else{
            r2.drawBg(window);

            if(barValues.size()!=0){
                bar.drawTo(window);
            }else{
                window.draw(noBar);
            }
        }
    }
}