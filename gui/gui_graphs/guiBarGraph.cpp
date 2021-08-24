#include "guiBarGraph.h"
#include <sstream>

GuiBarGraph::GuiBarGraph() { //default constructor
    position = sf::Vector2f(100, 100);
    barWidth = 40;
    barSpacing = 20;
    barMaxHeight = 150;
    std::vector<double> val;
    val.push_back(1000);
    val.push_back(500);
    val.push_back(700);
    val.push_back(900);
    values = val;

    length = val.size();


    sf::Color arrCol[] = {sf::Color::Red, sf::Color::Green, sf::Color::Yellow, sf::Color::Blue, sf::Color::Magenta,
                          sf::Color::Cyan, sf::Color::Black, sf::Color(235, 164, 52), sf::Color(52, 235, 168),
                          sf::Color(201, 20, 126), sf::Color(69, 120, 230), sf::Color(219, 105, 39)};
    std::vector<sf::Color> col;
    for (int i = 0; i < sizeof(arrCol) / sizeof(arrCol[0]); i++)
        col.push_back(arrCol[i]);
    colors = col;


    unrepeatedColors = col;

    std::string txtBottom[] = {"Bottom 1", "Bottom 2", "Bottom 3", "bottom 4", "Bottom 5", "Bottom 6", "Bottom 7",
                               "Bottom 8", "Bottom 9", "Bottom 10", "Bottom 11", "Bottom 12"};
    std::vector<std::string> bottomText;
    for (int k = 0; k < sizeof(txtBottom) / sizeof(txtBottom[0]); k++)
        bottomText.push_back(txtBottom[k]);

    eachBarBottomTitle = bottomText;


    //bottom title
    barRadius = 0;
    titleFont.loadFromFile("Roboto-Regular.ttf");
    titleFontSize = 10;
    titleFontColor = sf::Color::Black;
    barOutLineThickness = 0;
    titlePaddingLeft = 0;
    titlePaddingTop = 10;

    std::string txtLab[] = {"LabelText 1", "LabelText 2", "LabelText 3", "LabelText 4"};
    std::vector<std::string> labText;
    for (int k = 0; k < sizeof(txtLab) / sizeof(txtLab[0]); k++)
        labText.push_back(txtLab[k]);
    labelTexts = labText;

    unrepeatedLabelTexts = labText;

    totalWidth = (barWidth + barSpacing) * length; //unit space * length = total width
    labelPosition = sf::Vector2f(position.x + totalWidth + (0.1f * (barWidth + barSpacing) * length), position.y + 10);
    labelBoxDimension = sf::Vector2f(20, 20);
    labelVerticalSpacing = 40;
    labelBoxRadius = 3;
    labelFont.loadFromFile("arial.ttf");
    labelFontSize = 20;
    labelFontColor = sf::Color::Black;
    labelBoxOutLineThickness = 1;
    labelBoxOutLineColor = sf::Color::Black;

    //bar top text properties
    barTopTextFont.loadFromFile("Roboto-Regular.ttf");
    barTopTextFontSize = 10;
    barTopTextFontColor = sf::Color::Black;

    //vertical and horizontal axis;
    verticalAxisColor = sf::Color::Black;
    horizontalAxisColor = sf::Color::Black;

    toggleLabel = false;

    bars = new Banner[length];
    labels = new Banner[colors.size()];
    barTopTexts = new sf::Text[length];
    drawer();
}
//GuiBarGraph::GuiBarGraph() {

//}

std::string doubleToStringBar(double num) {
    std::stringstream ss;
    std::string str;
    ss << num;
    ss >> str;
    return str;
}

