#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "roundedRectangle.h"
#include "banner.h"

class Button : public Banner{	//inherited from banner class. button and banner are almost similar except for which button is clickable
											
public:
	//since, it is inherited from banner, so all the setters of banner can be used for button
	void setButtonText(std::string);
	bool isMouseOver(sf::RenderWindow& window);	//is mouse over button

};
#endif