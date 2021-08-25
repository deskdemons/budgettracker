#ifndef SFMLSIKDAI_TOPBAR_H
#define SFMLSIKDAI_TOPBAR_H

#include "../banner/banner.h"

class Topbar {
private:

public:
    Banner b1, b2;
    std::string uname;
    std::string viewName;
    sf::CircleShape userShape; //circle shape for user profile
    sf::Texture userPic; //user profile default photo texture

    void setViewText(std::string viewText); // views text like DashBoard,
    void setUsername(std::string userName);

    void drawer();

    Topbar();// constructor which makes all the topBar when object is made
    void drawTo(sf::RenderWindow &); // to Render in the window
};


#endif //SFMLSIKDAI_TOPBAR_H
