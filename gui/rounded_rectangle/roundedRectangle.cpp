#include<iostream>
#include "roundedRectangle.h"
#include<cmath>

#define PI 3.14159265

RoundedRectangle::RoundedRectangle() { //default constructor
    position = sf::Vector2f(50, 50);
    dimension = sf::Vector2f(400, 50);
    radius = 5;
    bgColor = sf::Color(180, 180, 180);
    outLineThickness = 1;
    outLineColor = sf::Color(75, 75, 75);
    drawer();
}

RoundedRectangle::RoundedRectangle(sf::Vector2f position, sf::Vector2f dimension, int radius, sf::Color bgColor,
                                   int outLineThickness, sf::Color outLineColor) {
    this->position = position;
    this->dimension = dimension;
    this->radius = radius;
    this->bgColor = bgColor;
    this->outLineThickness = outLineThickness;
    this->outLineColor = outLineColor;
    drawer();
}

void RoundedRectangle::drawer() {
    float unitDegree = PI / 180;
    convex.setPointCount(364);
    convex.setFillColor(bgColor);
    convex.setOutlineThickness(-outLineThickness);
    convex.setOutlineColor(outLineColor);

    convex.setPoint(0, sf::Vector2f(position.x + radius, position.y));
    for (int i = 1; i < 90; i++) {
        convex.setPoint(i, sf::Vector2f(position.x + radius - (radius * sin(i * unitDegree)),
                                        position.y + radius - (radius * cos(i * unitDegree))));
    }
    convex.setPoint(90, sf::Vector2f(position.x, position.y + radius));
    convex.setPoint(91, sf::Vector2f(position.x, position.y + dimension.y - radius));

    for (int j = 92; j < 181; j++) {
        convex.setPoint(j, sf::Vector2f(position.x + radius - (radius * sin((j - 1) * unitDegree)),
                                        position.y + dimension.y - radius - (radius * cos((j - 1) * unitDegree))));
    }

    convex.setPoint(181, sf::Vector2f(position.x + radius, dimension.y + position.y));
    convex.setPoint(182, sf::Vector2f(position.x + dimension.x - radius, dimension.y + position.y));

    for (int k = 183; k < 272; k++) {

        convex.setPoint(k, sf::Vector2f(position.x + dimension.x - radius - (radius * sin((k - 2) * unitDegree)),
                                        dimension.y + position.y - radius - (radius * cos((k - 2) * unitDegree))));
    }
    convex.setPoint(272, sf::Vector2f(position.x + dimension.x, position.y + dimension.y - radius));
    convex.setPoint(273, sf::Vector2f(position.x + dimension.x, position.y + radius));

    for (int l = 274; l < 363; l++) {

        convex.setPoint(l, sf::Vector2f(position.x + dimension.x - radius - (radius * sin((l - 3) * unitDegree)),
                                        position.y + radius - (radius * cos((l - 3) * unitDegree))));
    }
    convex.setPoint(363, sf::Vector2f(dimension.x + position.x - radius, position.y));
}


void RoundedRectangle::setPosition(sf::Vector2f position) {
    this->position = position;
    drawer();
}

void RoundedRectangle::setDimension(sf::Vector2f dimension) {
    this->dimension = dimension;
    drawer();
}

void RoundedRectangle::setRadius(int radius) {
    this->radius = radius;
    drawer();
}

void RoundedRectangle::setBgColor(sf::Color bgColor) {
    this->bgColor = bgColor;
    drawer();
}

void RoundedRectangle::setOutLineThickness(int outLineThickness) {
    this->outLineThickness = outLineThickness;
    drawer();
}

void RoundedRectangle::setOutLineColor(sf::Color outLineColor) {
    this->outLineColor = outLineColor;
    drawer();
}


void RoundedRectangle::drawBg(sf::RenderWindow &window) {
    window.draw(convex);
}