#include "guiPieChart.h"
#include<cmath>
#include <sstream>

GuiPieChart::GuiPieChart() {

    sf::Color arrCol[] = {sf::Color::Red, sf::Color::Green, sf::Color::Yellow, sf::Color::Blue, sf::Color::Magenta,
                          sf::Color::Cyan, sf::Color::Black, sf::Color(235, 164, 52), sf::Color(52, 235, 168),
                          sf::Color(201, 20, 126), sf::Color(69, 120, 230), sf::Color(219, 105, 39)};
    std::vector<sf::Color> col;
    for (int i = 0; i < sizeof(arrCol) / sizeof(arrCol[0]); i++)
        col.push_back(arrCol[i]);

    double arrPer[] = {25.0, 25.0, 25.0, 25.0};
    std::vector<double> per;
    for (int j = 0; j < sizeof(arrPer) / sizeof(arrPer[0]); j++)
        per.push_back(arrPer[j]);

    radius = 100;
    colors = col;
    position = sf::Vector2f(100, 100);
    percentages = per;

    //for label
    std::string txtLab[] = {"LabelText 1", "LabelText 2", "LabelText 3", "LabelText 4", "LabelText 5", "LabelText 6",
                            "LabelText 7", "LabelText 8", "LabelText 9", "LabelText 10", "LabelText 11",
                            "LabelText 12"};
    std::vector<std::string> labText;
    for (int k = 0; k < sizeof(txtLab) / sizeof(txtLab[0]); k++)
        labText.push_back(txtLab[k]);

    labelTexts = labText;
    labelPosition = sf::Vector2f(position.x + radius + 20, position.y - radius + 20);
    labelBoxDimension = sf::Vector2f(20, 20);
    labelVerticalSpacing = 40;
    labelBoxRadius = 3;
    labelFont.loadFromFile("arial.ttf");
    labelFontSize = 20;
    labelFontColor = sf::Color::Black;
    //label box background color is same as corresponding piechart color
    labelBoxOutLineThickness = 1;
    labelBoxOutLineColor = sf::Color::Black;


    length = percentages.size();
    unitDegree = PI / 180.0;
    fan = new sf::VertexArray[length];
    pieLabels = new Banner[length];

    drawer();
}

GuiPieChart::GuiPieChart(double radius, sf::Vector2f centerPosition, std::vector<sf::Color> colors,
                         std::vector<double> percentages, std::vector<std::string> labelTexts,
                         sf::Vector2f labelPosition, sf::Vector2f labelBoxDimension, int labelVerticalSpacing,
                         int labelBoxRadius, sf::Font &labelFont, int labelFontSize, sf::Color labelFontColor,
                         int labelBoxOutLineThickness, sf::Color labelBoxOutLineColor) {
    this->radius = radius;
    this->position = centerPosition;
    this->colors = colors;
    this->percentages = percentages;

    this->labelTexts = labelTexts;
    this->labelPosition = labelPosition;
    this->labelBoxDimension = labelBoxDimension;
    this->labelVerticalSpacing = labelVerticalSpacing;
    this->labelBoxRadius = labelBoxRadius;
    this->labelFont = labelFont;
    this->labelFontSize = labelFontSize;
    this->labelFontColor = labelFontColor;
    //label box background color is same as corresponding piechart color
    this->labelBoxOutLineThickness = labelBoxOutLineThickness;
    this->labelBoxOutLineColor = labelBoxOutLineColor;

    length = percentages.size();
    unitDegree = PI / 180.0;
    fan = new sf::VertexArray[length];
    pieLabels = new Banner[length];
    drawer();
}

std::string doubleToStringGui(double num) {
    std::stringstream ss;
    std::string str;
    ss << num;
    ss >> str;
    return str;
}