void GuiBarGraph::drawer() {
    //vertical and horizontal axis of graph
    verticalScaleLine.setPosition(position);
    verticalScaleLine.setSize(sf::Vector2f(2, barMaxHeight + (barMaxHeight * 0.1)));
    verticalScaleLine.setFillColor(verticalAxisColor);
    horizontalScaleLine.setPosition(sf::Vector2f(position.x, position.y + barMaxHeight + (barMaxHeight * 0.1f)));
    horizontalScaleLine.setSize(
            sf::Vector2f((barWidth + barSpacing) * length + (0.1f * (barWidth + barSpacing) * length), 2));
    horizontalScaleLine.setFillColor(horizontalAxisColor);


    //each bar and bottom title properties
    double maxVal = 0.0;
    for (int j = 0; j < length; j++) {
        if (values[j] > maxVal)
            maxVal = values[j];
    }

    for (int c = 0; c < values.size(); c++) {
        double eachBarHeight = (values[c] / maxVal) * barMaxHeight;
        //bars and its bottom title
        bars[c].setBannerText(eachBarBottomTitle[c]);
        bars[c].setPosition(sf::Vector2f(position.x + barSpacing + ((barSpacing + barWidth) * c),
                                         position.y + (0.1 * barMaxHeight) + barMaxHeight - eachBarHeight));
        bars[c].setDimension(sf::Vector2f(barWidth, eachBarHeight));
        bars[c].setRadius(barRadius);
        bars[c].setFont(titleFont);
        bars[c].setFontSize(titleFontSize);
        bars[c].setFontColor(titleFontColor);
        bars[c].setBgColor(colors[c]);
        bars[c].setOutLineThickness(barOutLineThickness);
        bars[c].setOutLineColor(barOutLineColor);
        bars[c].setPadding(titlePaddingLeft, titlePaddingTop + (eachBarHeight / 2));

        //texts on top of each bar
        barTopTexts[c].setString(doubleToStringBar(values[c]));
        barTopTexts[c].setPosition(sf::Vector2f(position.x + barSpacing + ((barSpacing + barWidth) * c),
                                                position.y + (0.1 * barMaxHeight) + barMaxHeight - eachBarHeight -
                                                (barTopTextFontSize * 1.5f)));
        barTopTexts[c].setFont(barTopTextFont);
        barTopTexts[c].setCharacterSize(barTopTextFontSize);
        barTopTexts[c].setFillColor(barTopTextFontColor);

    }

    //for label

    std::vector<std::string> labelTxts;                                         //problems in piechart yet to be solved //there might not be problem actually. but still experiment with piechart

    labelTxts.push_back(labelTexts[0]);
    int b;
    for (int i = 1; i < labelTexts.size(); i++) {

        b = 0;
        for (int j = 0; j < labelTxts.size(); j++) {
            if (labelTxts[j] == labelTexts[i])
                b++;
        }
        if (b == 0)
            labelTxts.push_back(labelTexts[i]);
    }

    unrepeatedLabelTexts = labelTxts;

    std::vector<sf::Color> labelCol;

    labelCol.push_back(colors[0]);
    int d;
    for (int i = 1; i < colors.size(); i++) {

        d = 0;
        for (int j = 0; j < labelCol.size(); j++) {
            if (labelCol[j] == colors[i])
                d++;
        }
        if (d == 0)
            labelCol.push_back(colors[i]);
    }

    unrepeatedColors = labelCol;

    if (toggleLabel) {
        for (int l = 0; l < unrepeatedLabelTexts.size(); l++) {
            labels[l];
            labels[l].setBannerText(labelTxts[l]);
            labels[l].setPosition(sf::Vector2f(labelPosition.x, labelPosition.y + (labelVerticalSpacing * l)));
            labels[l].setDimension(labelBoxDimension);
            labels[l].setRadius(labelBoxRadius);
            labels[l].setFont(labelFont);
            labels[l].setFontSize(labelFontSize);
            labels[l].setFontColor(labelFontColor);
            labels[l].setBgColor(unrepeatedColors[l]);
            labels[l].setOutLineThickness(labelBoxOutLineThickness);
            labels[l].setOutLineColor(labelBoxOutLineColor);
            labels[l].setPadding(30, 0);
        }
    }

}   //end of drawer

void GuiBarGraph::setToggleLabel(bool toggleLabel) {
    this->toggleLabel = toggleLabel;
    drawer();
}

void GuiBarGraph::setBarValues(std::vector<double> barValues) {
    this->values = barValues;
    length = barValues.size();
    bars = new Banner[length];
    barTopTexts = new sf::Text[length]; //new array having length no. of elements
    totalWidth = (barWidth + barSpacing) * length;
    labelPosition = sf::Vector2f(position.x + totalWidth + (0.1f * (barWidth + barSpacing) * length), position.y + 10);
    drawer();
}

void GuiBarGraph::setBarColors(std::vector<sf::Color> barColors) {
    this->colors = barColors;
    labels = new Banner[colors.size()];
    drawer();
}

void GuiBarGraph::setEachBarBottomTitle(std::vector<std::string> eachBarBottomTitle) {
    this->eachBarBottomTitle = eachBarBottomTitle;
    drawer();
}

void GuiBarGraph::setPosition(sf::Vector2f position) {
    this->position = position;
    labelPosition = sf::Vector2f(position.x + totalWidth + (0.1f * (barWidth + barSpacing) * length), position.y + 10);
    drawer();
}

void GuiBarGraph::setBarWidth(int barWidth) {
    this->barWidth = barWidth;
    totalWidth = (barWidth + barSpacing) * length;
    labelPosition = sf::Vector2f(position.x + totalWidth + (0.1f * (barWidth + barSpacing) * length), position.y + 10);
    drawer();
}

