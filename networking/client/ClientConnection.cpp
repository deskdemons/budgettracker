#include "ClientConnection.h"
#include <iostream>
ClientConnection::ClientConnection() : buffer_chars(), received() {
    ip = sf::IpAddress::getLocalAddress();
    port = 44444;
    socket.connect(ip, port);
}

std::vector<Budget> ClientConnection::get_from_server() {
    std::vector<Budget> return_value;

    std::string text;
    socket.receive(buffer_chars, sizeof(buffer_chars),received);
    if (received > 0){
        text = "g";
        socket.send(text.c_str(), text.length()+1);
        socket.receive(buffer_chars, sizeof (buffer_chars), received);
        if (received > 0){
            bool done = false;
            int position;
            std::string full_string = buffer_chars;
            while(!done){
                position = full_string.find("\n");

                if (position == -1){
                    done = true;
                    continue;
                }

                std::string temp = full_string.substr(0, position);
                Budget temp_bud(temp);
                return_value.push_back(temp_bud);
                full_string = full_string.substr(position + 1, full_string.size() - 1);
            }
            Budget temp_bud(full_string);
            return_value.push_back(temp_bud);

            return return_value;
        }
    }
}

void ClientConnection::send_to_server(std::string sending_text) {

}
