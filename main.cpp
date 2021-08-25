#include<iostream>
#include <SFML/Graphics.hpp>
#include "gui/sidebar/sidebar.h"
#include "pages/login_page/login_page.h"
#include "cclasses/users/signup/signUp.h"
#include "pages/dashboard_page/dashboard_page.h"
#include "pages/add_expense_page/add_expense_page.h"
#include "pages/add_income_page/add_income_page.h"
#include "pages/forex_page/forex_page.h"
#include "pages/see_report_page/see_report_page.h"
#include "utility/utility.h"


int main() {
    sf::RenderWindow window;
    window.setFramerateLimit(60);
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;    // for smoother graphics
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 640,
                              (sf::VideoMode::getDesktopMode().height / 2) - 360);
    window.create(sf::VideoMode(1280, 720), "setBudGet", sf::Style::Default, settings);
    window.setPosition(
            centerWindow);    //centerwindow is defined above. it's position is set so that the window is displayed symmetrically on the screen
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);

    window.setFramerateLimit(60);

    Sidebar s1;
    LoginPage l1;
    SignupPage su1;
    DashboardPage d1;
    AddExpensePage e1;
    AddIncomePage i1;
    ForexPage f1;
    SeeReportPage sr1;

    while (window.isOpen()) {    //this is always true when program is run. it is only false when program closes
        sf::Event event;
        std::string openedTab = s1.getChosenTab();
        while (window.pollEvent(
                event)) {    //it is analogous to fps. polling means recording the events many times per second continuously while the program runs
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
                if (l1.isLoggedIn() == false && Util_SignupMode == false) {
                    l1.eventHandler(event, window);
                } else if (Util_SignupMode == true) {
                    su1.eventHandler(event, window);
                } else {

                    if(openedTab != "Dashboard"){
                        if(d1.dashState() == true){
                            std::cout<<"if: making dashboard false"<<std::endl;
                            d1.dashBool(false);
                        }
                    }
                    if(openedTab != "See Report"){
                        if(sr1.seeReportBool() == true){
                            sr1.setReportBool(false);
                        }
                    }
                    if(openedTab == "Dashboard"){
                        std::cout<<"should run continuously"<<std::endl;
                        if(d1.dashState() == false){
                            std::cout<<"dashboard opened by first time or switching tab"<<std::endl;
                            d1.valueAssigner();
                            d1.drawer();
                            d1.dashBool(true);
                        }
                        d1.eventHandler(event, window);
                        //d1.drawer();
                    } else if (openedTab == "Add Expense") {
                        e1.eventHandler(event, window);
                    } else if (openedTab == "Add Income") {
                        i1.eventHandler(event, window);
                    } else if (openedTab == "Forex") {
                        f1.eventHandler(event, window);
                    }
                    else if(openedTab == "See Report"){
                        if(sr1.seeReportBool() == false){
                            sr1.valueAssigner();
                            sr1.drawer();
                            sr1.setReportBool(true);
                        }

                        sr1.eventHandler(event, window);
                    }
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (s1.isMouseOverTab(window)) {
                            //nothing needs to be done
                        }
                        else if(s1.isMouseOverBackup(window)){
                            std::cout<<"cout: backup button clicked"<<std::endl;
                            backup_network_sa();
                        }
                        else if(s1.isMouseOverLogout(window)){
                            l1.setTextBoxEmpty();
                            l1.setIsAuth(false);
                            d1.dashBool(false);
                            sr1.setReportBool(false);
                            std::cout<<"cout: logout button clicked"<<std::endl;
                        }
                    }
                }
            }
        }

        window.clear(sf::Color::White);    //clearing with color makes the background color of window as specified

        if (l1.isLoggedIn() == false && Util_SignupMode == false) {
            l1.drawTo(window);
        } else if (Util_SignupMode == true) {
            su1.drawTo(window);
        } else {
            s1.drawTo(window);
            if (openedTab == "Dashboard") {
                d1.drawTo(window);
            } else if (openedTab == "Add Expense") {
                e1.drawTo(window);
            } else if (openedTab == "Add Income") {
                i1.drawTo(window);
            } else if (openedTab == "Forex") {
                f1.drawTo(window);
            } else if (openedTab == "See Report") {
                sr1.drawTo(window);
            }
        }

        window.display();    //actually displaying things that is drawn in buffer
    }
}