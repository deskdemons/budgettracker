#pragma once
#ifndef TEXTBOXBG_H
#define TEXTBOXBG_H

#include<iostream>
#include<SFML\Graphics.hpp>

class TextBoxBg {
	sf::ConvexShape convex;	//sfml class to define convec shapes
	sf::Vector2f position;	//x,y position given by user
	sf::Vector2f dimension;	//width, height given by user
	int radius;	//radius of curvature of corners of the shape
	sf::Color bgColor;	//background color of the shape
	int outLineThickness;	//border thickness of the shape
	sf::Color outLineColor; //border color of the shape

public:
	TextBoxBg();
	TextBoxBg(sf::Vector2f position, sf::Vector2f dimension, int radius, sf::Color bgColor, int borderThickness, sf::Color borderColor);//position, dimension, radius, fillColor, outLineThickness, outLineColor 
	void drawer();	//this function has the code that actually draws the shape
	void setPosition(sf::Vector2f);	//sets position of the shape
	void setDimension(sf::Vector2f);	//width,height vector for the shape
	void setRadius(int);	// radius of curvature of cornors of shape
	void setBgColor(sf::Color);	//background color of shape
	void setOutLineThickness(int);	//border thickness
	void setOutLineColor(sf::Color);	//border color

	void drawBg(sf::RenderWindow&);	//renders shape . example: shape1.drawBg(window);
};

#endif