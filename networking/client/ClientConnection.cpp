#include "ClientConnection.h"
#include <iostream>
#include <fstream>


ClientConnection::ClientConnection() : buffer_chars(), received() {
    // We can use the values buffer_chars and received as their default initialized values, hence
    // we don't need to explicitly code this here

    // We are currently getting the local ip address because, both the client and server are running
    // in the same local machine. But to use some external server, we need to change this to the value
    // that we received from the user or default value
    ip = sf::IpAddress("192.168.1.64");
    port = 44444;

    // Socket is connected here in constructor since once constructed the job of the client_connection object
    // is to send and receive data. Hence, we are connecting it here as this is needed in almost every method.
    // So, this is here to reduce redundancy.
    socket.connect(ip, port);
}

std::vector<Budget> ClientConnection::get_from_server() {
    std::vector<Budget> return_value;

    // The text variable is used to hold the string of text that is to be sent to the server.
    // Using a string variable instead of array of chars is more beneficial since, we can more easily
    // use many methods of string class that comes with c++ std lib
    std::string text;

    // Here we use the g [abbr. get] command to ask the server get the data from the server
    text = "g";
    socket.send(text.c_str(), text.length() + 1);
    socket.receive(buffer_chars, sizeof(buffer_chars), received);

    // Once we have received the data
    if (received > 0) {
        bool done = false;
        int position;
        std::string full_string = buffer_chars;

        // This is here since, we don't know how may line we are receiving
        // hence, we are calculating such that once there are no more remaining "\n"
        // in the continuous string we received, it is the last csv line
        while (!done) {
            position = full_string.find("\n");

            if (position == -1) {
                done = true;
                continue;
            }

            std::string temp = full_string.substr(0, position);
            Budget temp_bud(temp);
            return_value.push_back(temp_bud);
            full_string = full_string.substr(position + 1, full_string.size() - 1);
        }

        // This is for the last line, since are close the loop once no "\n" are found in the code
        if (full_string != "connected") {
            Budget temp_bud(full_string);
            return_value.push_back(temp_bud);
        }
    }
    return return_value;
}


void ClientConnection::send_to_server(std::vector<Budget> send_value) {
    std::string sending_string;
    std::string text;
    // Initially we will be sending 'b' to server to dictate to server that we are trying to
    // perform a backup action, hence this text is needed
    text = "b";

    // We are sending data and receiving them in arrays or chars or string, hence to maintain that we
    // need to change the vector object that we received in the parameter to a continuous string object
    for (int i = 0; i < send_value.size(); i++) {
        sending_string += send_value[i].serialize();

        // We don't need an extra \n at the end of the message since it will just create an empty blank line
        // at the end, which when deserialized may observe unexpected phenomenon
        if (i < send_value.size()) {
            sending_string += "\n";
        }
    }

    // First we need to notify the server that we are sending backup data
    // Hence we will send b from client to server
    socket.send(text.c_str(), text.length() + 1);
    socket.receive(buffer_chars, sizeof(buffer_chars), received);

    // Once the data is received by the server, recognizing that the client has asked to back up
    // client data to the server, it should send a 'c' character

    // We are going to use the optimistic approach here, since the software is written such that the server
    // won't send anything other than 'c' we can just ignore whatever is being received once received.
    // Since the main motive is to inform that we are doing a backup, which has been achieved by sending 'b' and
    // It has been confirmed as we received one or more bit from the server
    if (received > 0) {
        text = sending_string;
        socket.send(text.c_str(), text.length() + 1);

        // This is for confirmation purpose,
        // We need to confirm that the server has received the data, hence we have this here.
        socket.receive(buffer_chars, sizeof(buffer_chars), received);

        // Once the server has processed the data that we send from client, we receive 1 back from server as string
        // hence checking if the data received back from the server is valid or not!
        if (received > 0 && buffer_chars[0] != 1) {
            throw ("Networking Error, invalid confirmation form server received!");
        }
    }

}

void ClientConnection::update_with_data_from_server() {
    std::vector<Budget> received_data;
    received_data = get_from_server();

    file_exist_assert();
    int removed_status = std::remove("budget.csv");
    if (removed_status == 1) {
        throw ("Old file could not be removed");
    }
    // write the initial line
    file_exist_assert();

    const char *fname = "budget.csv";
    std::ofstream fout(fname);

    // loop through the vector and add it to the file
    Budget empty_budget_object;
    int i;
    fout << "pk,user_id,title,category,datetime,currency" << std::endl;
    for (i = 0; i < received_data.size() - 1; i++) {
        try {
            fout << received_data[i].serialize(received_data[i].get_user_id()) << std::endl;
        } catch (std::string errorr) {
            std::cout << "Garbage value obtained for serialization" << errorr << std::endl;
        }
    }
    // The "fout" below doesn't have "std::endl" at end so as not to have an empty line at end of csv file
    // If empty line is present, it will create a budget object with empty values,
    // Such that when we append a line, it writes one new empty budget object every time.
    try {
        fout << received_data[i].serialize(received_data[i].get_user_id());
    } catch (std::string errorr) {
        std::cout << "Garbage value obtained for serialization" << errorr << std::endl;
    }
    fout.close();


}

void ClientConnection::file_exist_assert() {
    const char *fname = "budget.csv";

    std::fstream fs;
    fs.open(fname, std::ios::in);

    if (!fs) {
        // File doesnot exist
        //Create a file
        std::ofstream fout(fname);
        if (fout) {
            // If the creation is successful
            fout << "pk,user_id,title,category,datetime,currency";

            // Close the file handle after performing the operation
            fout.close();
        } else {
            std::cout << "File creation clientconnection.cpp creation unsucessful" << std::endl;
        }
    } else {
        std::cout << "File exist after deletion" << std::endl;
    }

}
