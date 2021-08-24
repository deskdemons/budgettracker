#include<iostream>
#include "textbox.h"

Textbox::Textbox() {    //default constructor
    isSelected = false;
    position = sf::Vector2f(50, 50);
    dimension = sf::Vector2f(400, 50);
    radius = 5;
    font.loadFromFile("Roboto-Regular.ttf");
    hintText = "Hint Text";
    hintFont.loadFromFile("arial.ttf");
    hintFontSize = 20;
    hintFontColor = sf::Color(130, 130, 130);
    dataType = "normal";
    fontSize = 20;
    maxLen = 20;
    fontColor = sf::Color::Black;
    bgColor = sf::Color(180, 180, 180);
    outLineThickness = 1;
    outLineColor = sf::Color(75, 75, 75);
    paddingL = 10;
    paddingT = 0;

    hint.setString(hintText);
    hint.setPosition(
            sf::Vector2f(position.x + paddingL, paddingT + position.y + ((dimension.y) / 2) - (hintFontSize / 1.5f)));
    hint.setFont(hintFont);
    hint.setCharacterSize(hintFontSize);
    hint.setFillColor(hintFontColor);

    textbox.setPosition(
            sf::Vector2f(position.x + paddingL, paddingT + position.y + ((dimension.y) / 2) - (fontSize / 1.5f)));
    textbox.setFont(font);
    textbox.setCharacterSize(fontSize);
    textbox.setFillColor(fontColor);
    txtbg = RoundedRectangle();

}

Textbox::Textbox(sf::Vector2f position, sf::Vector2f dimension, int radius, std::string hintText, sf::Font &hintFont,
                 int hintFontSize, sf::Color hintFontColor, std::string datatype, sf::Font &font, int fontSize,
                 int maxLen, sf::Color fontColor, sf::Color bgColor, int outLineThickness, sf::Color outLineColor,
                 int paddingL, int paddingT) {
    isSelected = false;
    this->position = position;
    this->dimension = dimension;
    this->radius = radius;
    this->hintText = hintText;
    this->hintFont = hintFont;
    this->hintFontSize = hintFontSize;
    this->hintFontColor = hintFontColor;
    this->dataType = dataType;
    this->font = font;
    this->fontSize = fontSize;
    this->maxLen = maxLen;
    this->fontColor = fontColor;
    this->bgColor = bgColor;
    this->outLineThickness = outLineThickness;
    this->outLineColor = outLineColor;
    this->paddingL = paddingL;
    this->paddingT = paddingT;

    hint.setString(hintText);
    hint.setPosition(
            sf::Vector2f(position.x + paddingL, paddingT + position.y + ((dimension.y) / 2) - (hintFontSize / 1.5f)));
    hint.setFont(hintFont);
    hint.setCharacterSize(hintFontSize);
    hint.setFillColor(hintFontColor);

    textbox.setPosition(
            sf::Vector2f(position.x + paddingL, paddingT + position.y + ((dimension.y) / 2) - (fontSize / 1.5f)));
    textbox.setFont(font);
    textbox.setCharacterSize(fontSize);
    textbox.setFillColor(fontColor);
    txtbg = RoundedRectangle(position, dimension, radius, bgColor, outLineThickness,
                             outLineColor); // RoundedRectangle txtbg = RoundedRectangle(position, dimension, radius); removing RoundedRectangle solve the problem

}

void Textbox::setSelected(bool sel) {
    isSelected = sel;

    // If not selected, remove the '_' at the end:
    if (!sel) {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length(); i++) {
            newT += t[i];
        }
        if (dataType == "normal")
            textbox.setString(newT);
        else
            textbox.setString(secureText.str());
    }
}

bool Textbox::isFocus() {
    return isSelected;
}

void Textbox::typedOn(sf::Event input) {
    if (isSelected) {
        int charTyped = input.text.unicode;

        // Only allow normal inputs:
        if (charTyped < 128) {
            // If there's a limit, don't go over it:
            if (text.str().length() <= maxLen) {
                inputLogic(charTyped);
            }
                // But allow for char deletions:
            else if (text.str().length() > maxLen && charTyped == BACKSPACE_KEY) {
                deleteLastChar();
            }

        }
    }
}

void Textbox::deleteLastChar() {
    std::string t = text.str();
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++) {
        newT += t[i];
    }
    text.str("");
    text << newT;
    displayLogic(text.str());
}

