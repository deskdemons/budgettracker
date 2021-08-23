#include<iostream>
#include <SFML/Graphics.hpp>
#include "gui/sidebar/sidebar.h"
#include "pages/login_page/login_page.h"
#include "pages/dashboard_page//dashboard_page.h"

int main() {

    sf::RenderWindow window;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;	// for smoother graphics
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 640, (sf::VideoMode::getDesktopMode().height / 2) - 360);
    window.create(sf::VideoMode(1280, 720), "setBudGet", sf::Style::Default, settings);
    window.setPosition(centerWindow);	//centerwindow is defined above. it's position is set so that the window is displayed symmetrically on the screen
    window.setKeyRepeatEnabled(true);

    Sidebar s1;
    LoginPage l1;
    DashboardPage d1;

    while (window.isOpen()) {	//this is always true when program is run. it is only false when program closes
        sf::Event event;
        std::string openedTab = s1.getChosenTab();
        while (window.pollEvent(event)) {	//it is analogous to fps. polling means recording the events many times per second continuously while the program runs
            if(event.type == sf::Event::Closed){
                window.close();
            }
            else{
                if(l1.isLoggedIn() == false){
                    l1.eventHandler(event, window);
                }else{
                    if(openedTab == "Dashboard"){
                        d1.eventHandler(event, window);
                    }
                    else{
                    //other pages logic in else if
                    }
                }
            }
        }

        window.clear(sf::Color::White);	//clearing with color makes the background color of window as specified

        if(l1.isLoggedIn() == false){
            l1.drawTo(window);
        }
        else{
            if(openedTab == "Dashboard"){
                d1.drawTo(window);
            }
            else{
                //other pages logic in else if
            }
        }

        window.display();	//actually displaying things that is drawn in buffer

    }
}