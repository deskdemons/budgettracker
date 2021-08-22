#ifndef BUDGETTRACKER_CLIENTCONNECTION_H
#define BUDGETTRACKER_CLIENTCONNECTION_H

#include "SFML/Network.hpp"
#include "../../cclasses/budget/budget.h"

class ClientConnection {
private:
    sf::IpAddress ip;
    int port;
    sf::TcpSocket socket;
    char buffer_chars[10000];
    std::size_t received;
    static void file_exist_assert();
public:
    ClientConnection();

    std::vector<Budget> get_from_server();
    void update_with_data_from_server();
    void send_to_server(std::vector<Budget>);
};


#endif //BUDGETTRACKER_CLIENTCONNECTION_H
