#include "table.h"
#include<cmath>

Table::Table() {
    //making contents
    std::vector<std::vector<std::string> > conR;
    std::vector<std::string> conC1;
    conC1.push_back("Name");
    conC1.push_back("Age");
    conC1.push_back("Laptop");
    std::vector<std::string> conC2;
    conC2.push_back("Prasiddha");
    conC2.push_back("20");
    conC2.push_back("Lenovo");
    std::vector<std::string> conC3;
    conC3.push_back("Rajeev");
    conC3.push_back("20");
    conC3.push_back("HP");
    std::vector<std::string> conC4;
    conC4.push_back("Saurav");
    conC4.push_back("19");
    conC4.push_back("Lenovo");
    std::vector<std::string> conC5;
    conC5.push_back("Prashant");
    conC5.push_back("21");
    conC5.push_back("HP");
    std::vector<std::string> conC6;
    conC6.push_back("Suyog");
    conC6.push_back("20");
    conC6.push_back("Dell");
    std::vector<std::string> conC7;
    conC7.push_back("Razesh");
    conC7.push_back("19");
    conC7.push_back("Asus");

    conR.push_back(conC1);
    conR.push_back(conC2);
    conR.push_back(conC3);
    conR.push_back(conC4);
    conR.push_back(conC5);
    conR.push_back(conC6);
    conR.push_back(conC7);
    //end of making contents

    //table properties
    position = sf::Vector2f(100, 100);

    std::vector<int> colWidth;
    colWidth.push_back(200);
    colWidth.push_back(300);
    colWidth.push_back(150);

    columnWidth = colWidth;
    headerHeight = 60;
    bodyHeight = 50;
    paddingRow = 0;
    paddingColumn = 0;
    tableLevel = 0;
    tableBodyRowNum = 4;

    //for header row
    headFont.loadFromFile("arial.ttf");
    headFontSize = 30;
    headFontColor = sf::Color::Magenta;
    headBgColor = sf::Color::Yellow;

    //for column row
    bodyFont.loadFromFile("arial.ttf");
    bodyFontSize = 20;
    bodyFontColor = sf::Color::Black;
    bodyBgColor = sf::Color::White;

    outLineThickness = 1;
    outLineColor = sf::Color::Black;
    headerPadding = sf::Vector2f(20, 0);
    bodyPadding = sf::Vector2f(20, 0);

    contents = conR;
    totalCell = conR.size() * conC1.size();
    tableCell = new Banner[totalCell];

    drawer();
}

void Table::drawer() {
    int c = 0;
    //for head
    for (int i = 0; i < 1; i++) {
        int posx = 0;
        for (int j = 0; j < contents[0].size(); j++) {
            tableCell[c].setBannerText(contents[i][j]);
            tableCell[c].setPosition(sf::Vector2f(position.x + posx, position.y + 0));
            tableCell[c].setDimension(sf::Vector2f(columnWidth[j], headerHeight));
            tableCell[c].setRadius(0);
            tableCell[c].setFont(headFont);
            tableCell[c].setFontSize(headFontSize);
            tableCell[c].setFontColor(headFontColor);
            tableCell[c].setBgColor(headBgColor);
            tableCell[c].setOutLineThickness(outLineThickness);
            tableCell[c].setOutLineColor(outLineColor);
            tableCell[c].setPadding(headerPadding.x, headerPadding.y);

            posx = posx + columnWidth[j] + paddingColumn;

            c++;
        }
        buttonPosx = position.x + posx;
    }
    //for body


    int g = (tableLevel * tableBodyRowNum) + 1;

    int y;
    int to = ceil((contents.size() - 1) / (float) tableBodyRowNum);
    int a = (contents.size() - 1) % tableBodyRowNum;
    if (tableLevel < (to - 1)) {
        y = g + tableBodyRowNum;
    } else {
        if (a == 0) {
            y = g + tableBodyRowNum;
        } else {
            y = g + a;
        }
    }

    int posy = headerHeight + paddingRow;
    for (int i = g; i < y; i++) {
        int posx = 0;
        buttonPosy = position.y + posy;
        for (int j = 0; j < contents[0].size(); j++) {
            tableCell[c].setBannerText(contents[i][j]);
            tableCell[c].setPosition(sf::Vector2f(position.x + posx, position.y + posy));
            tableCell[c].setDimension(sf::Vector2f(columnWidth[j], bodyHeight));
            tableCell[c].setRadius(0);
            tableCell[c].setFont(bodyFont);
            tableCell[c].setFontSize(bodyFontSize);
            tableCell[c].setFontColor(bodyFontColor);
            tableCell[c].setBgColor(bodyBgColor);
            tableCell[c].setOutLineThickness(outLineThickness);
            tableCell[c].setOutLineColor(outLineColor);
            tableCell[c].setPadding(bodyPadding.x, bodyPadding.y);

            posx = posx + columnWidth[j] + paddingColumn;
            c++;
        }
        posy = posy + bodyHeight + paddingRow;
    }
    totalBodyLoop = c;

    //button
    up.setPosition(sf::Vector2f(buttonPosx, position.y));
    up.setBannerText("^");
    up.setDimension(sf::Vector2f(20, 20));
    up.setPadding(3, 5);
    up.setBgColor(sf::Color(200, 200, 200));
    up.setFontSize(30);
    down.setPosition(sf::Vector2f(buttonPosx, buttonPosy + (bodyHeight - 20)));
    down.setBannerText("v");
    down.setDimension(sf::Vector2f(20, 20));
    down.setPadding(5, 0);
    down.setBgColor(sf::Color(200, 200, 200));
    down.setFontSize(20);
}

