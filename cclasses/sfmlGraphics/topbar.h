//
// Created by paudelrajeev58 on 8/21/21.
//

#ifndef SFMLSIKDAI_TOPBAR_H
#define SFMLSIKDAI_TOPBAR_H
#include "banner.h"

class Topbar{
private:

public:
    Banner b1,b2;
    std::string username;
    std::string viewName;
    sf::CircleShape userShape; //circle shape for user profile
    sf::Texture userPic; //user profile default photo texture
    std::string setViewText(); // views text like DashBoard,
    std::string setUsername();

    Topbar();// constructor which makes all the topBar when object is made
    void drawTo(sf::RenderWindow&); // to Render in the window
};


#endif //SFMLSIKDAI_TOPBAR_H
