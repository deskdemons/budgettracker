#ifndef GUIPIECHART_H
#define GUIPIECHART_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "../banner/banner.h"

#define PI 3.14159265

class GuiPieChart {
    float unitDegree;   //pi/180
    int length;         //length depends upon the length of vector of percentages passes. {20,40,15,25}. here length 4. length is used to loop to make chart
    double radius;      //radius of piechart
    sf::Vector2f position;  //position in x,y of center of piechart
    std::vector<sf::Color> colors;  //vector of color . length of this vector should be equal to length of percentage
    std::vector<double> percentages;    //percentages like: std::Vector<double> per = ({20,40,15,25});. need to use push_back for making vector in c++98
    std::vector<std::string> labelTexts;    //label text of corresponding percentages. length should be same as percentage
    sf::Vector2f labelPosition; //absolute position in x,y in vector2f format of starting cornor of label
    sf::Vector2f labelBoxDimension; //label colorful box dimenstion in width, height
    int labelVerticalSpacing;   //vertical space between consecutive labels
    int labelBoxRadius; //cornor radius of curvature of labelbox
    sf::Font labelFont; //font of label
    int labelFontSize;  //font size of label
    sf::Color labelFontColor;   //font color of label
    int labelBoxOutLineThickness;   //labelbox outline border thickness
    sf::Color labelBoxOutLineColor; //labelBox border color

    sf::VertexArray *fan;   //dynamic array of vertex array for multiple triangle fan
    Banner *pieLabels;  //dynamic array of banner class for multiple labels

public:
    GuiPieChart();  //default constructor
    GuiPieChart(double radius, sf::Vector2f centerPosition, std::vector<sf::Color> colors,
                std::vector<double> percentages, std::vector<std::string> labelsText, sf::Vector2f labelPosition,
                sf::Vector2f labelBoxDimension, int labelVerticalSpacing, int labelBoxRadius, sf::Font &labelFont,
                int labelFontSize, sf::Color labelFontColor, int labelBoxOutLineThickness,
                sf::Color labelBoxOutLineColor); //non default constructor
    //below are corresponding setter of above variable. you can easily see the parameter names
    void setRadius(double radius);

    void setPosition(sf::Vector2f centerPosition);  // position of center of pie-chart
    void setColor(
            std::vector<sf::Color> colorsVector);   //example: std::vector<std::string> col = ({sf::Color::Red, sf::Color(144,55,22)});. have to use push_back to make vector in c++98
    void setPercentages(std::vector<double> percentages);   //example: std::vector<double> per = ({60,40});

    void setLabelTexts(
            std::vector<std::string> labelTexts);    //example: std::vector<std::string> labtxt = ({"clothing","bus fair"});
    void setLabelPosition(sf::Vector2f labelPosition);  //absolute position of a bunch of label texts
    void setLabelBoxDimension(sf::Vector2f labelBoxDimension);

    void setLabelVerticalSpacing(int labelVerticalSpacing);

    void setLabelBoxRadius(int labelBoxRadius);

    void setLabelFont(sf::Font &labelFont);

    void setLabelFontSize(int labelFontSize);

    void setLabelFontColor(sf::Color labelFontColor);

    void setLabelBoxOutLineThickness(int labelBoxOutlineThickness);

    void setLabelBoxOutlineColor(sf::Color labelBoxOutLineColor);


    void drawer();

    void drawTo(sf::RenderWindow &);
};


#endif
