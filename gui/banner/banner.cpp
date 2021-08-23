#include "banner.h"

Banner::Banner() {
	bannerText = "Enter";
	position =  sf::Vector2f(50,50) ;
	dimension = sf::Vector2f(150, 50);
	radius = 5;
	font.loadFromFile("Roboto-Regular.ttf");
	fontSize = 20;
	fontColor = sf::Color::Black;
	bgColor = sf::Color(0, 204, 0);
	outLineThickness = 1;
	outLineColor = sf::Color(75, 75, 75);
	paddingL = 10;
	paddingT = 0;

	text.setString(bannerText);
	text.setPosition(sf::Vector2f(position.x + paddingL , paddingT + position.y + ((dimension.y) / 2) - (fontSize / 1.5f) ));
	text.setFont(font);
	text.setCharacterSize(fontSize);
	text.setFillColor(fontColor);
	bannerBg = RoundedRectangle(position, dimension, radius, bgColor, outLineThickness, outLineColor);
	bannerBg.drawer();
}
Banner::Banner(std::string bannerText, sf::Vector2f position, sf::Vector2f dimension, int radius, sf::Font& font, int fontSize, sf::Color fontColor, sf::Color bgColor, int outLineThickness, sf::Color outLineColor, int paddingL, int paddingT) {//position, dimension, radius, font, size of txt, txtColor, bgColor, outLineThickness, outLineColor
	this->bannerText = bannerText;
	this->position = position;
	this->dimension = dimension;
	this->radius = radius;
	this->font = font;
	this->fontSize = fontSize;
	this->fontColor = fontColor;
	this->bgColor = bgColor;
	this->outLineThickness = outLineThickness;
	this->outLineColor = outLineColor;
	this->paddingL = paddingL;
	this->paddingT = paddingT;

	text.setString(bannerText);
	text.setPosition(sf::Vector2f( position.x + paddingL, paddingT + position.y + ((dimension.y) / 2) - (fontSize / 1.5f) ));
	text.setFont(font);
	text.setCharacterSize(fontSize);
	text.setFillColor(fontColor);
	bannerBg = RoundedRectangle(position, dimension, radius, bgColor, outLineThickness, outLineColor); // RoundedRectangle txtbg = RoundedRectangle(position, dimension, radius); removing RoundedRectangle solve the problem
	bannerBg.drawer();
}

void Banner::setBannerText(std::string bannerText) {
	this->bannerText = bannerText;
	text.setString(bannerText);
}

void Banner::setPosition(sf::Vector2f position) {
	this->position = position;
	text.setPosition(sf::Vector2f( position.x + paddingL , paddingT + position.y + ((dimension.y) / 2) - (fontSize / 1.5f) )); //yet to make horizontall centered
	bannerBg.setPosition(position);
}
void Banner::setDimension(sf::Vector2f dim) {
	this->dimension = dim;
	bannerBg.setDimension(dim);	//dimension only used for RoundedRectangle .
}
void Banner::setRadius(int radius) {
	this->radius = radius;
	bannerBg.setRadius(radius);
}
void Banner::setFont(sf::Font& font) {
	this->font = font;
	text.setFont(font);
}
void Banner::setFontSize(int fontSize) {
	this->fontSize = fontSize;
	text.setCharacterSize(fontSize);
}
void Banner::setFontColor(sf::Color fontColor) {
	this->fontColor = fontColor;
	text.setFillColor(fontColor);
}
void Banner::setBgColor(sf::Color bgColor) {
	this->bgColor = bgColor;
	bannerBg.setBgColor(bgColor);
}
void Banner::setOutLineThickness(int outLineThickness) {
	this->outLineThickness = outLineThickness;
	bannerBg.setOutLineThickness(outLineThickness);
}
void Banner::setOutLineColor(sf::Color outLineColor) {
	this->outLineColor = outLineColor;
	bannerBg.setOutLineColor(outLineColor);
}
void Banner::setPadding(int paddingL, int paddingT) {
	this->paddingL = paddingL;
	this->paddingT = paddingT;
	text.setPosition(sf::Vector2f(position.x + paddingL , paddingT + position.y + ((dimension.y) / 2) - (fontSize / 1.5f) ));
}

void Banner::drawTo(sf::RenderWindow& window) {
	bannerBg.drawBg(window);
	window.draw(text);
}