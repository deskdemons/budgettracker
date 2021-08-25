#include "../../cclasses/users/login/login.h"
#include "login_page.h"
#include "../../utility/utility.h"

LoginPage::LoginPage() {    //constructor
    isAuth = false;  //when program first starts, its not logged in, so false
    isWrong = false;
    Util_SignupMode = false;
    drawer();   //drawer is called after object is contructed. obviously, because after construction of object, we need to draw what the page has
}

void LoginPage::eventHandler(sf::Event &event, sf::RenderWindow &window) {
    switch (event.type) {
        case sf::Event::TextEntered:
            if (username.isFocus()) {
                username.typedOn(event);
            } else if (password.isFocus()) {
                password.typedOn(event);
            }
            break;
            case sf::Event::MouseButtonPressed:
                if (signupButton.isMouseOver(window)) {
                    std::cout << "hello world" << std::endl;
                    Util_SignupMode = true;
                }
                if (username.isMouseOver(window)) {
                    username.setSelected(true);
                    password.setSelected(false);
                } else if (password.isMouseOver(window)) {
                    username.setSelected(false);
                    password.setSelected(true);
                } else if (loginButton.isMouseOver(window)) {
                    uname = username.getText();
                    pass = password.getText();
                    if (uname != "" && pass != "") {
                        loginButton.setOutLineThickness(3);
                        loginButton.setOutLineColor(sf::Color::Red);
                        Login l1(uname, pass);
                        isAuth = l1.isGen;
                        isWrong = !l1.isGen;
                        if (l1.isGen) {
                            globalUser = l1.u1;
                            update_global_user_with_latest_data();
                        }
                    }
                } else if (backupButton.isMouseOver(window)) {
                    if (!is_backing_up) {
                        std::cout << "BACKUP LOGIN BTN PRESSED" << std::endl;
                        backup_network_sa();
                    }
                } else if (restoreButton.isMouseOver(window)) {
                    std::cout << "RESTORE LOGIN BTN PRESSED" << std::endl;
                    is_restoring_data = false;
                    restore_network_sa();
                } else {
                    username.setSelected(false);
                    password.setSelected(false);
                }
                break;
    }
}

bool LoginPage::isLoggedIn() {
    return isAuth;
}

void LoginPage::setTextBoxEmpty(){
       username.setMakeTextboxEmpty();
       password.setMakeTextboxEmpty();
       drawer();
}

void LoginPage::drawer() {
    loginPageShowBox.setBgColor(sf::Color::Black);
    loginPageShowBox.setFontColor(sf::Color::White);
    loginPageShowBox.setBannerText("LOGIN PAGE");
    loginPageShowBox.setDimension(sf::Vector2f(200, 60));
    loginPageShowBox.setPadding(40, 0);
    loginPageShowBox.setPosition(sf::Vector2f(540, 50));

    backgroundRect.setDimension(sf::Vector2f(880, 470));
    backgroundRect.setBgColor(sf::Color(234, 234, 234));
    backgroundRect.setOutLineColor(sf::Color(234, 234, 234));
    backgroundRect.setRadius(20);
    backgroundRect.setPosition(sf::Vector2f(200, 150));
    backgroundRect.drawer();

    username.setPosition(sf::Vector2f(450, 280));
    username.setHintText("username");
    username.setBgColor(sf::Color::White);

    password.setPosition(sf::Vector2f(450, 365));
    password.setHintText("password");
    password.setDataType("secure");
    password.setBgColor(sf::Color::White);

    loginButton.setPosition(sf::Vector2f(565, 440));
    loginButton.setDimension(sf::Vector2f(150, 50));
    loginButton.setBgColor(sf::Color::White);
    loginButton.setPadding(50, 0);
    loginButton.setButtonText("Login");

    signupButton.setPosition(sf::Vector2f(1100, 50));
    signupButton.setDimension(sf::Vector2f(150, 40));
    signupButton.setOutLineColor(sf::Color::Red);
    signupButton.setBgColor(sf::Color::Red);
    signupButton.setRadius(10);
    signupButton.setPadding(45, 0);
    signupButton.setFontColor(sf::Color::White);
    signupButton.setButtonText("Signup");

    wrongCredentials.setBannerText("Username or Password was wrong! Please Try Again");
    wrongCredentials.setBgColor(sf::Color::Red);
    wrongCredentials.setFontColor(sf::Color::White);
    wrongCredentials.setDimension(sf::Vector2f(500, 40));
    wrongCredentials.setPadding(12, 0);
    wrongCredentials.setOutLineColor(sf::Color::Red);
    wrongCredentials.setPosition(sf::Vector2f(400, 550));

    backupButton.setPosition(sf::Vector2f(900, 650));
    backupButton.setDimension(sf::Vector2f(150, 30));
    backupButton.setOutLineColor(sf::Color::Red);
    backupButton.setBgColor(sf::Color::Red);
    backupButton.setPadding(40, 0);
    backupButton.setRadius(10);
    backupButton.setFontColor(sf::Color::White);
    backupButton.setButtonText("Backup");
    backupButton.setFontSize(20);

    restoreButton.setPosition(sf::Vector2f(1100, 650));
    restoreButton.setOutLineColor(sf::Color::Red);
    restoreButton.setDimension(sf::Vector2f(150, 30));
    restoreButton.setBgColor(sf::Color::Red);
    restoreButton.setPadding(40, 0);
    restoreButton.setRadius(10);
    restoreButton.setFontColor(sf::Color::White);
    restoreButton.setButtonText("Restore");
}

void LoginPage::setIsAuth(bool isAuthVal){
    this->isAuth = isAuthVal;
}

void LoginPage::drawTo(sf::RenderWindow &window){


    loginPageShowBox.drawTo(window);
    backgroundRect.drawBg(window);
    username.drawTo(window);
    password.drawTo(window);
    loginButton.drawTo(window);

    if (is_backing_up) {
        backupButton.setButtonText("Backed Up!");
        backupButton.setPadding(22, 0);
    }

    backupButton.drawTo(window);
    signupButton.drawTo(window);

    if (is_restoring_data) {
        restoreButton.setButtonText("Restored!");
        restoreButton.setPadding(22, 0);
    }
    restoreButton.drawTo(window);
    if (isWrong == true) {
        wrongCredentials.drawTo(window);
    }
}