void Table::setContents(std::vector<std::vector<std::string> > contents) {
    this->contents = contents;
    totalCell = contents.size() * contents[0].size();
    tableCell = new Banner[totalCell];
    //drawer();
}

void Table::setPosition(sf::Vector2f position) {
    this->position = position;
    //drawer();
}

void Table::setTableBodyRowNum(int tableBodyRowNum) {
    this->tableBodyRowNum = tableBodyRowNum;
    //drawer();
}

void Table::setColumnWidth(std::vector<int> columnWidth) {
    this->columnWidth = columnWidth;
    //drawer();
}

void Table::setHeaderHeight(int headerHeight) {
    this->headerHeight = headerHeight;
    drawer();
}

void Table::setBodyHeight(int bodyHeight) {
    this->bodyHeight = bodyHeight;
    drawer();
}

void Table::setPaddingRow(int paddingRow) {
    this->paddingRow = paddingRow;
    drawer();
}

void Table::setPaddingColumn(int paddingColumn) {
    this->paddingColumn = paddingColumn;
    drawer();
}

void Table::setHeadFont(sf::Font headFont) {
    this->headFont = headFont;
    drawer();
}

void Table::setHeadFontSize(int headFontSize) {
    this->headFontSize = headFontSize;
    drawer();
}

void Table::setHeadFontColor(sf::Color headFontColor) {
    this->headFontColor = headFontColor;
    drawer();
}

void Table::setHeadBgColor(sf::Color headBgColor) {
    this->headBgColor = headBgColor;
    drawer();
}

void Table::setBodyFont(sf::Font bodyFont) {
    this->bodyFont = bodyFont;
    drawer();
}

void Table::setBodyFontSize(int bodyFontSize) {
    this->bodyFontSize = bodyFontSize;
    drawer();
}

void Table::setBodyFontColor(sf::Color bodyFontColor) {
    this->bodyFontColor = bodyFontColor;
    drawer();
}

void Table::setBodyBgColor(sf::Color bodyBgColor) {
    this->bodyBgColor = bodyBgColor;
}

void Table::setOutLineThickness(int outLineThickness) {
    this->outLineThickness = outLineThickness;
    drawer();
}

void Table::setOutLineColor(sf::Color outLineColor) {
    this->outLineColor = outLineColor;
    drawer();
}

void Table::setHeaderPadding(sf::Vector2f headerPadding) {
    this->headerPadding = headerPadding;
    drawer();
}

void Table::setBodyPadding(sf::Vector2f bodyPadding) {
    this->bodyPadding = bodyPadding;
    drawer();
}

void Table::setTableLevelPlus() {
    if (tableLevel < ceil((contents.size() - 1) / tableBodyRowNum)) {
        this->tableLevel = (this->tableLevel) + 1;
        drawer();
    }
}

void Table::setTableLevelMinus() {
    if (tableLevel > 0) {
        this->tableLevel = (this->tableLevel) - 1;
        drawer();
    }
}

bool Table::isMouseOverUp(sf::RenderWindow &window) {
    return up.isMouseOver(window);
}

bool Table::isMouseOverDown(sf::RenderWindow &window) {
    return down.isMouseOver(window);
}

void Table::drawTo(sf::RenderWindow &window) {
    for (int j = contents[0].size(); j < totalBodyLoop; j++)    //table body drawn first for scrolling purpose
        tableCell[j].drawTo(window);
    for (int i = 0; i < contents[0].size(); i++)    //table head drawen later
        tableCell[i].drawTo(window);
    up.drawTo(window);
    down.drawTo(window);
}