void GuiBarGraph::setBarSpacing(int barSpacing) {
    this->barSpacing = barSpacing;
    totalWidth = (barWidth + barSpacing) * length;
    labelPosition = sf::Vector2f(position.x + totalWidth + (0.1f * (barWidth + barSpacing) * length), position.y + 10);
    drawer();
}

void GuiBarGraph::setBarMaxHeight(int barMaxHeight) {
    this->barMaxHeight = barMaxHeight;
    drawer();
}

void GuiBarGraph::setBarRadius(int barRadius) {
    this->barRadius = barRadius;
    drawer();
}


//bottom title
void GuiBarGraph::setTitleFont(sf::Font titleFont) {
    this->titleFont = titleFont;
    drawer();
}

void GuiBarGraph::setTitleFontSize(int titleFontSize) {
    this->titleFontSize = titleFontSize;
    drawer();
}

void GuiBarGraph::setTitleFontColor(sf::Color titleFontColor) {
    this->titleFontColor = titleFontColor;
    drawer();
}

void GuiBarGraph::setBarOutLineThickness(int barOutLineThickness) {
    this->barOutLineThickness = barOutLineThickness;
    drawer();
}

void GuiBarGraph::setBarOutLineColor(sf::Color barOutLineColor) {
    this->barOutLineColor = barOutLineColor;
    drawer();
}

void GuiBarGraph::setTitlePadding(sf::Vector2f titlePadding) {
    this->titlePaddingLeft = titlePadding.x;
    this->titlePaddingTop = titlePadding.y;
    drawer();
}

//label representing color
void GuiBarGraph::setLabelTexts(std::vector<std::string> labelTexts) {
    this->labelTexts = labelTexts;
    //labels = new Banner[colors.size()];
    drawer();
}

void GuiBarGraph::setLabelPosition(sf::Vector2f labelPosition) {
    this->labelPosition = labelPosition;
    drawer();
}

void GuiBarGraph::setLabelBoxDimension(sf::Vector2f labelBoxDimension) {
    this->labelBoxDimension = labelBoxDimension;
    drawer();
}

void GuiBarGraph::setLabelVerticalSpacing(int labelVerticalSpacing) {
    this->labelVerticalSpacing = labelVerticalSpacing;
    drawer();
}

void GuiBarGraph::setLabelBoxRadius(int labelBoxRadius) {
    this->labelBoxRadius = labelBoxRadius;
    drawer();
}

void GuiBarGraph::setLabelFont(sf::Font &labelFont) {
    this->labelFont = labelFont;
    drawer();
}

void GuiBarGraph::setLabelFontSize(int labelFontSize) {
    this->labelFontSize = labelFontSize;
    drawer();
}

void GuiBarGraph::setLabelFontColor(sf::Color labelFontColor) {
    this->labelFontColor = labelFontColor;
    drawer();
}

void GuiBarGraph::setLabelBoxOutLineThickness(int labelBoxOutlineThickness) {
    this->labelBoxOutLineThickness = labelBoxOutLineThickness;
    drawer();
}

void GuiBarGraph::setLabelBoxOutlineColor(sf::Color labelBoxOutLineColor) {
    this->labelBoxOutLineColor = labelBoxOutLineColor;
    drawer();
}


void GuiBarGraph::setBarTopTextFont(sf::Font barTopTextFont) {
    this->barTopTextFont = barTopTextFont;
    drawer();
}

void GuiBarGraph::setBarTopTextFontSize(int barTopTextFontSize) {
    this->barTopTextFontSize = barTopTextFontSize;
    drawer();
}

void GuiBarGraph::setBarTopTextFontColor(sf::Color barTopTextFontColor) {
    this->barTopTextFontColor = barTopTextFontColor;
    drawer();
}

void GuiBarGraph::setVerticalScaleColor(sf::Color verticalScaleColor) {
    this->verticalAxisColor = verticalScaleColor;
    drawer();
}

void GuiBarGraph::setHorizontalScaleColor(sf::Color horizontalScaleColor) {
    this->horizontalAxisColor = horizontalScaleColor;
    drawer();
}

void GuiBarGraph::drawTo(sf::RenderWindow &window) {
    window.draw(verticalScaleLine);
    window.draw(horizontalScaleLine);
    for (int b = 0; b < values.size(); b++)
        bars[b].drawTo(window);
    for (int v = 0; v < values.size(); v++)
        window.draw(barTopTexts[v]);
    if (toggleLabel) {
        for (int l = 0; l < unrepeatedLabelTexts.size(); l++)
            labels[l].drawTo(window);
    }
}