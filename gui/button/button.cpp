#include "button.h"


void Button::setButtonText(std::string buttonText) {
	setBannerText(buttonText);
}

bool Button::isMouseOver(sf::RenderWindow& window) {
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	int txtPosX = position.x;
	int txtPosY = position.y;

	int txtxPosWidth = position.x + dimension.x;
	int txtyPosHeight = position.y + dimension.y;

	if (mouseX < txtxPosWidth && mouseX > txtPosX && mouseY < txtyPosHeight && mouseY > txtPosY) {
		return true;
	}
	return false;
}