void Textbox::displayLogic(std::string disStr) {
    if (dataType == "normal")
        textbox.setString(text.str() + "_");
    else {
        secureText.str("");
        for (int c = 0; c < disStr.length(); c++) {
            secureText << static_cast<char>(42);
        }

        textbox.setString(secureText.str() + "_");
    }

}

void Textbox::inputLogic(int charTyped) {
    // If the key pressed isn't delete, or the two selection keys, then append the text with the char:
    if (charTyped != BACKSPACE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
        text << static_cast<char>(charTyped);
    }
        // If the key is delete, then delete the char:
    else if (charTyped == BACKSPACE_KEY) {
        if (text.str().length() > 0) {
            deleteLastChar();
        }
    }
    // Set the t_amount_text_box text:
    displayLogic(text.str());
}

bool Textbox::isMouseOver(sf::RenderWindow &window) {
    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;

    int txtPosX = position.x;
    int txtPosY = position.y;

    int txtxPosWidth = position.x + dimension.x;
    int txtyPosHeight = position.y + dimension.y;

    if (mouseX < txtxPosWidth && mouseX > txtPosX && mouseY < txtyPosHeight && mouseY > txtPosY) {
        displayLogic(text.str());
        return true;
    }
    return false;
}

std::string Textbox::getText() {
    return text.str();
}


void Textbox::setPosition(sf::Vector2f position) {
    this->position = position;
    textbox.setPosition(
            sf::Vector2f(position.x + paddingL, paddingT + position.y + ((dimension.y) / 2) - (fontSize / 1.5f)));
    hint.setPosition(
            sf::Vector2f(position.x + paddingL, paddingT + position.y + ((dimension.y) / 2) - (hintFontSize / 1.5f)));
    txtbg.setPosition(position);
}

void Textbox::setDimension(sf::Vector2f dimension) {
    this->dimension = dimension;
    txtbg.setDimension(dimension);    //dimension only used for RoundedRectangle .
}

void Textbox::setRadius(int radius) {
    this->radius = radius;
    txtbg.setRadius(radius);
}

void Textbox::setHintText(std::string hintText) {
    this->hintText = hintText;
    hint.setString(hintText);
}

void Textbox::setHintFont(sf::Font &hintFont) {
    this->hintFont = hintFont;
    hint.setFont(hintFont);
}

void Textbox::setHintFontSize(int hintFontSize) {
    this->hintFontSize = hintFontSize;
    hint.setCharacterSize(hintFontSize);
}

void Textbox::setHintFontColor(sf::Color hintFontColor) {
    this->hintFontColor = hintFontColor;
    hint.setFillColor(hintFontColor);
}

void Textbox::setDataType(std::string dataType) {
    this->dataType = dataType;
}

void Textbox::setFont(sf::Font &font) {
    this->font = font;
    textbox.setFont(font);
}

void Textbox::setFontSize(int fontSize) {
    this->fontSize = fontSize;
    textbox.setCharacterSize(fontSize);
}

void Textbox::setMaxLen(int maxLen) {
    this->maxLen = maxLen;
}

void Textbox::setFontColor(sf::Color fontColor) {
    this->fontColor = fontColor;
    textbox.setFillColor(fontColor);
}

void Textbox::setBgColor(sf::Color bgColor) {
    this->bgColor = bgColor;
    txtbg.setBgColor(bgColor);
}

void Textbox::setOutLineThickness(int outLineThickness) {
    this->outLineThickness = outLineThickness;
    txtbg.setOutLineThickness(outLineThickness);
}

void Textbox::setOutLineColor(sf::Color outLineColor) {
    this->outLineColor = outLineColor;
    txtbg.setOutLineColor(outLineColor);
}

void Textbox::setPadding(int paddingL, int paddingT) {
    this->paddingL = paddingL;
    this->paddingL = paddingT;
    textbox.setPosition(
            sf::Vector2f(position.x + paddingL, paddingT + position.y + ((dimension.y) / 2) - (fontSize / 1.5f)));
    hint.setPosition(
            sf::Vector2f(position.x + paddingL, paddingT + position.y + ((dimension.y) / 2) - (hintFontSize / 1.5f)));
}

void Textbox::drawTo(sf::RenderWindow &window) {
    txtbg.drawBg(window);
    window.draw(textbox);
    if (textbox.getString() == "") {
        window.draw(hint);
    }

}