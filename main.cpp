#include<iostream>
#include <SFML/Graphics.hpp>
#include "gui/sidebar/sidebar.h"
#include "pages/login_page/login_page.h"
#include "pages/signup_page/signup_page.h"
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
    settings.antialiasingLevel = 8;	// for smoother graphics
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 640, (sf::VideoMode::getDesktopMode().height / 2) - 360);
    window.create(sf::VideoMode(1280, 720), "setBudGet", sf::Style::Default, settings);
    window.setPosition(centerWindow);	//centerwindow is defined above. it's position is set so that the window is displayed symmetrically on the screen
    window.setKeyRepeatEnabled(true);

    Sidebar s1;
    LoginPage l1;
    SignupPage su1;
    DashboardPage d1;
    AddExpensePage e1;
    AddIncomePage i1;
    ForexPage f1;
    SeeReportPage sr1;

    while (window.isOpen()) {	//this is always true when program is run. it is only false when program closes
        sf::Event event;
        std::string openedTab = s1.getChosenTab();
        while (window.pollEvent(event)) {	//it is analogous to fps. polling means recording the events many times per second continuously while the program runs
            if(event.type == sf::Event::Closed){
                window.close();
            }
            else{
                if(l1.isLoggedIn() == false && Util_SignupMode == false){
                    l1.eventHandler(event, window);
                } else if (Util_SignupMode == true)
                {
                    su1.eventHandler(event,window);
                }
                else{
                    if(event.type == sf::Event::MouseButtonPressed){
                        if(s1.isMouseOverTab(window)){
                            //nothing needs to be done
                        }
                        else if(s1.isMouseOverBackup(window)){
                            std::cout<<"cout: backup button clicked"<<std::endl;
                        }
                        else if(s1.isMouseOverLogout(window)){
                            std::cout<<"cout: logout button clicked"<<std::endl;
                        }
                    }
                    if(openedTab == "Dashboard"){
                        d1.eventHandler(event, window);
                        //d1.drawer();
                    }
                    else if(openedTab == "Add Expense"){
                        e1.eventHandler(event, window);
                    }
                    else if(openedTab == "Add Income"){
                        i1.eventHandler(event, window);
                    }
                    else if(openedTab == "Forex"){
                        f1.eventHandler(event, window);
                    }
                    else if(openedTab == "See Report"){
                        sr1.eventHandler(event, window);
                    }
                }
            }
        }

        window.clear(sf::Color::White);	//clearing with color makes the background color of window as specified

        if(l1.isLoggedIn() == false && Util_SignupMode == false){
            l1.drawTo(window);
        }
        else if (Util_SignupMode    == true){
            su1.drawTo(window);
        }
        else{
            s1.drawTo(window);
            if(openedTab == "Dashboard"){
                d1.drawTo(window);
            }
            else if(openedTab == "Add Expense"){
                e1.drawTo(window);
            }
            else if(openedTab == "Add Income"){
                i1.drawTo(window);
            }
            else if(openedTab == "Forex"){
                f1.drawTo(window);
            }
            else if(openedTab == "See Report"){
                sr1.drawTo(window);
            }
        }

        window.display();	//actually displaying things that is drawn in buffer

    }
}