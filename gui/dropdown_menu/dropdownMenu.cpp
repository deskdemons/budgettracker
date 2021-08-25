#include"dropdownMenu.h"

DropdownMenu::DropdownMenu() {
    std::vector<std::string> list;
    list.push_back("item 1");
    list.push_back("item 2");
    list.push_back("item 3");
    list.push_back("item 4");

    hintText = "Shadow Txt";
    hintTextFontSize = 20;
    hintTextFontColor = sf::Color(200, 200, 200);
    hintTextPadding = sf::Vector2f(10, 0);

    dropList = list;
    chosenText = "";
    chosenItemIndex = 0;
    position = sf::Vector2f(100, 500);
    dimension = sf::Vector2f(200, 35);
    dropItemDimension = sf::Vector2f(200, 30);
    dropItemBgColor = sf::Color(240, 240, 240);
    radius = 0;
    font.loadFromFile("arial.ttf");
    fontSize = 20;
    bgColor = sf::Color::White;
    outLineThickness = 1;
    outLineColor = sf::Color::Black;
    padding = sf::Vector2f(5, 0);

    toggleDropDimension = sf::Vector2f(35, 35);
    toggleDropRadius = 0;
    toggleDropFont.loadFromFile("arial.ttf");
    toggleDropFontSize = 20;
    toggleDropFontColor = sf::Color::Black;
    toggleDropBgColor = sf::Color(100, 100, 100);
    toggleDropOutLineThickness = 1;
    toggleDropOutLineColor = sf::Color::Black;
    toggleDropPadding = sf::Vector2f(12, 0);

    isOpen = false;

    dropButton = new Button[list.size()];

    drawer();
}


void DropdownMenu::drawer() {
    chosenItem.setBannerText(chosenText);
    chosenItem.setPosition(position);
    chosenItem.setDimension(dimension);
    chosenItem.setRadius(radius);
    chosenItem.setFont(font);
    chosenItem.setFontSize(fontSize);
    chosenItem.setFontColor(fontColor);
    chosenItem.setBgColor(bgColor);
    chosenItem.setOutLineThickness(outLineThickness);
    chosenItem.setOutLineColor(outLineColor);
    chosenItem.setPadding(padding.x, padding.y);
    if (chosenText == "") {
        hint.setString(hintText);
        hint.setPosition(sf::Vector2f(position.x + hintTextPadding.x,
                                      hintTextPadding.y + position.y + ((dimension.y) / 2) -
                                      (hintTextFontSize / 1.5f)));
        hint.setFillColor(hintTextFontColor);
        hint.setFont(font);
        hint.setCharacterSize(hintTextFontSize);
    }

    toggleDrop.setPosition(sf::Vector2f(position.x + dimension.x, position.y));
    toggleDrop.setBannerText("v");
    toggleDrop.setDimension(sf::Vector2f(toggleDropDimension));
    toggleDrop.setRadius(toggleDropRadius);
    toggleDrop.setFont(toggleDropFont);
    toggleDrop.setFontSize(toggleDropFontSize);
    toggleDrop.setFontColor(toggleDropFontColor);
    toggleDrop.setBgColor(toggleDropBgColor);
    toggleDrop.setOutLineThickness(toggleDropOutLineThickness);
    toggleDrop.setOutLineColor(toggleDropOutLineColor);
    toggleDrop.setPadding(toggleDropPadding.x, toggleDropPadding.y);

    if (isOpen) {
        int posy = 0;
        for (int i = 0; i < dropList.size(); i++) {
            posy = dropItemDimension.y * i;

            dropButton[i].setBannerText(dropList[i]);
            dropButton[i].setPosition(sf::Vector2f(position.x, position.y + dimension.y + posy));
            dropButton[i].setDimension(dropItemDimension);
            dropButton[i].setRadius(0);
            dropButton[i].setFont(font);
            dropButton[i].setFontColor(fontColor);
            dropButton[i].setFontSize(fontSize);
            dropButton[i].setBgColor(dropItemBgColor);
            dropButton[i].setOutLineThickness(outLineThickness);
            dropButton[i].setOutLineColor(outLineColor);
            dropButton[i].setPadding(padding.x, padding.y);
        }
    }

}

void DropdownMenu::setDropMenuList(std::vector<std::string> dropList) {
    this->dropList = dropList;
    dropButton = new Button[dropList.size()];
}