void GuiPieChart::drawer() {
    length = percentages.size();
    double l = 0;
    int m = 0;
    double h = 0;
    double c = 0;
    int d = 0;

    for (int i = 0; i < length; i++) {
        l += percentages[i];
        h = (percentages[i] / 100.0) * 360.0;
        c = (l / 100.0) * 360.0;
        fan[i] = sf::VertexArray(sf::TriangleFan, round(h) + 1);
        fan[i][0].position = sf::Vector2f(position.x, position.y);
        fan[i][0].color = colors[i];
        int k = 0;
        for (int j = m; j < round(c); j++) {
            fan[i][k + 1].position = sf::Vector2f(position.x + (radius * sin(j * unitDegree)),
                                                  position.y + (radius * cos(j * unitDegree)));
            fan[i][k + 1].color = colors[i];
            k++;
            d = j;
        }
        m = d + 1;

        //making labels

        pieLabels[i];
        pieLabels[i].setBannerText(doubleToStringGui(percentages[i]) + "% : " + labelTexts[i]);
        pieLabels[i].setPosition(sf::Vector2f(labelPosition.x, labelPosition.y + (labelVerticalSpacing * i)));
        pieLabels[i].setDimension(labelBoxDimension);
        pieLabels[i].setRadius(labelBoxRadius);
        pieLabels[i].setFont(labelFont);
        pieLabels[i].setFontSize(labelFontSize);
        pieLabels[i].setFontColor(labelFontColor);
        pieLabels[i].setBgColor(colors[i]);
        pieLabels[i].setOutLineThickness(labelBoxOutLineThickness);
        pieLabels[i].setOutLineColor(labelBoxOutLineColor);
        pieLabels[i].setPadding(30, 0);
    }
}

void GuiPieChart::setRadius(double radius) {
    this->radius = radius;
    labelPosition = sf::Vector2f(position.x + radius + 20, position.y - radius + 20);
    drawer();
}

void GuiPieChart::setPosition(sf::Vector2f centerPosition) {
    this->position = centerPosition;
    labelPosition = sf::Vector2f(centerPosition.x + radius + 20, centerPosition.y - radius + 10);
    drawer();
}

void GuiPieChart::setColor(std::vector<sf::Color> colorsVector) {
    this->colors = colorsVector;
    drawer();
}

void GuiPieChart::setPercentages(std::vector<double> percentages) {
    this->percentages = percentages;
    length = percentages.size();
    fan = new sf::VertexArray[length];
    pieLabels = new Banner[length];
    drawer();
}

void GuiPieChart::setLabelTexts(std::vector<std::string> labelTexts) {
    this->labelTexts = labelTexts;
    drawer();
}

void GuiPieChart::setLabelPosition(sf::Vector2f labelPosition) {
    this->labelPosition = labelPosition;
    drawer();
}

void GuiPieChart::setLabelBoxDimension(sf::Vector2f labelBoxDimension) {
    this->labelBoxDimension = labelBoxDimension;
    drawer();
}

void GuiPieChart::setLabelVerticalSpacing(int labelVerticalSpacing) {
    this->labelVerticalSpacing = labelVerticalSpacing;
    drawer();
}

void GuiPieChart::setLabelBoxRadius(int labelBoxRadius) {
    this->labelBoxRadius = labelBoxRadius;
    drawer();
}

void GuiPieChart::setLabelFont(sf::Font &labelFont) {
    this->labelFont = labelFont;
    drawer();
}

void GuiPieChart::setLabelFontSize(int labelFontSize) {
    this->labelFontSize = labelFontSize;
    drawer();
}

void GuiPieChart::setLabelFontColor(sf::Color labelFontColor) {
    this->labelFontColor = labelFontColor;
    drawer();
}

void GuiPieChart::setLabelBoxOutLineThickness(int labelBoxOutlineThickness) {
    this->labelBoxOutLineThickness = labelBoxOutlineThickness;
    drawer();
}

void GuiPieChart::setLabelBoxOutlineColor(sf::Color labelBoxOutLineColor) {
    this->labelBoxOutLineColor = labelBoxOutLineColor;
    drawer();
}

void GuiPieChart::drawTo(sf::RenderWindow &window) {
    for (int w = 0; w < length; w++)
        pieLabels[w].drawTo(window);
    for (int v = 0; v < length; v++)
        window.draw(fan[v]);
}
