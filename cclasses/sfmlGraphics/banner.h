#pragma once
#ifndef BANNER_H
#define BANNER_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "RoundedRectangle.h"

class Banner {
protected:
	RoundedRectangle bannerBg; //manually defined background shape 
	sf::Text text;	//sfml text class

	std::string bannerText;	//actual string of button
	sf::Vector2f position; //x,y coordinate of top left cornor of button
	sf::Vector2f dimension; //width, height of button
	int radius;	//radius of curvature of corners of button
	sf::Font font;	//font family of button text
	int fontSize;	//font size
	sf::Color fontColor; //font color
	sf::Color bgColor;	//background color of button
	int outLineThickness;	//border thickness of button
	sf::Color outLineColor;	//border color of button
	int paddingL;	//text padding from left w.r.t border
	int paddingT;	//text padding from top w.r.t border

public:
	Banner();	//default constructor with default values. you can see in cpp file
	Banner(std::string bannerText, sf::Vector2f position, sf::Vector2f dimension, int radius, sf::Font& font, int fontSize, sf::Color fontColor, sf::Color bgColor, int borderThickness, sf::Color borderColor, int paddingLeft, int paddingRight);//constructor //position, dimension, radius, font, size of txt, txtColor, bgColor, outLineThickness, outLineColor

	//bool isMouseOver(sf::RenderWindow& window);	//is mouse over button

	void setBannerText(std::string);	//setters. example: b1.setButtonText("submit");
	void setPosition(sf::Vector2f);	//x,y vector for position of button
	void setDimension(sf::Vector2f);	//width, height vector for button
	void setRadius(int);	//radius of curvature of cornors of button
	void setFont(sf::Font&);	//font for text of button
	void setFontSize(int);	//font size
	void setFontColor(sf::Color);	//font color
	void setBgColor(sf::Color);	//background color for button
	void setOutLineThickness(int);	//border thickness 
	void setOutLineColor(sf::Color);	//border color
	void setPadding(int, int);	//(left padding, right padding) for text inside button w.r.t border

	void drawTo(sf::RenderWindow&);	// renders button . example: b1.drawTo(window);
};
#endif