void DropdownMenu::setPosition(sf::Vector2f position) {
    this->position = position;
}

void DropdownMenu::setDimension(sf::Vector2f dimension) {
    this->dimension = dimension;
}

void DropdownMenu::setRadius(int radius) {
    this->radius = radius;
}

void DropdownMenu::setFont(sf::Font font) {
    this->font = font;
}

void DropdownMenu::setFontSize(int fontSize) {
    this->fontSize = fontSize;
}

void DropdownMenu::setFontColor(sf::Color fontColor) {
    this->fontColor = fontColor;
}

void DropdownMenu::setBgColor(sf::Color bgColor) {
    this->bgColor = bgColor;
}

void DropdownMenu::setOutLineThickness(int outLineThickness) {
    this->outLineThickness = outLineThickness;
}

void DropdownMenu::setOutLineColor(sf::Color outLineColor) {
    this->outLineColor = outLineColor;
}

void DropdownMenu::setPadding(sf::Vector2f padding) {
    this->padding = padding;
}

void DropdownMenu::setDropItemDimension(sf::Vector2f dropItemDimension) {
    this->dropItemDimension = dropItemDimension;
}

void DropdownMenu::setDropItemBgColor(sf::Color dropItemBgColor) {
    this->dropItemBgColor = dropItemBgColor;
}

void DropdownMenu::setHintText(std::string hintText) {
    this->hintText = hintText;
}

void DropdownMenu::setHintTextFontSize(int hintTextFontSize) {
    this->hintTextFontSize = hintTextFontSize;
}

void DropdownMenu::setHintTextFontColor(sf::Color hintTextFontColor) {
    this->hintTextFontColor = hintTextFontColor;
}

void DropdownMenu::setHintTextPadding(sf::Vector2f hintTextPadding) {
    this->hintTextPadding = hintTextPadding;
}

void DropdownMenu::setToggleDropDimension(sf::Vector2f toggleDropDimension) {
    this->toggleDropDimension = toggleDropDimension;
}

void DropdownMenu::setToggleDropRadius(int toggleDropRadius) {
    this->toggleDropRadius = toggleDropRadius;
}

void DropdownMenu::setToggleDropFont(sf::Font toggleDropFont) {
    this->toggleDropFont = toggleDropFont;
}

void DropdownMenu::setToggleDropFontSize(int toggleDropFontSize) {
    this->toggleDropFontSize = toggleDropFontSize;
}

void DropdownMenu::setToggleDropFontColor(sf::Color toggleDropFontColor) {
    this->toggleDropFontColor = toggleDropFontColor;
}

void DropdownMenu::setToggleDropBgColor(sf::Color toggleDropBgColor) {
    this->toggleDropBgColor = toggleDropBgColor;
}

void DropdownMenu::setToggleDropOutLineThickness(int toggleDropOutLineThickness) {
    this->toggleDropOutLineThickness = toggleDropOutLineThickness;
}

void DropdownMenu::setToggleDropOutLineColor(sf::Color toggleDropOutLineColor) {
    this->toggleDropOutLineColor = toggleDropOutLineColor;
}

void DropdownMenu::setToggleDropPadding(sf::Vector2f toggleDropPadding) {
    this->toggleDropPadding = toggleDropPadding;
}


bool DropdownMenu::isMouseOverToggle(sf::RenderWindow &window) {
    return toggleDrop.isMouseOver(window);
}

void DropdownMenu::toggleDropDown() {
    if (isOpen)
        isOpen = false;
    else
        isOpen = true;
    drawer();
}

bool DropdownMenu::isMouseOverItem(sf::RenderWindow &window) {
    if (isOpen) {
        for (int i = 0; i < dropList.size(); i++) {
            if (dropButton[i].isMouseOver(window)) {
                chosenItemIndex = i;
                chosenText = dropList[i];
                chosenItem.setBannerText(chosenText);
                toggleDropDown();
                drawer();
                return true;
            }

        }
        return false;
    } else {
        return false;

    }
}

std::string DropdownMenu::getChosenItemTxt() {
    return chosenText;
}


void DropdownMenu::drawTo(sf::RenderWindow &window) {
    chosenItem.drawTo(window);
    toggleDrop.drawTo(window);
    if (isOpen) {
        for (int i = 0; i < dropList.size(); i++)
            dropButton[i].drawTo(window);
    }
    if (chosenText == "")
        window.draw(hint);
}