#ifndef BUDGETTRACKER_SERVERCONNECTION_H
#define BUDGETTRACKER_SERVERCONNECTION_H

#include "SFML/Network.hpp"
#include "../../cclasses/budget/budget.h"

class ServerConnection {
private:
    int port;
    sf::TcpListener listener;
    sf::TcpSocket socket;

    std::string read_full_budget_file();

    static void file_exist_assert();

public:
    // Default constructor that will just initialize the port, listener and socket values,
    // That's the limit of this constructor
    ServerConnection();

    // Getters and Setters for port variables
    int get_port() const;

    void set_port(int);

    // Starts accepting and responding to connections
    // Server will not listen to any messages before we start run_server
    void run_server();

    void update_current_data(std::vector<Budget> received_data);
};


#endif //BUDGETTRACKER_SERVERCONNECTION_H
