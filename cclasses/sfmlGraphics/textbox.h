#pragma once
#ifndef TEXTBOX_H
#define TEXTBOX_H
#include<iostream>
#include<sstream>
#include<SFML/Graphics.hpp>
#include "RoundedRectangle.h"

// Define keys:
#define BACKSPACE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
private:
	sf::Text textbox; //sfml text class 
	bool isSelected;	//at first, given text box isn't selected as it is false. so when we press key, nothing is written
	std::ostringstream text;	//text to store entered value
	std::ostringstream secureText;	//used to show live character press to the screen
	std::string hintText;	//hint text
	

	sf::Vector2f position;	//x,y coordinate of top left cornor of button
	sf::Vector2f dimension; //width, height of button
	int radius;//radius of curvature of corners of button
	sf::Text hint;	//hint text	//you can see deafult values on default constructor of the corresponding cpp file
	sf::Font hintFont;	//hint text font
	int hintFontSize;	//hint text size
	sf::Color hintFontColor;	//hint text color
	std::string dataType;	// pass string "normal" or "secure". secure are for passwords
	sf::Font font; //font family of button text
	int fontSize; //font size
	int maxLen;	//maximum length of text
	sf::Color fontColor;	//font color
	sf::Color bgColor; //background color of button
	int outLineThickness;	//border thickness of button
	sf::Color outLineColor;	//border color of button
	int paddingL;	//text padding from left w.r.t border
	int paddingT;	//text padding from top w.r.t border

	RoundedRectangle txtbg;	////manually defined background shape class

public:
	Textbox();	//default constructor with default values. you can see in cpp file
	Textbox(sf::Vector2f position, sf::Vector2f dimension, int radius, std::string hintText ,sf::Font& hintFont, int hintFontSize, sf::Color hintFontColor,std::string dataType, sf::Font& font, int fontSize, int maxLen, sf::Color fontColor, sf::Color bgColor, int borderThickness, sf::Color borderColor, int paddingLeft, int paddingTop); //this is constructor //position, dimension, radius, font, size of txt, max length of txt, txtColor, bgColor, outLineThickness, outLineColor
	
	void setSelected(bool);	//sets true if given textbox is selected by using mouse click over the textbox
	bool isFocus();	// returns boolean variable "selected"
	void typedOn(sf::Event); // every event is send here and if event is keypress, then it does its internal work as defined
	void deleteLastChar();	//deletes last char when backspace is pressed
	void displayLogic(std::string disStr);	//logic to make secure datatype appear hidden as *
	void inputLogic(int);	//converts ascii into char and injects character stream to string
	bool isMouseOver(sf::RenderWindow& );//bool is mouse is over textbox or not

	std::string getText();	// getter that returns the entered text so far

	void setPosition(sf::Vector2f );	//setters. example: textbox1.setButtonText("submit");
	void setDimension(sf::Vector2f );	//width, height of textbox in vector2f form
	void setRadius(int);	//radius of curvature of cornor of textbox
	void setHintText(std::string hintText);
	void setHintFont(sf::Font&);	//hint text font
	void setHintFontSize(int);	//hint text font size
	void setHintFontColor(sf::Color);	//hint text font Color
	void setDataType(std::string);	// either "normal" or "secure",  default is normal if not mentioned
	void setFont(sf::Font&);	//text font
	void setFontSize(int);	//text font size
	void setMaxLen(int);	//maximum length of characters that can be entered in textbox
	void setFontColor(sf::Color);
	void setBgColor(sf::Color);	//textbox bg color
	void setOutLineThickness(int);	//textbox border thickness
	void setOutLineColor(sf::Color);	//textbox border color
	void setPadding(int, int);	//(left padding, right padding) for text inside button w.r.t border

	void drawTo(sf::RenderWindow&); // renders textbox . example: textbox1.drawTo(window);
};

#endif