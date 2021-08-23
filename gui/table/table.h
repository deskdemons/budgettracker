#pragma once
#ifndef TABLE_H
#define TABLE_H
#include<SFML/Graphics.hpp>
#include<vector>
#include "../banner/banner.h"
#include "../button/button.h"

class Table {
    std::vector<std::vector<std::string> > contents;	//Row<Column<elements> > , where elements is string and length of column of all row has to be same(obviously)

    int totalCell;	//total number of cell of table. it is calculated by row.length * col. length
    sf::Vector2f position;	//position of table . ex: sf::Vector2f(100,100)
    std::vector<int> columnWidth;	// vector of column width. ex:  std::vector<int>  colWid = {200, 100, 150};   where those ints are width in pixels. length of this vector should be equal to no. of columns
    int headerHeight;	// height of header of table
    int bodyHeight;		// heighth of body of table
    int paddingRow;		// padding between each row of table
    int paddingColumn;	// padding between each column of table
    int tableLevel;		// used internally. default value = 0; for zero, row will start from index 1,2,3,4.  Level 2 might start from 5,6,7,8. used for scrolling purpose
    int tableBodyRowNum;	//how many rows should be seen at once. Recommended not to exceed the actual no. of rows provided in contents
    int totalBodyLoop;	//used internally to should visible rows
    int buttonPosx;		//position x for both button(x and y) is same
    int buttonPosy;		// position y of up button is same as position of table. so, this buttonPosy is used for position y of down button
    //radius = 0		//table radius is always zero.

    sf::Font headFont;	//table Header font
    int headFontSize;	//table header font size
    sf::Color headFontColor;	//table header font color
    sf::Color headBgColor;		//table header bg color
    sf::Vector2f headerPadding;	//table header padding . ex: sf::Vector2f(10,0); for left, top

    sf::Font bodyFont;	//table body font
    int bodyFontSize;	//table body font size
    sf::Color bodyFontColor;	//table body font color
    sf::Color bodyBgColor;	//table body bg color
    sf::Vector2f bodyPadding;	//table body padding

    int outLineThickness;	//table border thicness. It can be made 0
    sf::Color outLineColor;	//table border color

    Banner *tableCell;	//dynamic initialization  of no. of cells in table
    Button up;	//up scroll button
    Button down;	//down scroll button
public:
    Table();
    void setContents(std::vector<std::vector<std::string> > contents);	//setter for contents of table. actual contents should be string
    void setPosition(sf::Vector2f position);	//setter for position of table top left corner
    void setTableBodyRowNum(int tableBodyRowNum);	//setter for no. of visible rows of table at a time
    void setColumnWidth(std::vector<int> columnWidth);	//setter for column width of table
    void setHeaderHeight(int headerHeight);	// setter for header row height of table
    void setBodyHeight(int bodyHeight);	//setter for each body rows height of table
    void setPaddingRow(int paddingRow);	//padding between rows of table
    void setPaddingColumn(int paddingColumn);	//padding between column of table
    void setHeadFont(sf::Font headFont);
    void setHeadFontSize(int headFontSize);
    void setHeadFontColor(sf::Color headFontColor);
    void setHeadBgColor(sf::Color headBgColor);
    void setBodyFont(sf::Font bodyFont);
    void setBodyFontSize(int bodyFontSize);
    void setBodyFontColor(sf::Color bodyFontColor);
    void setBodyBgColor(sf::Color bodyBgColor);
    void setOutLineThickness(int outLineThickness);	//border thickness of table
    void setOutLineColor(sf::Color outLineColor);	//border color of table
    void setHeaderPadding(sf::Vector2f headerPadding);	//padding for text inside header row. ex: sf::Vector2f(10,0); for left, top
    void setBodyPadding(sf::Vector2f bodyPadding);	//paddingfor text inside body rows
    void setTableLevelPlus();	// use when table is needed to scroll down
    void setTableLevelMinus();	// use when table is needed to scroll up

    bool isMouseOverUp(sf::RenderWindow &window);	//return true if mouse is over up scroll button
    bool isMouseOverDown(sf::RenderWindow &window); //return true if mouse is over down scroll button

    void drawer();	//contains logic drawing table artifacts
    void drawTo(sf::RenderWindow &window);	//draws this table object to buffer
};

#endif // !TABLE_H
