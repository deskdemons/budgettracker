#pragma once
#ifndef GUIBARGRAPH_H
#define GUIBARGRAPH_H

#include<iostream>
#include <SFML\Graphics.hpp>
#include "../banner/banner.h"

class GuiBarGraph {
    sf::Vector2f position;	//position of top left cornor of bargraph. i.e, top of vertical scale of graph
    int length; //length of  values. basically how many bars are there. it is set first through constructor calculating the length of values passed
    int barWidth;	//width of bar
    int barSpacing;	//width of space between bars
    int barMaxHeight;	//height of highest bar
    std::vector<double> values; //vector of values of bar. values are basically used for magnitude of the bar height. Length of values, colors, and eachbarbottomtitle vectors should be same
    std::vector<sf::Color> colors;	//vector of colors of corresponding bars
    std::vector<std::string> eachBarBottomTitle;	//vector of bottom title below each bar.

    //not direct variables. these variable is formed by operation on class variables
    int totalWidth; //calculated and assigned inside constructor. used for position of labels
    std::vector<std::string> unrepeatedLabelTexts;  //vector of string of unique/unrepeated label texts. It is automatically assigned in drawer
    std::vector<sf::Color> unrepeatedColors;    //vector of string of unique/unrepeated colors. It is automatically assigned in drawer

    //common properties of all bar in a graph
    int barRadius;  //radius of corners of bars
    sf::Font titleFont; //font of bar bottom title
    int titleFontSize;  //font size of bottom title
    sf::Color titleFontColor;//font color of bottom title
    int barOutLineThickness;    //bar outline thickness
    sf::Color barOutLineColor;  //bar outline color
    int titlePaddingLeft;   //bottom title padding left //assigned using std::vector2f(titlepaddingLeft, titlepadidng right)
    int titlePaddingTop;    //bottom title padding right    //assigned using std::vector2f(titlepaddingLeft, titlepadidng right)

    //properties of label
    bool toggleLabel;   //should label be visible or not
    std::vector<std::string> labelTexts; //should depend upon different no. of unique colors
    sf::Vector2f labelPosition; //absolute position in x,y in vector2f format of starting cornor of label
    sf::Vector2f labelBoxDimension; //label colorful box dimenstion in width, height
    int labelVerticalSpacing;   //vertical space between consecutive labels
    int labelBoxRadius; //cornor radius of curvature of labelbox
    sf::Font labelFont; //font of label
    int labelFontSize;  //font size of label
    sf::Color labelFontColor;   //font color of label
    int labelBoxOutLineThickness;   //labelbox outline border thickness
    sf::Color labelBoxOutLineColor; //labelBox outline border color

    //bartop text properties
    sf::Font barTopTextFont;    //bartoptext font. bartoptext represents the magnitude of the bar
    int barTopTextFontSize;     //bar top text font size
    sf::Color barTopTextFontColor;  //bartop text font color

    sf::Color verticalAxisColor;    //vertical axis scale color
    sf::Color horizontalAxisColor;  //horizontal axis scale color


    Banner *bars;	//the actual bars. the text of this banner is used as title of each bar
    Banner *labels;	//label is labeling the color of bar
    sf::Text *barTopTexts;	// text on top of each bar signifying the magnitude/amplitude of bar
    sf::RectangleShape verticalScaleLine;	//vertical scale of bar
    sf::RectangleShape horizontalScaleLine;	//horizontal scale of bar

public:
    GuiBarGraph();  //only default constructor available. default values are assigned in the defination of this constructor in cpp file. Non-default constructor is so redundant
    //GuiBarGraph(int barWidth, int barSpacing, int barMaxHeight, std::vector<double> values, std::vector<sf::Color>, std::vector<std::string> eachBarBottomTitle, std::vector<std::string> labelTexts, sf::Vector2f position, sf::Vector2f labelBoxDimension, int labelVerticalSpacing, int labelBoxRadius, sf::Font& labelFont, int labelFontSize, sf::Color labelFontColor, int labelBoxOutLineThickness, sf::Color labelBoxOutLineColor);

    //must set values for customized bar graph
    void setBarValues(std::vector<double> barValues);   //vector of values of bar. for ex: std::vector<double> barVal = ({2000,4000,1000,8000}); values are basically used for magnitude of the bar height. Length of values, colors, and eachbarbottomtitle vectors should be same
    void setBarColors(std::vector<sf::Color> colors);   //for ex: std::vector<sf::Color> col = ({sf::Color::Red,sf::Color::Blue,sf::Color::Green,sf::Color::Yellow});
    void setEachBarBottomTitle(std::vector<std::string> eachBarBottomTitle); //for ex: std::vector<std::string> bottomtitle = ({"Jan","Feb","Mar","Apr});
    void setLabelTexts(std::vector<std::string> labelTexts);    //example: std::vector<std::string> labtxt = ({"clothing","bus fair"});
    // these were must set values for customized bar graph

    void setPosition(sf::Vector2f position);    // ex: sf::Vector2f(200, 100).  sets the position of the top left cornor cor bar graph, i.e, the top of vertical scale
    void setBarWidth(int barWidth); // width of each bar. single value common for all bar
    void setBarSpacing(int barSpacing); //  space between each bar
    void setBarMaxHeight(int barMaxHeight); // set what should be height of tallest bar. other values like scale dimension depends upon max Height

    void setBarRadius(int barRadius);   //set radius of corners of bar
    void setTitleFont(sf::Font titleFont);  //set font of bottom titles of bar
    void setTitleFontSize(int titleFontSize);   //set font size of bottom titles for bar
    void setTitleFontColor(sf::Color titleFontColor); //set font color of bottom titles for bar
    void setBarOutLineThickness(int barOutLineThickness);//set bar border thickness
    void setBarOutLineColor(sf::Color barOutLineColor); //set bar border color
    void setTitlePadding(sf::Vector2f titlePadding);    //ex: sf::Vector(10, 10)  . set padding to left and top for bottom title of bar.

    void setLabelPosition(sf::Vector2f labelPosition);  //absolute position of a bunch of label texts
    void setLabelBoxDimension(sf::Vector2f labelBoxDimension);  //ex:: sf::Vector2f(16,16) .label box dimension width, height
    void setLabelVerticalSpacing(int labelVerticalSpacing); // vertical spacing between each label
    void setLabelBoxRadius(int labelBoxRadius); // label box radius
    void setLabelFont(sf::Font& labelFont); //label font
    void setLabelFontSize(int labelFontSize);   //label font size
    void setLabelFontColor(sf::Color labelFontColor);   //label font Color
    void setLabelBoxOutLineThickness(int labelBoxOutlineThickness); //label box outline thickness
    void setLabelBoxOutlineColor(sf::Color labelBoxOutLineColor);   //label box outline color

    void setBarTopTextFont(sf::Font barTopTextFont);    //text on top of each bar. its font. actual bar top text is just magnitude of the bar
    void setBarTopTextFontSize(int barTopTextFontSize); //text on top of each bar. its font size
    void setBarTopTextFontColor(sf::Color barTopTextFontColor); //text on top of each bar. its font color

    void setVerticalScaleColor(sf::Color verticalScaleColor);   //vertical axis scale color
    void setHorizontalScaleColor(sf::Color horizontalScaleColor);   //horizontal axis scale color

    void setToggleLabel(bool toggleLabel);  //turn visibility of label on or off using bool

    void drawer();  //it contains logic of how things have to be drawn
    void drawTo(sf::RenderWindow& window);  //just draws bar graph in buffer. note that we need to display drawn artifacts into the screen too, from main.cpp file
};

#endif