#include<iostream>
#include <SFML/Graphics.hpp>
#include "cclasses/sfmlGraphics/textbox.h"
#include "cclasses/sfmlGraphics/button.h"
#include "cclasses/sfmlGraphics/textBoxBg.h"
#include "cclasses/sfmlGraphics/banner.h"

int main() {

    sf::RenderWindow window;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;	// for smoother graphics
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 640, (sf::VideoMode::getDesktopMode().height / 2) - 360);
    window.create(sf::VideoMode(1280, 720), "setBudGet", sf::Style::Default, settings);
    window.setPosition(centerWindow);	//centerwindow is defined above. it's position is set so that the window is displayed symmetrically on the screen
    window.setKeyRepeatEnabled(true);
    Textbox text4();
    sf::Font font;		//font for normal text
    sf::Font fontHint;	//font for hintText
    if (!font.loadFromFile("Roboto-Regular.ttf")) //loading font file
        std::cout << "font not found\n";
    if (!fontHint.loadFromFile("arial.ttf"))	//loading font file for hint text
        std::cout << "font not found\n";
    Textbox text1;	//object of manually defined textbox class. default constructor triggered
    Textbox text2;	//another object. default constructor triggered
    text2.setPosition(sf::Vector2f( 50, 150 ));	//setting the position. it overwrites the default position
    text2.setHintText("Username");	//hint text
    text2.setDataType("secure");	//dataType. if "normal", its normal. but if "secure", then ******
    text2.setFontColor(sf::Color::Blue);	//fontColor of text
    text2.setPadding(30, 0); //padding text w.r.t box border. negative values accepted
    //below, object of textbox class with all properties defined in the constructor
    Textbox text3(sf::Vector2f(  50,250 ), sf::Vector2f( 400, 70), 10,"password",fontHint, 30, sf::Color::Magenta,"secure", font, 30, 20, sf::Color(100, 0, 0), sf::Color(190, 190, 55), 3, sf::Color(0, 0, 0), 20, -10); //position, dimension, radius, hintText, hintFont, hintFontSize, hintFontColor,dataType, txtFont, fontSize, maxLen, txtColor, bgColor, borderThickness, borderColor, paddingLeft, paddingRight

    Button b1;	//object of manually defined button class. default constructor triggered
    b1.setPosition(sf::Vector2f( 500,500));	//setting position of button. it overwrites the default position
    b1.setBgColor(sf::Color(255, 0, 0));	//setting background color
    b1.setPadding(50, 0);	//setting padding of text as (left, top)
    b1.setButtonText("Login");
    while (window.isOpen()) {	//this is always true when program is run. it is only false when program closes
        sf::Event Event;

        while (window.pollEvent(Event)) {	//it is analogous to fps. polling means recording the events many times per second continuously while the program runs
            switch (Event.type) {
                case sf::Event::Closed:
                    window.close();	//closing window when cross button is pressed
                    break;
                    case sf::Event::TextEntered:
                        if (text1.isFocus()) {
                            text1.typedOn(Event);	//passing event to typedOn method to convert into char
                        }
                        else if (text2.isFocus()) {
                            text2.typedOn(Event);
                        }
                        else if (text3.isFocus()) {
                            text3.typedOn(Event);
                        }
                        break;
                        case sf::Event::MouseButtonPressed:
                            if (text1.isMouseOver(window)) {	//if mouse is clicked inside territory of tex1, then  focus on text 1 and defocus from others
                                text1.setSelected(true);
                                text2.setSelected(false);
                                text3.setSelected(false);
                            }
                            else if (text2.isMouseOver(window)) {	//similarly
                                text1.setSelected(false);
                                text2.setSelected(true);
                                text3.setSelected(false);
                            }
                            else if (text3.isMouseOver(window)) {	//similarly
                                text1.setSelected(false);
                                text2.setSelected(false);
                                text3.setSelected(true);
                            }
                            else if (b1.isMouseOver(window)) {	//if mouse is clicked while being above button b1
                                b1.setBgColor(sf::Color(0, 0, 155));	//change the background color
                                b1.setFontColor(sf::Color(255, 255, 255));	//change the font color
                                std::cout << "text1:" << text1.getText() << std::endl << "text2:" << text2.getText() << std::endl << "text3:" << text3.getText() <<std::endl;	//getText gives the text entered so far
                            }
                            else {								//if mouse click is not in any textbox, then remove focus from all textbox
                                text1.setSelected(false);
                                text2.setSelected(false);
                                text3.setSelected(false);
                            }
                            break;
            }
            window.clear(sf::Color(155, 155, 155));	//clearing with color makes the background color of window as specified
            text1.drawTo(window);	//drawing text by passing window by reference.
            text2.drawTo(window);	//drawTo is defined inside the manually defined class. we are passing window by reference. the actual code that draws is this way: window.draw(shape) or window.draw(textbox) or window.draw(anything)
            text3.drawTo(window);	//things should be drawn orderly, i.e, here, text3 can overlap and overshadow text2 if the have same position. things that are drawn later is drawn at top
            b1.drawTo(window);	//drawing button
            window.display();	//actually displaying things that is drawn in buffer

        }
    }
}